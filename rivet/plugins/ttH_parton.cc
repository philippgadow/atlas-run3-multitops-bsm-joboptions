// -*- C++ -*-
// #include "Root/TH1F.h"
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/ZFinder.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/IdentifiedFinalState.hh"
#include "Rivet/Projections/LeadingParticlesFinalState.hh"
#include "Rivet/Projections/UnstableParticles.hh"
#include "Rivet/Projections/HadronicFinalState.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Tools/BinnedHistogram.hh"
#include "Rivet/Projections/ChargedFinalState.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/VisibleFinalState.hh"
#include "Rivet/Tools/RivetMT2.hh"

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/ReaderAscii.h"
// #include "HepMC3/HepMCUtils.h"



namespace Rivet {

  using namespace Cuts;
  bool debug = false;

  bool hasChild(Particle ptcl, int pdgID) { //If the parent particle decay to some child particles
      for (auto child:ptcl.children())
          if (child.pid()==pdgID) return true;
      return false;
  }
  bool hasParent(Particle ptcl, int pdgID) {
      for (auto parent:ptcl.parents())
        if (parent.pid()==pdgID) return true;
      return false;
  }

  Particle getLastInstance(Particle ptcl) {
    if ( ptcl.genParticle()->end_vertex() ) { // check if has end vertex
      if ( !hasChild(ptcl.genParticle(),ptcl.pid()) ) return ptcl;
      else return getLastInstance(ptcl.children()[0]);
    }
    return ptcl;
  }

  void printInfo(ConstGenParticlePtr part){
    std::cout <<"production particle with ID: "<< part->pdg_id()
                << ", status: " <<  part->status()
                << ", barcode: " << part->id()
              <<std::endl;
    std::cout << "pt: " <<  part->momentum().perp()
              << ", eta: " <<  part->momentum().eta()
              << ", phi: " <<  part->momentum().phi()
              <<std::endl;
    std::cout <<"parent number: "<< Particle(part).parents().size()
              << ", children number: " << Particle(part).children().size()
              <<std::endl;
    std::cout << "------------------"<<std::endl;
  }

