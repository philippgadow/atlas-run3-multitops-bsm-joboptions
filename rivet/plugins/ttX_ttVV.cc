#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/AnalysisLoader.hh"

#include <numeric>
#include <functional>

/* 
 * Author : Philipp Gadow (philipp.gadow@cern.ch) 
 */

namespace Rivet {

  bool debug = false;


  void fillHistKinematics(map<std::string,Histo1DPtr> _h, std::string name_template, Particle ptcl, bool includeMass){
    _h[name_template + "_pT"]->fill(ptcl.pT()/GeV);
    _h[name_template + "_eta"]->fill(ptcl.eta());
    if (includeMass){
      _h[name_template + "_mass"]->fill(ptcl.mass()/GeV);
    }
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

  bool hasChild(Particle ptcl, int pdgID) { //If the parent particle decays to some child particle
      for (auto child:ptcl.children())
          if (child.pid()==pdgID) return true;
      return false;
  }

  bool hasParent(Particle ptcl, int pdgID) { //If the a particle has some parent
      for (auto parent:ptcl.parents())
        if (parent.pid()==pdgID) return true;
      return false;
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

  Particle getLastInstance(Particle ptcl) { //Find last point in decay chain
    if ( ptcl.genParticle()->end_vertex() ) { // check if has end vertex
      if ( !hasChild(ptcl.genParticle(),ptcl.pid()) ) return ptcl;
      else return getLastInstance(ptcl.children()[0]);
    }
    return ptcl;
  }

  void getChildren(map<std::string,Histo1DPtr> _h, std::string name_template, Particle Parent, Particles& childrenList){
    if (debug){
        std::cout << "Getting children for candidate id = " << Parent.pid() << ", barcode = " << Parent.genParticle()->id() << ", status = " << Parent.genParticle()->status() << std::endl;
    }
    //check parent decay chain
    Particle Parent_to_decay = getLastInstance(Parent);
    for(const Particle &Child: Parent_to_decay.children()){
      if (debug) {
        std::cout << "Candidate child id = " << Child.pid() << ", child barcode = " << Child.genParticle()->id() << ", child status = " << Child.genParticle()->status() << std::endl;
      }
      childrenList.push_back(Child);
      _h[name_template + "_decay"]->fill(Child.pid());
    } 
  }


  
  class ttX_ttVV: public Analysis {
  public:

    /// Minimal constructor
    ttX_ttVV() : Analysis("ttX_ttVV")
    {
    }

    /// Set up projections and book histograms
    void init() {
            
      //Histogramming 
      book(_h["sumOfWeights"],"sumOfWeights",2,0,2);

      book(_h["top_decay"],"top_decay",51,-25.5,25.5);
      book(_h["H_decay"],"H_decay",51,-25.5,25.5);
      book(_h["W_decay"],"W_decay",51,-25.5,25.5);
      book(_h["Z_decay"],"Z_decay",51,-25.5,25.5);

      book(_h["Inclusive_nTop"],"Inclusive_nTop",5,0.5,5.5);
      book(_h["Inclusive_nH"],"Inclusive_nH",5,0.5,5.5); 
      book(_h["Inclusive_nW"],"Inclusive_nW",10,0.5,10.5);
      book(_h["Inclusive_nZ"],"Inclusive_nZ",10,0.5,10.5);

      book(_h["Inclusive_top_pT"],"Inclusive_top_pT",80,0,1000);
      book(_h["Inclusive_top0_pT"],"Inclusive_top0_pT",80,0,1000);
      book(_h["Inclusive_top1_pT"],"Inclusive_top1_pT",80,0,1000);
      book(_h["Inclusive_H_pT"],"Inclusive_H_pT",80,0,1000);
      book(_h["Inclusive_H0_pT"],"Inclusive_H0_pT",80,0,1000);
      book(_h["Inclusive_H1_pT"],"Inclusive_H1_pT",80,0,1000);
      book(_h["Inclusive_W_pT"],"Inclusive_W_pT",80,0,1000);
      book(_h["Inclusive_W0_pT"],"Inclusive_W0_pT",80,0,1000);
      book(_h["Inclusive_W1_pT"],"Inclusive_W1_pT",80,0,1000);
      book(_h["Inclusive_Z_pT"],"Inclusive_Z_pT",80,0,1000);
      book(_h["Inclusive_Z0_pT"],"Inclusive_Z0_pT",80,0,1000);
      book(_h["Inclusive_Z1_pT"],"Inclusive_Z1_pT",80,0,1000);

      book(_h["Inclusive_top_eta"],"Inclusive_top_eta",40,-5.,5.);
      book(_h["Inclusive_top0_eta"],"Inclusive_top0_eta",40,-5.,5.);
      book(_h["Inclusive_top1_eta"],"Inclusive_top1_eta",40,-5.,5.);
      book(_h["Inclusive_H_eta"],"Inclusive_H_eta",40,-5.,5.);
      book(_h["Inclusive_H0_eta"],"Inclusive_H0_eta",40,-5.,5.);
      book(_h["Inclusive_H1_eta"],"Inclusive_H1_eta",40,-5.,5.);
      book(_h["Inclusive_W_eta"],"Inclusive_W_eta",40,-5.,5.);
      book(_h["Inclusive_W0_eta"],"Inclusive_W0_eta",40,-5.,5.);
      book(_h["Inclusive_W1_eta"],"Inclusive_W1_eta",40,-5.,5.);
      book(_h["Inclusive_Z_eta"],"Inclusive_Z_eta",40,-5.,5.);
      book(_h["Inclusive_Z0_eta"],"Inclusive_Z0_eta",40,-5.,5.);
      book(_h["Inclusive_Z1_eta"],"Inclusive_Z1_eta",40,-5.,5.);

      book(_h["Inclusive_top_mass"],"Inclusive_top_mass",40,150,200);
      book(_h["Inclusive_top0_mass"],"Inclusive_top0_mass",40,150,200);
      book(_h["Inclusive_top1_mass"],"Inclusive_top1_mass",40,150,200);
      book(_h["Inclusive_H_mass"],"Inclusive_H_mass",40,100,150);
      book(_h["Inclusive_H0_mass"],"Inclusive_H0_mass",40,100,150);
      book(_h["Inclusive_H1_mass"],"Inclusive_H1_mass",40,100,150);
      book(_h["Inclusive_W_mass"],"Inclusive_W_mass",40,55,105);
      book(_h["Inclusive_W0_mass"],"Inclusive_W0_mass",40,55,105);
      book(_h["Inclusive_W1_mass"],"Inclusive_W1_mass",40,55,105);
      book(_h["Inclusive_Z_mass"],"Inclusive_Z_mass",40,65,165);
      book(_h["Inclusive_Z0_mass"],"Inclusive_Z0_mass",40,65,175);
      book(_h["Inclusive_Z1_mass"],"Inclusive_Z1_mass",40,65,175);

    }


    void analyze(const Event& event) {
      vector<std::shared_ptr<const HepMC3::GenParticle>> genParticles = HepMCUtils::particles(event.genEvent());

      Particles topCands;
      Particles HCands;
      Particles WCands;
      Particles ZCands;

      for (ConstGenParticlePtr part : HepMCUtils::particles(event.genEvent()))
      {
              //Select Tops
              addCand(part, {6}, topCands);

              //Select Higgs
              addCand(part, {25}, HCands);

              //Select W
              addCand(part, {24}, WCands);

              //Select Z
              addCand(part, {23}, ZCands);

      }

      topCands = sortByPt(topCands);
      HCands = sortByPt(HCands);
      WCands   = sortByPt(WCands);
      ZCands   = sortByPt(ZCands);
      
      _h["Inclusive_nTop"]->fill(topCands.size());
      _h["Inclusive_nH"]->fill(HCands.size());
      _h["Inclusive_nW"]->fill(WCands.size());
      _h["Inclusive_nZ"]->fill(ZCands.size());

      if (topCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_top0", topCands.at(0), true);
          fillHistKinematics(_h, "Inclusive_top1", topCands.at(1), true);
      }
      for (Particle top: topCands){
          fillHistKinematics(_h, "Inclusive_top", top, true);
          Particles topChildren;
          getChildren(_h, "top", top, topChildren);
      }

      if (HCands.size()>=1){
          fillHistKinematics(_h, "Inclusive_H0", HCands.at(0), true);
      }
      if (HCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_H1", HCands.at(1), true);
      }
      for (Particle higgs: HCands){
        fillHistKinematics(_h, "Inclusive_H", higgs, true);
        Particles HChildren;
        getChildren(_h, "H", higgs, HChildren);
      }

      if (WCands.size()>=1){
          fillHistKinematics(_h, "Inclusive_W0", WCands.at(0), true);
      }
      if (WCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_W1", WCands.at(1), true);
      }
      for (Particle wboson: WCands){
        fillHistKinematics(_h, "Inclusive_W", wboson, true);
        Particles WChildren;
        getChildren(_h, "W", wboson, WChildren);
      }

      if (ZCands.size()>=1){
          fillHistKinematics(_h, "Inclusive_Z0", ZCands.at(0), true);
      }
      if (ZCands.size()>=2){
          fillHistKinematics(_h, "Inclusive_Z1", ZCands.at(1), true);
      }
      for (Particle zboson: ZCands){
        fillHistKinematics(_h, "Inclusive_Z", zboson, true);
        Particles ZChildren;
        getChildren(_h, "Z", zboson, ZChildren);
      }

    }

    void finalize() {
        MSG_INFO("CROSS SSECTION:"<<crossSection());
        MSG_INFO("Sum of weights:"<<sumOfWeights());
        const double sf = crossSection() / sumOfWeights();
        for (auto hist : _h) { scale(hist.second, sf); }

        _h["sumOfWeights"]->fill(1);
    }

    //@}


  private:

    // @name Histogram data members
    //@{
    //
    map<std::string,Histo1DPtr> _h;

    //@}

  };



  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(ttX_ttVV);
}