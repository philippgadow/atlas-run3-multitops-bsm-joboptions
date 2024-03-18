// -*- C++ -*-
// #include "Root/TH1F.h"
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/ZFinder.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/IdentifiedFinalState.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/NonPromptFinalState.hh"
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

  class tttt_ttZp: public Analysis {
  public:

    /// Constructor
    tttt_ttZp()
      : Analysis("tttt_ttZp")
    {    }


    /// @name Analysis methods
    //@{

    /// Book histograms and initialise projections before the run
    void init() {

        declare(FastJets(FinalState(Cuts::abseta < 2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
        declare(MissingMomentum(FinalState(Cuts::abseta < 4 && Cuts::pT >0*GeV)),"MissingET");

        declare(UnstableParticles(),"UFS");

        FinalState lepfs;
        //Projection to find prompt electrons
        IdentifiedFinalState el_id(lepfs);
        el_id.acceptIdPair(PID::ELECTRON);
        PromptFinalState electrons(el_id);
        electrons.acceptTauDecays(true);
        declare(electrons,"electrons");

        //Projection to find prompt muons
        IdentifiedFinalState mu_id(lepfs);
        mu_id.acceptIdPair(PID::MUON);
        PromptFinalState muons(mu_id);
        muons.acceptTauDecays(true);
        declare(muons,"muons");

        //Projection to find non-prompt electrons
        IdentifiedFinalState np_el_id(lepfs);
        np_el_id.acceptIdPair(PID::ELECTRON);
        NonPromptFinalState np_electrons(np_el_id);
        np_electrons.acceptTauDecays(true);
        declare(np_electrons,"np_electrons");


        //Projection to find non-prompt muons
        IdentifiedFinalState np_mu_id(lepfs);
        np_mu_id.acceptIdPair(PID::MUON);
        NonPromptFinalState np_muons(np_mu_id);
        np_muons.acceptTauDecays(true);
        declare(np_muons,"np_muons");

        book(_h["sumOfWeights"],"sumOfWeights",2,0,2);

        book(_h["Inclusive_nTop"],"Inclusive_nTop",5,0.5,5.5);
        book(_h["Inclusive_nZprime"],"Inclusive_nZprime",4,-0.5,3.5);
        book(_h["Inclusive_nTop_FromNonZprime_allevents"],"Inclusive_nTop_FromNonZprime_allevents",5,-0.5,4.5);
        book(_h["Inclusive_nTop_FromZprime_allevents"],"Inclusive_nTop_FromZprime_allevents",5,-0.5,4.5);

        book(_h["Inclusive_nTop_FromNonZprime"],"Inclusive_nTop_FromNonZprime",5,-0.5,4.5);
        book(_h["Inclusive_nTop_FromZprime"],"Inclusive_nTop_FromZprime",5,-0.5,4.5);

        book(_h["Inclusive_mZprime"],"Inclusive_mZprime",870,150,4500);
        book(_h["Inclusive_mZprime_zoomin"],"Inclusive_mZprime_zoomin",1740,150,4500);

        book(_h["Inclusive_mZprime400"],"Inclusive_mZprime400",20,300,500);
        book(_h["Inclusive_mZprime500"],"Inclusive_mZprime500",20,400,600);
        book(_h["Inclusive_mZprime600"],"Inclusive_mZprime600",20,500,700);
        book(_h["Inclusive_mZprime700"],"Inclusive_mZprime700",20,600,800);
        book(_h["Inclusive_mZprime800"],"Inclusive_mZprime800",20,700,900);
        book(_h["Inclusive_mZprime900"],"Inclusive_mZprime900",20,800,1000);
        book(_h["Inclusive_mZprime1000"],"Inclusive_mZprime1000",20,900,1100);
        book(_h["Inclusive_mZprime1250"],"Inclusive_mZprime1250",20,1150,1350);
        book(_h["Inclusive_mZprime1500"],"Inclusive_mZprime1500",20,1400,1600);
        book(_h["Inclusive_mZprime2000"],"Inclusive_mZprime2000",20,1900,2100);
        book(_h["Inclusive_mZprime2500"],"Inclusive_mZprime2500",20,2400,2600);
        book(_h["Inclusive_mZprime3000"],"Inclusive_mZprime3000",20,2900,3100);

        book(_h["Inclusive_pT_Zprime"],"Inclusive_pT_Zprime",25,0,1000);
        book(_h["Inclusive_pT_ttbar_FromZprime"],"Inclusive_pT_ttbar_FromZprime",25,0,1000);

        book(_h["Inclusive_mTop1_FromZprime"],"Inclusive_mTop1_FromZprime",25,150,200);
        book(_h["Inclusive_mTop2_FromZprime"],"Inclusive_mTop2_FromZprime",25,150,200);
        book(_h["Inclusive_mTop1_zoomin_FromZprime"],"Inclusive_mTop1_zoomin_FromZprime",40,165,175);
        book(_h["Inclusive_mTop2_zoomin_FromZprime"],"Inclusive_mTop2_zoomin_FromZprime",40,165,175);
        book(_h["Inclusive_dR_ttbar_FromZprime"],"Inclusive_dR_ttbar_FromZprime",20,0,5);

        book(_h["Inclusive_InvM_FromZprime"],"Inclusive_InvM_FromZprime",870,150,4500);
        book(_h["Inclusive_InvM_FromZprime_zoomin"],"Inclusive_InvM_FromZprime_zoomin",1740,150,4500);

        book(_h["Inclusive_pToverInv_ttbar_FromZprime"],"Inclusive_pToverInv_ttbar_FromZprime",25,0,2);

        book(_h["Inclusive_InvM_FromZprime400"],"Inclusive_InvM_FromZprime400",20,300,500);
        book(_h["Inclusive_InvM_FromZprime500"],"Inclusive_InvM_FromZprime500",20,400,600);
        book(_h["Inclusive_InvM_FromZprime600"],"Inclusive_InvM_FromZprime600",20,500,700);
        book(_h["Inclusive_InvM_FromZprime700"],"Inclusive_InvM_FromZprime700",20,600,800);
        book(_h["Inclusive_InvM_FromZprime800"],"Inclusive_InvM_FromZprime800",20,700,900);
        book(_h["Inclusive_InvM_FromZprime900"],"Inclusive_InvM_FromZprime900",20,800,1000);
        book(_h["Inclusive_InvM_FromZprime1000"],"Inclusive_InvM_FromZprime1000",20,900,1100);
        book(_h["Inclusive_InvM_FromZprime1250"],"Inclusive_InvM_FromZprime1250",20,1150,1350);
        book(_h["Inclusive_InvM_FromZprime1500"],"Inclusive_InvM_FromZprime1500",20,1400,1600);
        book(_h["Inclusive_InvM_FromZprime2000"],"Inclusive_InvM_FromZprime2000",20,1900,2100);
        book(_h["Inclusive_InvM_FromZprime2500"],"Inclusive_InvM_FromZprime2500",20,2400,2600);
        book(_h["Inclusive_InvM_FromZprime3000"],"Inclusive_InvM_FromZprime3000",20,2900,3100);

        book(_h["Inclusive_pT_ttbar_FromNonZprime"],"Inclusive_pT_ttbar_FromNonZprime",20,0,600);
        book(_h["Inclusive_mTop1_FromNonZprime"],"Inclusive_mTop1_FromNonZprime",25,150,200);
        book(_h["Inclusive_mTop2_FromNonZprime"],"Inclusive_mTop2_FromNonZprime",25,150,200);
        book(_h["Inclusive_mTop1_zoomin_FromNonZprime"],"Inclusive_mTop1_zoomin_FromNonZprime",40,165,175);
        book(_h["Inclusive_mTop2_zoomin_FromNonZprime"],"Inclusive_mTop2_zoomin_FromNonZprime",40,165,175);
        book(_h["Inclusive_dR_ttbar_FromNonZprime"],"Inclusive_dR_ttbar_FromNonZprime",20,0,5);

        book(_h["Inclusive_pToverInv_ttbar_FromNonZprime"],"Inclusive_pToverInv_ttbar_FromNonZprime",25,0,3);
        book(_h["Inclusive_InvM_FromNonZprime"],"Inclusive_InvM_FromNonZprime",40,0,1800);

        book(_h["Inclusive_nLep"],"Inclusive_nLep",11,-0.5,10.5);
        book(_h["Inclusive_nLep_prompt"],"Inclusive_nLep_prompt",11,-0.5,10.5);
        book(_h["Inclusive_nLep_nonprompt"],"Inclusive_nLep_nonprompt",11,-0.5,10.5);

        book(_h["Inclusive_lep0Pt"],"Inclusive_lep0Pt",20,0,300);
        book(_h["Inclusive_lep0Eta"],"Inclusive_lep0Eta",10,-2.5,2.5);
        book(_h["Inclusive_lep0Phi"],"Inclusive_lep0Phi",16,-4,4);

        book(_h["Inclusive_lep1Pt"],"Inclusive_lep1Pt",20,0,150);
        book(_h["Inclusive_lep1Eta"],"Inclusive_lep1Eta",10,-2.5,2.5);
        book(_h["Inclusive_lep1Phi"],"Inclusive_lep1Phi",16,-4,4);

        book(_h["Inclusive_lep2Pt"],"Inclusive_lep2Pt",20,0,100);
        book(_h["Inclusive_lep2Eta"],"Inclusive_lep2Eta",10,-2.5,2.5);
        book(_h["Inclusive_lep2Phi"],"Inclusive_lep2Phi",16,-4,4);

        book(_h["Inclusive_lep3Pt"],"Inclusive_lep3Pt",20,0,100);
        book(_h["Inclusive_lep3Eta"],"Inclusive_lep3Eta",10,-2.5,2.5);
        book(_h["Inclusive_lep3Phi"],"Inclusive_lep3Phi",16,-4,4);
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // const double weight = event.weight();

      // MSG_INFO("#----------------Event--------------#");

      //DO PDG analysis
      vector<std::shared_ptr<const HepMC3::GenParticle>> genParticles = HepMCUtils::particles(event.genEvent());

      Particles ZprimeCands;
      Particles topCands,topCandsFromZprime,topCandsFromNonZprime;

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

                      // append top candidates
                      topCands.push_back(Particle(part));

                      if (!( part->production_vertex() && ( hasParent(part,32) ) ) ) {
                          topCandsFromNonZprime.push_back(Particle(part));
                      }
                    }
              }

              //Select Zprime bosons
              if((fabs(part->pdg_id())==32)&&Particle(part).children().size())
              {

                    if ( part->production_vertex() && !hasParent(part, part->pdg_id()) && Particle(part).children().size()>0 )
                    {
                     if(debug){
                      std::cout <<"production Zprime: "<< part->pdg_id()
                                   << ", status: " <<  part->status()
                                   << ", barcode: " << part->id()
                                  <<std::endl;
                      std::cout << "pt: " <<  part->momentum().perp()
                                << ", eta: " <<  part->momentum().eta()
                                << ", phi: " <<  part->momentum().phi()
                               <<std::endl;
                      std::cout <<"Zprime parent number: "<< Particle(part).parents().size()
                                << ", children number: " << Particle(part).children().size()
                               <<std::endl;
                      std::cout << "------------------"<<std::endl;
                     }
                      ZprimeCands.push_back(Particle(part));
                    }

              }
          // }
      }

      // MSG_INFO("Number of W boson : "   << wCands.size());
      _h["Inclusive_nZprime"]->fill(ZprimeCands.size());
      _h["Inclusive_nTop"]->fill(topCands.size());

      _h["Inclusive_nTop_FromNonZprime_allevents"]->fill(topCandsFromNonZprime.size());

      if (ZprimeCands.size()==1){
        _h["Inclusive_nTop_FromNonZprime"]->fill(topCandsFromNonZprime.size());
      }
      else{
        _h["Inclusive_nTop_FromNonZprime"]->fill(-999);
      }



      for(const Particle &Zprime: ZprimeCands){
        if (debug){
            MSG_INFO("ZprimeCands id = " << Zprime.pid() << ", ZprimeCands barcode = " << Zprime.genParticle()->id() << ", ZprimeCands status = " << Zprime.genParticle()->status());
        }

        //check top decay chain
        Particle Zprime_to_decay = getLastInstance(Zprime);
        for(const Particle &Zprime_c: Zprime_to_decay.children()){
         if (debug) {
            MSG_INFO ( "ZprimeCands child id = " << Zprime_c.pid() << ", ZprimeCands child barcode = " << Zprime_c.genParticle()->id() << ", ZprimeCands child status = " << Zprime_c.genParticle()->status());
          }
          if(fabs(Zprime_c.pid()) == 6)
           {
               topCandsFromZprime.push_back(Zprime_c);
           }
        }
        if (debug) MSG_INFO ( "\n");

      }

      if (ZprimeCands.size()==1){
        _h["Inclusive_pT_Zprime"]->fill(ZprimeCands.at(0).pT());
        _h["Inclusive_mZprime"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime_zoomin"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime400"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime500"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime600"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime700"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime800"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime900"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime1000"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime1250"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime1500"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime2000"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime2500"]->fill(ZprimeCands.at(0).mass());
        _h["Inclusive_mZprime3000"]->fill(ZprimeCands.at(0).mass());
      }
      else{
          _h["Inclusive_pT_Zprime"]->fill(-999);
          _h["Inclusive_mZprime"]->fill(-999);
          _h["Inclusive_mZprime_zoomin"]->fill(-999);
          _h["Inclusive_mZprime400"]->fill(-999);
          _h["Inclusive_mZprime500"]->fill(-999);
          _h["Inclusive_mZprime600"]->fill(-999);
          _h["Inclusive_mZprime700"]->fill(-999);
          _h["Inclusive_mZprime800"]->fill(-999);
          _h["Inclusive_mZprime900"]->fill(-999);
          _h["Inclusive_mZprime1000"]->fill(-999);
          _h["Inclusive_mZprime1250"]->fill(-999);
          _h["Inclusive_mZprime1500"]->fill(-999);
          _h["Inclusive_mZprime2000"]->fill(-999);
          _h["Inclusive_mZprime2500"]->fill(-999);
          _h["Inclusive_mZprime3000"]->fill(-999);
      }


      _h["Inclusive_nTop_FromZprime_allevents"]->fill(topCandsFromZprime.size());

      if (ZprimeCands.size()==1){
        _h["Inclusive_nTop_FromZprime"]->fill(topCandsFromZprime.size());
      }
      else{
        _h["Inclusive_nTop_FromZprime"]->fill(-999);
      }


      sortByPt(topCandsFromZprime);


      if ( topCandsFromZprime.size() == 2 ){
        double pT_ttbar_FromZprime = (topCandsFromZprime.at(0).momentum() + topCandsFromZprime.at(1).momentum()).pT()/GeV;
        double dR_ttbar_FromZprime = fabs(deltaR(topCandsFromZprime.at(0),topCandsFromZprime.at(1)));
        double InvM_ttbar_FromZprime = ( topCandsFromZprime.at(0).momentum() + topCandsFromZprime.at(1).momentum() ).mass()/GeV;

        double pT_over_InvM_ttbar_FromZprime = pT_ttbar_FromZprime/InvM_ttbar_FromZprime;

        // std::cout << "pT_ttbar = " << pT_ttbar << std::endl;
        _h["Inclusive_pT_ttbar_FromZprime"]->fill(pT_ttbar_FromZprime);
        _h["Inclusive_mTop1_FromZprime"]->fill(topCandsFromZprime.at(0).mass());
        _h["Inclusive_mTop2_FromZprime"]->fill(topCandsFromZprime.at(1).mass());
        _h["Inclusive_mTop1_zoomin_FromZprime"]->fill(topCandsFromZprime.at(0).mass());
        _h["Inclusive_mTop2_zoomin_FromZprime"]->fill(topCandsFromZprime.at(1).mass());
        _h["Inclusive_dR_ttbar_FromZprime"]->fill(dR_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime_zoomin"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime400"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime500"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime600"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime700"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime800"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime900"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime1000"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime1250"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime1500"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime2000"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime2500"]->fill(InvM_ttbar_FromZprime);
        _h["Inclusive_InvM_FromZprime3000"]->fill(InvM_ttbar_FromZprime);

        _h["Inclusive_pToverInv_ttbar_FromZprime"]->fill(pT_over_InvM_ttbar_FromZprime);

      }
      else{
        _h["Inclusive_pT_ttbar_FromZprime"]->fill(-999);
        _h["Inclusive_mTop1_FromZprime"]->fill(-999);
        _h["Inclusive_mTop2_FromZprime"]->fill(-999);
        _h["Inclusive_mTop1_zoomin_FromZprime"]->fill(-999);
        _h["Inclusive_mTop2_zoomin_FromZprime"]->fill(-999);
        _h["Inclusive_dR_ttbar_FromZprime"]->fill(-999);
        _h["Inclusive_InvM_FromZprime"]->fill(-999);
        _h["Inclusive_InvM_FromZprime_zoomin"]->fill(-999);
        _h["Inclusive_InvM_FromZprime400"]->fill(-999);
        _h["Inclusive_InvM_FromZprime500"]->fill(-999);
        _h["Inclusive_InvM_FromZprime600"]->fill(-999);
        _h["Inclusive_InvM_FromZprime700"]->fill(-999);
        _h["Inclusive_InvM_FromZprime800"]->fill(-999);
        _h["Inclusive_InvM_FromZprime900"]->fill(-999);
        _h["Inclusive_InvM_FromZprime1000"]->fill(-999);
        _h["Inclusive_InvM_FromZprime1250"]->fill(-999);
        _h["Inclusive_InvM_FromZprime1500"]->fill(-999);
        _h["Inclusive_InvM_FromZprime2000"]->fill(-999);
        _h["Inclusive_InvM_FromZprime2500"]->fill(-999);
        _h["Inclusive_InvM_FromZprime3000"]->fill(-999);
        _h["Inclusive_pToverInv_ttbar_FromZprime"]->fill(-999);

      }

      if ( topCandsFromNonZprime.size() == 2 ){
        double pT_ttbar_FromNonZprime = (topCandsFromNonZprime.at(0).momentum() + topCandsFromNonZprime.at(1).momentum()).pT()/GeV;
        double dR_ttbar_FromNonZprime = fabs(deltaR(topCandsFromNonZprime.at(0),topCandsFromNonZprime.at(1)));
        double InvM_ttbar_FromNonZprime = ( topCandsFromNonZprime.at(0).momentum() + topCandsFromNonZprime.at(1).momentum() ).mass()/GeV;
        double pT_over_InvM_ttbar_FromNonZprime = pT_ttbar_FromNonZprime/InvM_ttbar_FromNonZprime;

        // std::cout << "pT_ttbar = " << pT_ttbar << std::endl;
        _h["Inclusive_pT_ttbar_FromNonZprime"]->fill(pT_ttbar_FromNonZprime);
        _h["Inclusive_mTop1_FromNonZprime"]->fill(topCandsFromNonZprime.at(0).mass());
        _h["Inclusive_mTop2_FromNonZprime"]->fill(topCandsFromNonZprime.at(1).mass());
        _h["Inclusive_mTop1_zoomin_FromNonZprime"]->fill(topCandsFromNonZprime.at(0).mass());
        _h["Inclusive_mTop2_zoomin_FromNonZprime"]->fill(topCandsFromNonZprime.at(1).mass());
        _h["Inclusive_dR_ttbar_FromNonZprime"]->fill(dR_ttbar_FromNonZprime);

        _h["Inclusive_InvM_FromNonZprime"]->fill(InvM_ttbar_FromNonZprime);
        _h["Inclusive_pToverInv_ttbar_FromNonZprime"]->fill(pT_over_InvM_ttbar_FromNonZprime);

      }
      else{
        _h["Inclusive_pT_ttbar_FromNonZprime"]->fill(-999);
        _h["Inclusive_mTop1_FromNonZprime"]->fill(-999);
        _h["Inclusive_mTop2_FromNonZprime"]->fill(-999);
        _h["Inclusive_mTop1_zoomin_FromNonZprime"]->fill(-999);
        _h["Inclusive_mTop2_zoomin_FromNonZprime"]->fill(-999);
        _h["Inclusive_dR_ttbar_FromNonZprime"]->fill(-999);

        _h["Inclusive_InvM_FromNonZprime"]->fill(-999);
        _h["Inclusive_pToverInv_ttbar_FromNonZprime"]->fill(-999);
      }

      if (debug){
        MSG_INFO( "Number of top quark : " << topCands.size());
        MSG_INFO( "Number of Zprime bosons:" << ZprimeCands.size());
        MSG_INFO( "Number of Top quark is from Zprime:" << topCandsFromZprime.size());
        MSG_INFO( "Number of Top quark is from Non-Zprime:" << topCandsFromNonZprime.size());
        MSG_INFO("#----------------DONE--------------#");
      }

      // particle level analysis
      Particles all_lepVec;
      Particles prompt_elVec,prompt_muVec,prompt_lepVec;
      Particles nonprompt_elVec,nonprompt_muVec,nonprompt_lepVec;

      for (const Particle & el: applyProjection<NonPromptFinalState>(event,"np_electrons").particlesByPt()){
        if(el.pT()/GeV > 7 && fabs(el.eta()) <2.8)
          { 
            all_lepVec.push_back(el);
            nonprompt_elVec.push_back(el);
            nonprompt_lepVec.push_back(el);
          }
        }
      for(const Particle &mu: applyProjection<NonPromptFinalState>(event,"np_muons").particlesByPt())
      {
        if(mu.pT()/GeV >7 && fabs(mu.eta()) <2.8)
          {
            all_lepVec.push_back(mu);
            nonprompt_muVec.push_back(mu);
            nonprompt_lepVec.push_back(mu);
          }
      }
      for (const Particle & el: applyProjection<PromptFinalState>(event,"electrons").particlesByPt())
      {
          if(el.pT()/GeV > 7 && fabs(el.eta()) <2.8)
          {
              all_lepVec.push_back(el);
              prompt_elVec.push_back(el);
              prompt_lepVec.push_back(el);
          }
      }
      for(const Particle &mu: applyProjection<PromptFinalState>(event,"muons").particlesByPt())
      {
          if(mu.pT()/GeV >7 && fabs(mu.eta()) <2.8)
          {
              all_lepVec.push_back(mu);
              prompt_muVec.push_back(mu);
              prompt_lepVec.push_back(mu);
          }
      }
      
      prompt_elVec = sortByPt(prompt_elVec);
      prompt_muVec = sortByPt(prompt_muVec);
      prompt_lepVec = sortByPt(prompt_lepVec);

      nonprompt_elVec = sortByPt(nonprompt_elVec);
      nonprompt_muVec = sortByPt(nonprompt_muVec);
      nonprompt_lepVec = sortByPt(nonprompt_lepVec);

      _h["Inclusive_nLep"]->fill(all_lepVec.size());
      _h["Inclusive_nLep_prompt"]->fill(prompt_lepVec.size());
      _h["Inclusive_nLep_nonprompt"]->fill(nonprompt_lepVec.size());

      if (prompt_lepVec.size() >= 1){
        _h["Inclusive_lep0Pt"]->fill(prompt_lepVec.at(0).pT()/GeV);
        _h["Inclusive_lep0Eta"]->fill(prompt_lepVec.at(0).eta());
        _h["Inclusive_lep0Phi"]->fill(prompt_lepVec.at(0).phi(MINUSPI_PLUSPI));
      }

      if (prompt_lepVec.size() >= 2){
        _h["Inclusive_lep1Pt"]->fill(prompt_lepVec.at(1).pT()/GeV);
        _h["Inclusive_lep1Eta"]->fill(prompt_lepVec.at(1).eta());
        _h["Inclusive_lep1Phi"]->fill(prompt_lepVec.at(1).phi(MINUSPI_PLUSPI));
      }

      if (prompt_lepVec.size() >= 3){
        _h["Inclusive_lep2Pt"]->fill(prompt_lepVec.at(2).pT()/GeV);
        _h["Inclusive_lep2Eta"]->fill(prompt_lepVec.at(2).eta());
        _h["Inclusive_lep2Phi"]->fill(prompt_lepVec.at(2).phi(MINUSPI_PLUSPI));
      }

      if (prompt_lepVec.size() >= 4){
        _h["Inclusive_lep3Pt"]->fill(prompt_lepVec.at(3).pT()/GeV);
        _h["Inclusive_lep3Eta"]->fill(prompt_lepVec.at(3).eta());
        _h["Inclusive_lep3Phi"]->fill(prompt_lepVec.at(3).phi(MINUSPI_PLUSPI));
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
  DECLARE_RIVET_PLUGIN(tttt_ttZp);

}