  void addCand(ConstGenParticlePtr part, std::vector<int> pdgIDs, Particles& candList) {
    if (std::find(pdgIDs.begin(), pdgIDs.end(), fabs(part->pdg_id())) != pdgIDs.end()){
      if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0){
          if (debug){
            printInfo(part);
          }
          candList.push_back(Particle(part));
      }
    }
  } 

  void fillHistKinematics(map<std::string,Histo1DPtr> _h, std::string name_template, Particle ptcl, bool includeMass){
    _h[name_template + "_pT"]->fill(ptcl.pT()/GeV);
    _h[name_template + "_eta"]->fill(ptcl.eta());
    if (includeMass){
      _h[name_template + "_mass"]->fill(ptcl.mass()/GeV);
    }
  }

  class ttH_parton: public Analysis {
  public:

    /// Constructor
    ttH_parton()
      : Analysis("ttH_parton")
    {    }


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {

        declare(FastJets(FinalState(Cuts::abseta < 2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
        declare(MissingMomentum(FinalState(Cuts::abseta < 4 && Cuts::pT >0*GeV)),"MissingET");

        // book(_h["sumOfWeights"],"sumOfWeights",10,0,2);

        book(_h["Inclusive_nTop"],"Inclusive_nTop",5,0.5,5.5);
        book(_h["Inclusive_nH"],"Inclusive_nH",5,0.5,5.5);
        book(_h["Inclusive_nW"],"Inclusive_nW",10,0.5,10.5);
        book(_h["Inclusive_nq"],"Inclusive_nq",24,0.5,24.5);
        book(_h["Inclusive_nlep"],"Inclusive_nlep",10,0.5,10.5);

        book(_h["Inclusive_top0_pT"],"Inclusive_top0_pT",40,0,500);
        book(_h["Inclusive_top1_pT"],"Inclusive_top1_pT",40,0,500)
        book(_h["Inclusive_H_pT"],"Inclusive_H_pT",40,0,500);
        book(_h["Inclusive_q0_pT"],"Inclusive_q0_pT",40,0,500);
        book(_h["Inclusive_q1_pT"],"Inclusive_q1_pT",40,0,500);
        book(_h["Inclusive_l0_pT"],"Inclusive_l0_pT",40,0,500);
        book(_h["Inclusive_l1_pT"],"Inclusive_l1_pT",40,0,500);

        book(_h["Inclusive_top0_eta"],"Inclusive_top0_eta",40,-5.,5.);
        book(_h["Inclusive_top1_eta"],"Inclusive_top1_eta",40,-5.,5.);
        book(_h["Inclusive_H_eta"],"Inclusive_H_eta",40,-5.,5.);
        book(_h["Inclusive_q0_eta"],"Inclusive_q0_eta",40,-5.,5.);
        book(_h["Inclusive_q1_eta"],"Inclusive_q1_eta",40,-5.,5.);
        book(_h["Inclusive_l0_eta"],"Inclusive_l0_eta",40,-5.,5.);
        book(_h["Inclusive_l1_eta"],"Inclusive_l1_eta",40,-5.,5.);

        book(_h["Inclusive_top0_mass"],"Inclusive_top0_mass",40,150,200);
        book(_h["Inclusive_top1_mass"],"Inclusive_top1_mass",40,150,200);
        book(_h["Inclusive_H_mass"],"Inclusive_H_mass",40,100,150);

    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // const double weight = event.weight();

      // MSG_INFO("#----------------Event--------------#");

      //DO PDG analysis
      // vector<const HepMC3::GenParticle*> genParticles = HepMCUtils::particles(event.genEvent());
      // vector<const Particle> genParticles = Rivet::Particles(event.genEvent());
      vector<std::shared_ptr<const HepMC3::GenParticle>> genParticles = HepMCUtils::particles(event.genEvent());

      Particles topCands;
      Particles HCands;
      Particles WCands;
      Particles qCands;
      Particles lepCands;

      for (ConstGenParticlePtr part : HepMCUtils::particles(event.genEvent()))
      {
              //Select Tops
              addCand(part, {6}, topCands);

              //Select Higgs
              addCand(part, {25}, HCands);

              //Select W
              addCand(part, {24}, WCands);

              //Select quarks
              addCand(part, {1,2,3,4,5}, qCands);

              //Select leptons
              addCand(part, {11,13,15}, lepCands);

      }

      topCands = sortByPt(topCands);
      HCands = sortByPt(HCands);
      WCands   = sortByPt(WCands);
      qCands   = sortByPt(qCands);
      lepCands = sortByPt(lepCands);
      
      _h["Inclusive_nTop"]->fill(topCands.size());
      _h["Inclusive_nH"]->fill(HCands.size());
      _h["Inclusive_nW"]->fill(WCands.size());
      _h["Inclusive_nq"]->fill(qCands.size());
      _h["Inclusive_nlep"]->fill(lepCands.size());

      if (topCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_top0", topCands.at(0), true);
          fillHistKinematics(_h, "Inclusive_top1", topCands.at(1), true);
      }

      if (HCands.size()>=1){
          fillHistKinematics(_h, "Inclusive_H", HCands.at(0), true);
      }

      if (qCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_q0", qCands.at(0), false);
          fillHistKinematics(_h, "Inclusive_q1", qCands.at(1), false);
      }

      if (lepCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_l0", lepCands.at(0), false);
          fillHistKinematics(_h, "Inclusive_l1", lepCands.at(1), false);
      }

    }

    /// Normalise histograms etc., after the run
    // void finalize()
    // {
        
    //     // For Powheg
        
    //     MSG_INFO("CROSS SSECTION:"<<crossSection());
    //     auto xsec = isnan(crossSection()) ? 1: crossSection();
    //     MSG_INFO("xsec = "<< xsec);
    //     MSG_INFO("Sum of weights:"<<sumOfWeights());
    //     //const double sf = xsec / sumOfWeights();
    //     _h["sumOfWeights"]->fill(xsec); // histograms are scaled to xs

    //     // For Sherpa/MG
    //     // MSG_INFO("CROSS SSECTION:"<<crossSection());
    //     // MSG_INFO("Sum of weights:"<<sumOfWeights());
    //     // const double sf = crossSection() / sumOfWeights();
    //     // for (auto hist : _h) { scale(hist.second, sf); }

    //     // _h["sumOfWeights"]->fill(1);


    // }
    //@}


  private:

    map<std::string,Histo1DPtr> _h;

  };

  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(ttH_parton);

}
