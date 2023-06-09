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

  class tttt_ttH: public Analysis {
  public:

    /// Constructor
    tttt_ttH()
      : Analysis("tttt_ttH")
    {    }


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {

        declare(FastJets(FinalState(Cuts::abseta < 2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
        declare(MissingMomentum(FinalState(Cuts::abseta < 4 && Cuts::pT >0*GeV)),"MissingET");

        book(_h["sumOfWeights"],"sumOfWeights",2,0,2);

        book(_h["Inclusive_nTop"],"Inclusive_nTop",5,0.5,5.5);
        book(_h["Inclusive_nH"],"Inclusive_nH",4,-0.5,3.5);
        book(_h["Inclusive_nTop_FromNonH_allevents"],"Inclusive_nTop_FromNonH_allevents",5,-0.5,4.5);
        book(_h["Inclusive_nTop_FromH_allevents"],"Inclusive_nTop_FromH_allevents",5,-0.5,4.5);

        book(_h["Inclusive_nTop_FromNonH"],"Inclusive_nTop_FromNonH",5,-0.5,4.5);
        book(_h["Inclusive_nTop_FromH"],"Inclusive_nTop_FromH",5,-0.5,4.5);

        book(_h["Inclusive_mH"],"Inclusive_mH",870,150,4500);
        book(_h["Inclusive_mH_zoomin"],"Inclusive_mH_zoomin",1740,150,4500);

        book(_h["Inclusive_mH400"],"Inclusive_mH400",20,300,500);
        book(_h["Inclusive_mH500"],"Inclusive_mH500",20,400,600);
        book(_h["Inclusive_mH600"],"Inclusive_mH600",20,500,700);
        book(_h["Inclusive_mH700"],"Inclusive_mH700",20,600,800);
        book(_h["Inclusive_mH800"],"Inclusive_mH800",20,700,900);
        book(_h["Inclusive_mH900"],"Inclusive_mH900",20,800,1000);
        book(_h["Inclusive_mH1000"],"Inclusive_mH1000",20,900,1100);
        book(_h["Inclusive_mH1250"],"Inclusive_mH1250",20,1150,1350);
        book(_h["Inclusive_mH1500"],"Inclusive_mH1500",20,1400,1600);
        book(_h["Inclusive_mH2000"],"Inclusive_mH2000",20,1900,2100);
        book(_h["Inclusive_mH2500"],"Inclusive_mH2500",20,2400,2600);
        book(_h["Inclusive_mH3000"],"Inclusive_mH3000",20,2900,3100);
        book(_h["Inclusive_mH1500_largewidth"],"Inclusive_mH1500_largewidth",20,900,2000);
        book(_h["Inclusive_mH2000_largewidth"],"Inclusive_mH2000_largewidth",20,1500,2500);
        book(_h["Inclusive_mH2500_largewidth"],"Inclusive_mH2500_largewidth",20,2000,3000);
        book(_h["Inclusive_mH3000_largewidth"],"Inclusive_mH3000_largewidth",20,2500,3500);

        book(_h["Inclusive_pT_H"],"Inclusive_pT_H",25,0,1000);
        book(_h["Inclusive_pT_ttbar_FromH"],"Inclusive_pT_ttbar_FromH",25,0,1000);

        book(_h["Inclusive_mTop1_FromH"],"Inclusive_mTop1_FromH",25,150,200);
        book(_h["Inclusive_mTop2_FromH"],"Inclusive_mTop2_FromH",25,150,200);
        book(_h["Inclusive_mTop1_zoomin_FromH"],"Inclusive_mTop1_zoomin_FromH",40,165,175);
        book(_h["Inclusive_mTop2_zoomin_FromH"],"Inclusive_mTop2_zoomin_FromH",40,165,175);
        book(_h["Inclusive_dR_ttbar_FromH"],"Inclusive_dR_ttbar_FromH",20,0,5);

        book(_h["Inclusive_InvM_FromH"],"Inclusive_InvM_FromH",870,150,4500);
        book(_h["Inclusive_InvM_FromH_zoomin"],"Inclusive_InvM_FromH_zoomin",1740,150,4500);

        book(_h["Inclusive_pToverInv_ttbar_FromH"],"Inclusive_pToverInv_ttbar_FromH",25,0,2);

        book(_h["Inclusive_InvM_FromH400"],"Inclusive_InvM_FromH400",20,300,500);
        book(_h["Inclusive_InvM_FromH500"],"Inclusive_InvM_FromH500",20,400,600);
        book(_h["Inclusive_InvM_FromH600"],"Inclusive_InvM_FromH600",20,500,700);
        book(_h["Inclusive_InvM_FromH700"],"Inclusive_InvM_FromH700",20,600,800);
        book(_h["Inclusive_InvM_FromH800"],"Inclusive_InvM_FromH800",20,700,900);
        book(_h["Inclusive_InvM_FromH900"],"Inclusive_InvM_FromH900",20,800,1000);
        book(_h["Inclusive_InvM_FromH1000"],"Inclusive_InvM_FromH1000",20,900,1100);
        book(_h["Inclusive_InvM_FromH1250"],"Inclusive_InvM_FromH1250",20,1150,1350);
        book(_h["Inclusive_InvM_FromH1500"],"Inclusive_InvM_FromH1500",20,1400,1600);
        book(_h["Inclusive_InvM_FromH2000"],"Inclusive_InvM_FromH2000",20,1900,2100);
        book(_h["Inclusive_InvM_FromH2500"],"Inclusive_InvM_FromH2500",20,2400,2600);
        book(_h["Inclusive_InvM_FromH3000"],"Inclusive_InvM_FromH3000",20,2900,3100);

        book(_h["Inclusive_pT_ttbar_FromNonH"],"Inclusive_pT_ttbar_FromNonH",20,0,600);
        book(_h["Inclusive_mTop1_FromNonH"],"Inclusive_mTop1_FromNonH",25,150,200);
        book(_h["Inclusive_mTop2_FromNonH"],"Inclusive_mTop2_FromNonH",25,150,200);
        book(_h["Inclusive_mTop1_zoomin_FromNonH"],"Inclusive_mTop1_zoomin_FromNonH",40,165,175);
        book(_h["Inclusive_mTop2_zoomin_FromNonH"],"Inclusive_mTop2_zoomin_FromNonH",40,165,175);
        book(_h["Inclusive_dR_ttbar_FromNonH"],"Inclusive_dR_ttbar_FromNonH",20,0,5);

        book(_h["Inclusive_pToverInv_ttbar_FromNonH"],"Inclusive_pToverInv_ttbar_FromNonH",25,0,3);
        book(_h["Inclusive_InvM_FromNonH"],"Inclusive_InvM_FromNonH",40,0,1800);
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // const double weight = event.weight();

      // MSG_INFO("#----------------Event--------------#");

      //DO PDG analysis
      vector<std::shared_ptr<const HepMC3::GenParticle>> genParticles = HepMCUtils::particles(event.genEvent());

      Particles HCands;
      Particles topCands,topCandsFromH,topCandsFromNonH;

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

                      if (!( part->production_vertex() && ( hasParent(part,35) || hasParent(part,36) ) ) ) {
                          topCandsFromNonH.push_back(Particle(part));
                      }


                    }

              }

              //Select heavy higgs bosons
              if((fabs(part->pdg_id())==35||fabs(part->pdg_id())==36)&&Particle(part).children().size())
              {

                    if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0 )
                    {
                     if(debug){
                      std::cout <<"production Heavy Higgs: "<< part->pdg_id()
                                   << ", status: " <<  part->status()
                                   << ", barcode: " << part->id()
                                  <<std::endl;
                      std::cout << "pt: " <<  part->momentum().perp()
                                << ", eta: " <<  part->momentum().eta()
                                << ", phi: " <<  part->momentum().phi()
                               <<std::endl;
                      std::cout <<"Heavy Higgs parent number: "<< Particle(part).parents().size()
                                << ", children number: " << Particle(part).children().size()
                               <<std::endl;
                      std::cout << "------------------"<<std::endl;
                     }
                      HCands.push_back(Particle(part));
                    }

              }
          // }
      }

      // MSG_INFO("Number of W boson : "   << wCands.size());
      _h["Inclusive_nH"]->fill(HCands.size());
      _h["Inclusive_nTop"]->fill(topCands.size());

      _h["Inclusive_nTop_FromNonH_allevents"]->fill(topCandsFromNonH.size());

      if (HCands.size()==1){
        _h["Inclusive_nTop_FromNonH"]->fill(topCandsFromNonH.size());
      }
      else{
        _h["Inclusive_nTop_FromNonH"]->fill(-999);
      }



      for(const Particle &Higgs: HCands){
        if (debug){
            MSG_INFO("HCands id = " << Higgs.pid() << ", HCands barcode = " << Higgs.genParticle()->id() << ", HCands status = " << Higgs.genParticle()->status());
        }

        //check top decay chain
        Particle Higgs_to_decay = getLastInstance(Higgs);
        for(const Particle &Higgs_c: Higgs_to_decay.children()){
         if (debug) {
            MSG_INFO ( "HCands child id = " << Higgs_c.pid() << ", HCands child barcode = " << Higgs_c.genParticle()->id() << ", HCands child status = " << Higgs_c.genParticle()->status());
          }
          if(fabs(Higgs_c.pid()) == 6)
           {
               topCandsFromH.push_back(Higgs_c);
           }
        }
        if (debug) MSG_INFO ( "\n");

      }

      if (HCands.size()==1){
        _h["Inclusive_pT_H"]->fill(HCands.at(0).pT());
        _h["Inclusive_mH"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH_zoomin"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH400"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH500"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH600"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH700"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH800"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH900"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1000"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1250"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1500"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2000"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2500"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH3000"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1500_largewidth"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2000_largewidth"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2500_largewidth"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH3000_largewidth"]->fill(HCands.at(0).mass());
      }
      else{
          _h["Inclusive_pT_H"]->fill(-999);
          _h["Inclusive_mH"]->fill(-999);
          _h["Inclusive_mH_zoomin"]->fill(-999);
          _h["Inclusive_mH400"]->fill(-999);
          _h["Inclusive_mH500"]->fill(-999);
          _h["Inclusive_mH600"]->fill(-999);
          _h["Inclusive_mH700"]->fill(-999);
          _h["Inclusive_mH800"]->fill(-999);
          _h["Inclusive_mH900"]->fill(-999);
          _h["Inclusive_mH1000"]->fill(-999);
          _h["Inclusive_mH1250"]->fill(-999);
          _h["Inclusive_mH1500"]->fill(-999);
          _h["Inclusive_mH2000"]->fill(-999);
          _h["Inclusive_mH2500"]->fill(-999);
          _h["Inclusive_mH3000"]->fill(-999);
          _h["Inclusive_mH1500_largewidth"]->fill(-999);
          _h["Inclusive_mH2000_largewidth"]->fill(-999);
          _h["Inclusive_mH2500_largewidth"]->fill(-999);
          _h["Inclusive_mH3000_largewidth"]->fill(-999);

      }


      _h["Inclusive_nTop_FromH_allevents"]->fill(topCandsFromH.size());

      if (HCands.size()==1){
        _h["Inclusive_nTop_FromH"]->fill(topCandsFromH.size());
      }
      else{
        _h["Inclusive_nTop_FromH"]->fill(-999);
      }


      sortByPt(topCandsFromH);


      if ( topCandsFromH.size() == 2 ){
        double pT_ttbar_FromH = (topCandsFromH.at(0).momentum() + topCandsFromH.at(1).momentum()).pT()/GeV;
        double dR_ttbar_FromH = fabs(deltaR(topCandsFromH.at(0),topCandsFromH.at(1)));
        double InvM_ttbar_FromH = ( topCandsFromH.at(0).momentum() + topCandsFromH.at(1).momentum() ).mass()/GeV;

        double pT_over_InvM_ttbar_FromH = pT_ttbar_FromH/InvM_ttbar_FromH;

        // std::cout << "pT_ttbar = " << pT_ttbar << std::endl;
        _h["Inclusive_pT_ttbar_FromH"]->fill(pT_ttbar_FromH);
        _h["Inclusive_mTop1_FromH"]->fill(topCandsFromH.at(0).mass());
        _h["Inclusive_mTop2_FromH"]->fill(topCandsFromH.at(1).mass());
        _h["Inclusive_mTop1_zoomin_FromH"]->fill(topCandsFromH.at(0).mass());
        _h["Inclusive_mTop2_zoomin_FromH"]->fill(topCandsFromH.at(1).mass());
        _h["Inclusive_dR_ttbar_FromH"]->fill(dR_ttbar_FromH);
        _h["Inclusive_InvM_FromH"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH_zoomin"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH400"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH500"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH600"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH700"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH800"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH900"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH1000"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH1250"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH1500"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH2000"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH2500"]->fill(InvM_ttbar_FromH);
        _h["Inclusive_InvM_FromH3000"]->fill(InvM_ttbar_FromH);

        _h["Inclusive_pToverInv_ttbar_FromH"]->fill(pT_over_InvM_ttbar_FromH);

      }
      else{
        _h["Inclusive_pT_ttbar_FromH"]->fill(-999);
        _h["Inclusive_mTop1_FromH"]->fill(-999);
        _h["Inclusive_mTop2_FromH"]->fill(-999);
        _h["Inclusive_mTop1_zoomin_FromH"]->fill(-999);
        _h["Inclusive_mTop2_zoomin_FromH"]->fill(-999);
        _h["Inclusive_dR_ttbar_FromH"]->fill(-999);
        _h["Inclusive_InvM_FromH"]->fill(-999);
        _h["Inclusive_InvM_FromH_zoomin"]->fill(-999);
        _h["Inclusive_InvM_FromH400"]->fill(-999);
        _h["Inclusive_InvM_FromH500"]->fill(-999);
        _h["Inclusive_InvM_FromH600"]->fill(-999);
        _h["Inclusive_InvM_FromH700"]->fill(-999);
        _h["Inclusive_InvM_FromH800"]->fill(-999);
        _h["Inclusive_InvM_FromH900"]->fill(-999);
        _h["Inclusive_InvM_FromH1000"]->fill(-999);
        _h["Inclusive_InvM_FromH1250"]->fill(-999);
        _h["Inclusive_InvM_FromH1500"]->fill(-999);
        _h["Inclusive_InvM_FromH2000"]->fill(-999);
        _h["Inclusive_InvM_FromH2500"]->fill(-999);
        _h["Inclusive_InvM_FromH3000"]->fill(-999);
        _h["Inclusive_pToverInv_ttbar_FromH"]->fill(-999);

      }

      if ( topCandsFromNonH.size() == 2 ){
        double pT_ttbar_FromNonH = (topCandsFromNonH.at(0).momentum() + topCandsFromNonH.at(1).momentum()).pT()/GeV;
        double dR_ttbar_FromNonH = fabs(deltaR(topCandsFromNonH.at(0),topCandsFromNonH.at(1)));
        double InvM_ttbar_FromNonH = ( topCandsFromNonH.at(0).momentum() + topCandsFromNonH.at(1).momentum() ).mass()/GeV;
        double pT_over_InvM_ttbar_FromNonH = pT_ttbar_FromNonH/InvM_ttbar_FromNonH;

        // std::cout << "pT_ttbar = " << pT_ttbar << std::endl;
        _h["Inclusive_pT_ttbar_FromNonH"]->fill(pT_ttbar_FromNonH);
        _h["Inclusive_mTop1_FromNonH"]->fill(topCandsFromNonH.at(0).mass());
        _h["Inclusive_mTop2_FromNonH"]->fill(topCandsFromNonH.at(1).mass());
        _h["Inclusive_mTop1_zoomin_FromNonH"]->fill(topCandsFromNonH.at(0).mass());
        _h["Inclusive_mTop2_zoomin_FromNonH"]->fill(topCandsFromNonH.at(1).mass());
        _h["Inclusive_dR_ttbar_FromNonH"]->fill(dR_ttbar_FromNonH);

        _h["Inclusive_InvM_FromNonH"]->fill(InvM_ttbar_FromNonH);
        _h["Inclusive_pToverInv_ttbar_FromNonH"]->fill(pT_over_InvM_ttbar_FromNonH);

      }
      else{
        _h["Inclusive_pT_ttbar_FromNonH"]->fill(-999);
        _h["Inclusive_mTop1_FromNonH"]->fill(-999);
        _h["Inclusive_mTop2_FromNonH"]->fill(-999);
        _h["Inclusive_mTop1_zoomin_FromNonH"]->fill(-999);
        _h["Inclusive_mTop2_zoomin_FromNonH"]->fill(-999);
        _h["Inclusive_dR_ttbar_FromNonH"]->fill(-999);

        _h["Inclusive_InvM_FromNonH"]->fill(-999);
        _h["Inclusive_pToverInv_ttbar_FromNonH"]->fill(-999);
      }

      if (debug){
        MSG_INFO( "Number of top quark : " << topCands.size());
        MSG_INFO( "Number of H boson:" << HCands.size());
        MSG_INFO( "Number of Top quark is from H:" << topCandsFromH.size());
        MSG_INFO( "Number of Top quark is from Non-H:" << topCandsFromNonH.size());
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
  DECLARE_RIVET_PLUGIN(tttt_ttH);

}
