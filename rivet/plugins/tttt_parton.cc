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

  class tttt_parton: public Analysis {
  public:

    /// Constructor
    tttt_parton()
      : Analysis("tttt_parton")
    {    }


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {

        declare(FastJets(FinalState(Cuts::abseta < 2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
        declare(MissingMomentum(FinalState(Cuts::abseta < 4 && Cuts::pT >0*GeV)),"MissingET");

        book(_h["sumOfWeights"],"sumOfWeights",2,0,2);

        book(_h["Inclusive_nTop"],"Inclusive_nTop",5,0.5,5.5);
        book(_h["Inclusive_nq"],"Inclusive_nq",5,0.5,5.5);
        book(_h["Inclusive_nW"],"Inclusive_nW",5,0.5,5.5);
   
        book(_h["Inclusive_pT_top0"],"Inclusive_pT_top0",40,0,300);
        book(_h["Inclusive_pT_top1"],"Inclusive_pT_top1",40,0,300);
        book(_h["Inclusive_pT_top2"],"Inclusive_pT_top2",40,0,300);
        book(_h["Inclusive_pT_top3"],"Inclusive_pT_top3",40,0,300);
        book(_h["Inclusive_m_top0"],"Inclusive_m_top0",40,150,200);
        book(_h["Inclusive_m_top1"],"Inclusive_m_top1",40,150,200);
        book(_h["Inclusive_m_top2"],"Inclusive_m_top2",40,150,200);
        book(_h["Inclusive_m_top3"],"Inclusive_m_top3",40,150,200);
        book(_h["Inclusive_eta_top0"],"Inclusive_eta_top0",40,-5.,5.);
        book(_h["Inclusive_eta_top1"],"Inclusive_eta_top1",40,-5.,5.);
        book(_h["Inclusive_eta_top2"],"Inclusive_eta_top2",40,-5.,5.);
        book(_h["Inclusive_eta_top3"],"Inclusive_eta_top3",40,-5.,5.);
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
      Particles qCands;
      Particles WCands;

      for (ConstGenParticlePtr part : HepMCUtils::particles(event.genEvent()))
      {
              //Select Tops
              if(fabs(part->pdg_id()) == 6)
              {

                  if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0)
                  {
                      if(debug){
                          std::cout <<"production Top: "<< part->pdg_id()
                                     << ", status: " <<  part->status()
                                     << ", barcode: " << part->id()
                                    <<std::endl;
                          std::cout << "pt: " <<  part->momentum().perp()
                                    << ", eta: " <<  part->momentum().eta()
                                    << ", phi: " <<  part->momentum().phi()
                                   <<std::endl;
                          std::cout <<"Top parent number: "<< Particle(part).parents().size()
                                    << ", children number: " << Particle(part).children().size()
                                   <<std::endl;
                          std::cout << "------------------"<<std::endl;
                      }

                      // append W candidates
                      topCands.push_back(Particle(part));


                  }
              }
              //Select light quark
              if(fabs(part->pdg_id()) == 1 || fabs(part->pdg_id()) == 2 || fabs(part->pdg_id()) == 3 || fabs(part->pdg_id()) == 4 || fabs(part->pdg_id()) == 5)
              {

                  if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0)
                  {
                      if(debug){
                          std::cout <<"production quark: "<< part->pdg_id()
                                     << ", status: " <<  part->status()
                                     << ", barcode: " << part->id()
                                    <<std::endl;
                          std::cout << "pt: " <<  part->momentum().perp()
                                    << ", eta: " <<  part->momentum().eta()
                                    << ", phi: " <<  part->momentum().phi()
                                   <<std::endl;
                          std::cout <<"quark parent number: "<< Particle(part).parents().size()
                                    << ", children number: " << Particle(part).children().size()
                                   <<std::endl;
                          std::cout << "------------------"<<std::endl;
                      }

                      // append W candidates
                      qCands.push_back(Particle(part));


                  }
              }
              //Select W
              if(fabs(part->pdg_id()) == 24)
              {

                  if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0)
                  {
                      if(debug){
                          std::cout <<"production W: "<< part->pdg_id()
                                     << ", status: " <<  part->status()
                                     << ", barcode: " << part->id()
                                    <<std::endl;
                          std::cout << "pt: " <<  part->momentum().perp()
                                    << ", eta: " <<  part->momentum().eta()
                                    << ", phi: " <<  part->momentum().phi()
                                   <<std::endl;
                          std::cout <<"W parent number: "<< Particle(part).parents().size()
                                    << ", children number: " << Particle(part).children().size()
                                   <<std::endl;
                          std::cout << "------------------"<<std::endl;
                      }

                      // append W candidates
                      WCands.push_back(Particle(part));


                  }
              }


      }
      topCands = sortByPt(topCands);
      qCands   = sortByPt(qCands);
      WCands   = sortByPt(WCands);

      _h["Inclusive_nTop"]->fill(topCands.size());
      _h["Inclusive_nq"]->fill(qCands.size());
      _h["Inclusive_nW"]->fill(WCands.size());

      if (topCands.size()>=4){
        _h["Inclusive_pT_top0"]->fill(topCands.at(0).pT()/GeV);
        _h["Inclusive_pT_top1"]->fill(topCands.at(1).pT()/GeV);
        _h["Inclusive_pT_top2"]->fill(topCands.at(2).pT()/GeV);
        _h["Inclusive_pT_top3"]->fill(topCands.at(3).pT()/GeV);

        _h["Inclusive_eta_top0"]->fill(topCands.at(0).eta()/GeV);
        _h["Inclusive_eta_top1"]->fill(topCands.at(1).eta()/GeV);
        _h["Inclusive_eta_top2"]->fill(topCands.at(2).eta()/GeV);
        _h["Inclusive_eta_top3"]->fill(topCands.at(3).eta()/GeV);

        _h["Inclusive_m_top0"]->fill(topCands.at(0).mass()/GeV);
        _h["Inclusive_m_top1"]->fill(topCands.at(1).mass()/GeV);
        _h["Inclusive_m_top2"]->fill(topCands.at(2).mass()/GeV);
        _h["Inclusive_m_top3"]->fill(topCands.at(3).mass()/GeV);
      }
     


      if (debug){

        MSG_INFO( "Number of top quark : " << topCands.size());
        MSG_INFO("#----------------DONE--------------#");
      }


    }

    /// Normalise histograms etc., after the run
    void finalize()
    {
        //
        // For Powheg
        //
        // MSG_INFO("CROSS SSECTION:"<<crossSection());
        // auto xsec = isnan(crossSection()) ? 1: crossSection();
        // MSG_INFO("xsec = "<< xsec);
        // MSG_INFO("Sum of weights:"<<sumOfWeights());
        // const double sf = xsec / sumOfWeights();
        // _h["sumOfWeights"]->fill(xsec); // histograms are scaled to xs

        // For Sherpa/MG
        MSG_INFO("CROSS SSECTION:"<<crossSection());
        MSG_INFO("Sum of weights:"<<sumOfWeights());
        const double sf = crossSection() / sumOfWeights();
        for (auto hist : _h) { scale(hist.second, sf); }

        _h["sumOfWeights"]->fill(1);


    }
    //@}


  private:

    map<std::string,Histo1DPtr> _h;

  };



  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(tttt_parton);

}
