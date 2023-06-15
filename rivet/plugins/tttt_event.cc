#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/TauFinder.hh"
#include "Rivet/Projections/HeavyHadrons.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/ChargedFinalState.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/IdentifiedFinalState.hh"
#include "Rivet/Projections/UnstableParticles.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/WFinder.hh"
#include "Rivet/AnalysisLoader.hh"

#include <numeric>
#include <functional>


namespace Rivet {
    bool debug = false;
    int countProngs(Particle mother) {
        int n_prongs = 0;
        for(Particle p : mother.children())
            if (p.charge3()!=0) ++n_prongs;
        return n_prongs;
    }



  class tttt_event: public Analysis {
  public:

    /// Minimal constructor
    tttt_event() : Analysis("tttt_event")
    {
    }

    /// Set up projections and book histograms
    void init() {
      FinalState lepfs;
      //Projection to find prompt electrons
      IdentifiedFinalState el_id(lepfs);
      el_id.acceptIdPair(PID::ELECTRON);
      PromptFinalState electrons(el_id);
      electrons.acceptTauDecays(true);
      declare(electrons,"electrons");

      declare(UnstableParticles(),"UFS");

      //Projection to find prompt muons
      IdentifiedFinalState mu_id(lepfs);
      mu_id.acceptIdPair(PID::MUON);
      PromptFinalState muons(mu_id);
      muons.acceptTauDecays(true);
      declare(muons,"muons");


      TauFinder tauhadronic(TauFinder::DecayMode::HADRONIC);
      declare(tauhadronic,"TauHadronic");

      declare(HeavyHadrons(Cuts::abseta < 5 && Cuts::pT > 5*GeV), "BCHadrons");

      const FinalState fs(Cuts::abseta < 2.5);
      declare(fs, "FS");
      FastJets jetfs(fs, FastJets::ANTIKT, 0.4, JetAlg::Muons::NONE, JetAlg::Invisibles::NONE);
      declare(jetfs, "Jets");
     // declare(FastJets(FinalState(Cuts::abseta < 2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
      //declare(FastJets(FinalState(), FastJets::ANTIKT, 0.4), "Jets");
      declare(MissingMomentum(FinalState(Cuts::abseta < 5 && Cuts::pT >0*GeV)),"MissingET");


      //Histogramming

      // Inclusive region
      book(_h["sumOfWeights"],"sumOfWeights",2,0,2);


      book(_h["Inclusive_nJets"],"Inclusive_nJets",15,-0.5,14.5);
      book(_h["Inclusive_HT"],"Inclusive_HT",15,0,3000);
      book(_h["Inclusive_HT_2"],"Inclusive_HT_2",30,0,6000);

      book(_h["Inclusive_HT_jets"],"Inclusive_HT_jets",15,0,3000);
      book(_h["Inclusive_HT_jets_2"],"Inclusive_HT_jets_2",30,0,6000);

      book(_h["Inclusive_nBjets"],"Inclusive_nBjets",7,-0.5,6.5);
      book(_h["Inclusive_nHadTau"],"Inclusive_nHadTau",4,-0.5,3.5);

      book(_h["Inclusive_jet0Pt"],"Inclusive_jet0Pt",20,0,600);
      book(_h["Inclusive_jet0Pt_2"],"Inclusive_jet0Pt_2",40,0,2000);
      book(_h["Inclusive_jet0Eta"],"Inclusive_jet0Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet0Phi"],"Inclusive_jet0Phi",16,-4,4);

      book(_h["Inclusive_jet1Pt"],"Inclusive_jet1Pt",20,0,450);
      book(_h["Inclusive_jet1Eta"],"Inclusive_jet1Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet1Phi"],"Inclusive_jet1Phi",16,-4,4);

      book(_h["Inclusive_jet2Pt"],"Inclusive_jet2Pt",20,0,250);
      book(_h["Inclusive_jet2Eta"],"Inclusive_jet2Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet2Phi"],"Inclusive_jet2Phi",16,-4,4);

      book(_h["Inclusive_jet3Pt"],"Inclusive_jet3Pt",20,0,150);
      book(_h["Inclusive_jet3Eta"],"Inclusive_jet3Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet3Phi"],"Inclusive_jet3Phi",16,-4,4);

      book(_h["Inclusive_jet4Pt"],"Inclusive_jet4Pt",20,0,120);
      book(_h["Inclusive_jet4Eta"],"Inclusive_jet4Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet4Phi"],"Inclusive_jet4Phi",16,-4,4);

      book(_h["Inclusive_jet5Pt"],"Inclusive_jet5Pt",20,0,90);
      book(_h["Inclusive_jet5Eta"],"Inclusive_jet5Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet5Phi"],"Inclusive_jet5Phi",16,-4,4);


      book(_h["Inclusive_lep0Pt"],"Inclusive_lep0Pt",20,0,300);
      book(_h["Inclusive_lep0Pt_2"],"Inclusive_lep0Pt_2",40,0,1200);
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


      // 15 GeV
      book(_h["Inclusive_lep0Pt_15GeV"],"Inclusive_lep0Pt_15GeV",20,0,300);
      book(_h["Inclusive_lep0Pt_15GeV_2"],"Inclusive_lep0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_lep0Eta_15GeV"],"Inclusive_lep0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep0Phi_15GeV"],"Inclusive_lep0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_lep1Pt_15GeV"],"Inclusive_lep1Pt_15GeV",20,0,150);
      book(_h["Inclusive_lep1Eta_15GeV"],"Inclusive_lep1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep1Phi_15GeV"],"Inclusive_lep1Phi_15GeV",16,-4,4);

      book(_h["Inclusive_lep2Pt_15GeV"],"Inclusive_lep2Pt_15GeV",20,0,100);
      book(_h["Inclusive_lep2Eta_15GeV"],"Inclusive_lep2Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep2Phi_15GeV"],"Inclusive_lep2Phi_15GeV",16,-4,4);

      book(_h["Inclusive_lep3Pt_15GeV"],"Inclusive_lep3Pt_15GeV",20,0,100);
      book(_h["Inclusive_lep3Eta_15GeV"],"Inclusive_lep3Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep3Phi_15GeV"],"Inclusive_lep3Phi_15GeV",16,-4,4);

      // electrons
      book(_h["Inclusive_e0Pt_15GeV"],"Inclusive_e0Pt_15GeV",20,0,300);
      book(_h["Inclusive_e0Pt_15GeV_2"],"Inclusive_e0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_e0Eta_15GeV"],"Inclusive_e0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e0Phi_15GeV"],"Inclusive_e0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_e1Pt_15GeV"],"Inclusive_e1Pt_15GeV",20,0,150);
      book(_h["Inclusive_e1Eta_15GeV"],"Inclusive_e1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e1Phi_15GeV"],"Inclusive_e1Phi_15GeV",16,-4,4);

      book(_h["Inclusive_e2Pt_15GeV"],"Inclusive_e2Pt_15GeV",20,0,100);
      book(_h["Inclusive_e2Eta_15GeV"],"Inclusive_e2Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e2Phi_15GeV"],"Inclusive_e2Phi_15GeV",16,-4,4);

      book(_h["Inclusive_e3Pt_15GeV"],"Inclusive_e3Pt_15GeV",20,0,100);
      book(_h["Inclusive_e3Eta_15GeV"],"Inclusive_e3Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e3Phi_15GeV"],"Inclusive_e3Phi_15GeV",16,-4,4);

      // muon
      book(_h["Inclusive_mu0Pt_15GeV"],"Inclusive_mu0Pt_15GeV",20,0,300);
      book(_h["Inclusive_mu0Pt_15GeV_2"],"Inclusive_mu0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_mu0Eta_15GeV"],"Inclusive_mu0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu0Phi_15GeV"],"Inclusive_mu0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_mu1Pt_15GeV"],"Inclusive_mu1Pt_15GeV",20,0,150);
      book(_h["Inclusive_mu1Eta_15GeV"],"Inclusive_mu1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu1Phi_15GeV"],"Inclusive_mu1Phi_15GeV",16,-4,4);

      book(_h["Inclusive_mu2Pt_15GeV"],"Inclusive_mu2Pt_15GeV",20,0,100);
      book(_h["Inclusive_mu2Eta_15GeV"],"Inclusive_mu2Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu2Phi_15GeV"],"Inclusive_mu2Phi_15GeV",16,-4,4);

      book(_h["Inclusive_mu3Pt_15GeV"],"Inclusive_mu3Pt_15GeV",20,0,100);
      book(_h["Inclusive_mu3Eta_15GeV"],"Inclusive_mu3Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu3Phi_15GeV"],"Inclusive_mu3Phi_15GeV",16,-4,4);

      // hadronic tau (15 GeV)
      book(_h["Inclusive_tau0Pt_15GeV"],"Inclusive_tau0Pt_15GeV",20,0,300);
      book(_h["Inclusive_tau0Pt_15GeV_2"],"Inclusive_tau0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_tau0Eta_15GeV"],"Inclusive_tau0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau0Phi_15GeV"],"Inclusive_tau0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_tau1Pt_15GeV"],"Inclusive_tau1Pt_15GeV",20,0,150);
      book(_h["Inclusive_tau1Eta_15GeV"],"Inclusive_tau1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau1Phi_15GeV"],"Inclusive_tau1Phi_15GeV",16,-4,4);

      book(_h["Inclusive_tau2Pt_15GeV"],"Inclusive_tau2Pt_15GeV",20,0,100);
      book(_h["Inclusive_tau2Eta_15GeV"],"Inclusive_tau2Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau2Phi_15GeV"],"Inclusive_tau2Phi_15GeV",16,-4,4);

      book(_h["Inclusive_tau3Pt_15GeV"],"Inclusive_tau3Pt_15GeV",20,0,100);
      book(_h["Inclusive_tau3Eta_15GeV"],"Inclusive_tau3Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau3Phi_15GeV"],"Inclusive_tau3Phi_15GeV",16,-4,4);

      // hadronic tau (25 GeV)
      book(_h["Inclusive_tau0Pt_25GeV"],"Inclusive_tau0Pt_25GeV",20,0,300);
      book(_h["Inclusive_tau0Pt_25GeV_2"],"Inclusive_tau0Pt_25GeV_2",40,0,1200);
      book(_h["Inclusive_tau0Eta_25GeV"],"Inclusive_tau0Eta_25GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau0Phi_25GeV"],"Inclusive_tau0Phi_25GeV",16,-4,4);

      book(_h["Inclusive_tau1Pt_25GeV"],"Inclusive_tau1Pt_25GeV",20,0,150);
      book(_h["Inclusive_tau1Eta_25GeV"],"Inclusive_tau1Eta_25GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau1Phi_25GeV"],"Inclusive_tau1Phi_25GeV",16,-4,4);

      book(_h["Inclusive_tau2Pt_25GeV"],"Inclusive_tau2Pt_25GeV",20,0,100);
      book(_h["Inclusive_tau2Eta_25GeV"],"Inclusive_tau2Eta_25GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau2Phi_25GeV"],"Inclusive_tau2Phi_25GeV",16,-4,4);

      book(_h["Inclusive_tau3Pt_25GeV"],"Inclusive_tau3Pt_25GeV",20,0,100);
      book(_h["Inclusive_tau3Eta_25GeV"],"Inclusive_tau3Eta_25GeV",10,-2.5,2.5);
      book(_h["Inclusive_tau3Phi_25GeV"],"Inclusive_tau3Phi_25GeV",16,-4,4);



      book(_h["Inclusive_entries"],"Inclusive_entries",3,-0.5,3.5);



     book(_h["2lSS3l_nJets"],"2lSS3l_nJets",15,-0.5,14.5);
     book(_h["2lSS3l_HT"],"2lSS3l_HT",15,0,3000);
     book(_h["2lSS3l_HT_jets"],"2lSS3l_HT_jets",15,0,3000);
     book(_h["2lSS3l_nBjets"],"2lSS3l_nBjets",7,-0.5,6.5);
     book(_h["2lSS3l_lep0Pt"],"2lSS3l_lep0Pt",20,0,300);
     book(_h["2lSS3l_lep0Eta"],"2lSS3l_lep0Eta",20,-2.5,2.5);
     book(_h["2lSS3l_lepJetMinDR"],"2lSS3l_lepJetMinDR",5,0,0.5);
     book(_h["2lSS3l_DR_lep01"],"2lSS3l_DR_lep01",10,0,2*M_PI);
     book(_h["2lSS3l_DEta_lep01"],"2lSS3l_DEta_lep01",10,0,5);
     book(_h["2lSS3l_DPhi_lep01"],"2lSS3l_DPhi_lep01",10,0,4);
     book(_h["2lSS3l_jet0Pt"],"2lSS3l_jet0Pt",20,0,600);
     book(_h["2lSS3l_jet0Eta"],"2lSS3l_jet0Eta",10,-2.5,2.5);
     book(_h["2lSS3l_bjet0Pt"],"2lSS3l_bjet0Pt",20,0,400);
     book(_h["2lSS3l_entries"],"2lSS3l_entries",3,-0.5,3.5);

    book(_h["2lSS3l_HT_2"],"2lSS3l_HT_2",30,0,6000);
    book(_h["2lSS3l_HT_jets_2"],"2lSS3l_HT_jets_2",30,0,6000);
    book(_h["2lSS3l_jet0Pt_2"],"2lSS3l_jet0Pt_2",40,0,2000);
    book(_h["2lSS3l_lep0Pt_2"],"2lSS3l_lep0Pt_2",40,0,1200);



     book(_h["2lSS_nJets"],"2lSS_nJets",15,-0.5,14.5);
     book(_h["2lSS_HT"],"2lSS_HT",15,0,3000);
     book(_h["2lSS_HT_jets"],"2lSS_HT_jets",15,0,3000);
     book(_h["2lSS_nBjets"],"2lSS_nBjets",7,-0.5,6.5);
     book(_h["2lSS_lep0Pt"],"2lSS_lep0Pt",20,0,300);
     book(_h["2lSS_lep0Eta"],"2lSS_lep0Eta",20,-2.5,2.5);
     book(_h["2lSS_lepJetMinDR"],"2lSS_lepJetMinDR",5,0,0.5);
     book(_h["2lSS_DR_lep01"],"2lSS_DR_lep01",10,0,2*M_PI);
     book(_h["2lSS_DEta_lep01"],"2lSS_DEta_lep01",10,0,5);
     book(_h["2lSS_DPhi_lep01"],"2lSS_DPhi_lep01",10,0,4);
     book(_h["2lSS_jet0Pt"],"2lSS_jet0Pt",20,0,600);
     book(_h["2lSS_jet0Eta"],"2lSS_jet0Eta",10,-2.5,2.5);
     book(_h["2lSS_bjet0Pt"],"2lSS_bjet0Pt",20,0,400);
     book(_h["2lSS_entries"],"2lSS_entries",3,-0.5,3.5);

    book(_h["2lSS_HT_2"],"2lSS_HT_2",30,0,6000);
    book(_h["2lSS_HT_jets_2"],"2lSS_HT_jets_2",30,0,6000);
    book(_h["2lSS_jet0Pt_2"],"2lSS_jet0Pt_2",40,0,2000);
    book(_h["2lSS_lep0Pt_2"],"2lSS_lep0Pt_2",40,0,1200);



     book(_h["2lSS_1b4j_nJets"],"2lSS_1b4j_nJets",15,-0.5,14.5);
     book(_h["2lSS_1b4j_HT"],"2lSS_1b4j_HT",15,0,3000);
     book(_h["2lSS_1b4j_HT_jets"],"2lSS_1b4j_HT_jets",15,0,3000);
     book(_h["2lSS_1b4j_nBjets"],"2lSS_1b4j_nBjets",7,-0.5,6.5);
     book(_h["2lSS_1b4j_bjet0Pt"],"2lSS_1b4j_bjet0Pt",20,0,400);
     book(_h["2lSS_1b4j_lep0Pt"],"2lSS_1b4j_lep0Pt",20,0,300);
     book(_h["2lSS_1b4j_lep0Eta"],"2lSS_1b4j_lep0Eta",20,-2.5,2.5);
     book(_h["2lSS_1b4j_lepJetMinDR"],"2lSS_1b4j_lepJetMinDR",5,0,0.5);
     book(_h["2lSS_1b4j_DR_lep01"],"2lSS_1b4j_DR_lep01",10,0,2*M_PI);
     book(_h["2lSS_1b4j_DEta_lep01"],"2lSS_1b4j_DEta_lep01",10,0,5);
     book(_h["2lSS_1b4j_DPhi_lep01"],"2lSS_1b4j_DPhi_lep01",10,0,4);
     book(_h["2lSS_1b4j_jet0Pt"],"2lSS_1b4j_jet0Pt",20,0,600);
     book(_h["2lSS_1b4j_jet0Eta"],"2lSS_1b4j_jet0Eta",10,-2.5,2.5);
     book(_h["2lSS_1b4j_entries"],"2lSS_1b4j_entries",3,-0.5,3.5);

    book(_h["2lSS_1b4j_HT_2"],"2lSS_1b4j_HT_2",30,0,6000);
    book(_h["2lSS_1b4j_HT_jets_2"],"2lSS_1b4j_HT_jets_2",30,0,6000);
    book(_h["2lSS_1b4j_jet0Pt_2"],"2lSS_1b4j_jet0Pt_2",40,0,2000);
    book(_h["2lSS_1b4j_lep0Pt_2"],"2lSS_1b4j_lep0Pt_2",40,0,1200);



     book(_h["3l_nJets"],"3l_nJets",15,-0.5,14.5);
     book(_h["3l_HT"],"3l_HT",15,0,3000);
     book(_h["3l_HT_jets"],"3l_HT_jets",15,0,3000);
     book(_h["3l_nBjets"],"3l_nBjets",7,-0.5,6.5);
     book(_h["3l_lep0Pt"],"3l_lep0Pt",20,0,300);
     book(_h["3l_lep0Eta"],"3l_lep0Eta",20,-2.5,2.5);
     book(_h["3l_lepJetMinDR"],"3l_lepJetMinDR",5,0,0.5);
     book(_h["3l_DR_lep01"],"3l_DR_lep01",10,0,2*M_PI);
     book(_h["3l_DEta_lep01"],"3l_DEta_lep01",10,0,5);
     book(_h["3l_DPhi_lep01"],"3l_DPhi_lep01",10,0,4);
     book(_h["3l_jet0Pt"],"3l_jet0Pt",20,0,600);
     book(_h["3l_jet0Eta"],"3l_jet0Eta",10,-2.5,2.5);
     book(_h["3l_bjet0Pt"],"3l_bjet0Pt",20,0,400);
     book(_h["3l_entries"],"3l_entries",3,-0.5,3.5);

    book(_h["3l_HT_2"],"3l_HT_2",30,0,6000);
    book(_h["3l_HT_jets_2"],"3l_HT_jets_2",30,0,6000);
    book(_h["3l_jet0Pt_2"],"3l_jet0Pt_2",40,0,2000);
    book(_h["3l_lep0Pt_2"],"3l_lep0Pt_2",40,0,1200);



     book(_h["3l_1b2j_nJets"],"3l_1b2j_nJets",15,-0.5,14.5);
     book(_h["3l_1b2j_HT"],"3l_1b2j_HT",15,0,3000);
     book(_h["3l_1b2j_HT_jets"],"3l_1b2j_HT_jets",15,0,3000);
     book(_h["3l_1b2j_nBjets"],"3l_1b2j_nBjets",7,-0.5,6.5);
     book(_h["3l_1b2j_bjet0Pt"],"3l_1b2j_bjet0Pt",20,0,400);
     book(_h["3l_1b2j_lep0Pt"],"3l_1b2j_lep0Pt",20,0,300);
     book(_h["3l_1b2j_lep0Eta"],"3l_1b2j_lep0Eta",20,-2.5,2.5);
     book(_h["3l_1b2j_lepJetMinDR"],"3l_1b2j_lepJetMinDR",5,0,0.5);
     book(_h["3l_1b2j_DR_lep01"],"3l_1b2j_DR_lep01",10,0,2*M_PI);
     book(_h["3l_1b2j_DEta_lep01"],"3l_1b2j_DEta_lep01",10,0,5);
     book(_h["3l_1b2j_DPhi_lep01"],"3l_1b2j_DPhi_lep01",10,0,4);
     book(_h["3l_1b2j_jet0Pt"],"3l_1b2j_jet0Pt",20,0,600);
     book(_h["3l_1b2j_jet0Eta"],"3l_1b2j_jet0Eta",10,-2.5,2.5);
     book(_h["3l_1b2j_entries"],"3l_1b2j_entries",3,-0.5,3.5);

    book(_h["3l_1b2j_HT_2"],"3l_1b2j_HT_2",30,0,6000);
    book(_h["3l_1b2j_HT_jets_2"],"3l_1b2j_HT_jets_2",30,0,6000);
    book(_h["3l_1b2j_jet0Pt_2"],"3l_1b2j_jet0Pt_2",40,0,2000);
    book(_h["3l_1b2j_lep0Pt_2"],"3l_1b2j_lep0Pt_2",40,0,1200);






     book(_h["BaselineSR_nJets"],"BaselineSR_nJets",6,5.5,11.5);
     book(_h["BaselineSR_nBjets"],"BaselineSR_nBjets",5,1.5,6.5);

     book(_h["BaselineSR_HT_1"],"BaselineSR_HT_1",15,0,1500);
     book(_h["BaselineSR_HT_2"],"BaselineSR_HT_2",15,0,3000);
     book(_h["BaselineSR_HT_3"],"BaselineSR_HT_3",30,0,6000);

     book(_h["BaselineSR_HT_jets_1"],"BaselineSR_HT_jets_1",15,0,1500);
     book(_h["BaselineSR_HT_jets_2"],"BaselineSR_HT_jets_2",15,0,3000);
     book(_h["BaselineSR_HT_jets_3"],"BaselineSR_HT_jets_3",30,0,6000);

     book(_h["BaselineSR_lep0Pt_1"],"BaselineSR_lep0Pt_1",20,0,300);
     book(_h["BaselineSR_lep0Pt_2"],"BaselineSR_lep0Pt_2",40,0,1200);
     book(_h["BaselineSR_lep0Eta"],"BaselineSR_lep0Eta",20,-2.5,2.5);

     book(_h["BaselineSR_lep1Pt_1"],"BaselineSR_lep1Pt_1",15,0,150);
     book(_h["BaselineSR_lep1Pt_2"],"BaselineSR_lep1Pt_2",20,0,300);
     book(_h["BaselineSR_lep1Eta"],"BaselineSR_lep1Eta",20,-2.5,2.5);



     book(_h["BaselineSR_lepJetMinDR"],"BaselineSR_lepJetMinDR",5,0,0.5);
     book(_h["BaselineSR_DR_lep01"],"BaselineSR_DR_lep01",10,0,2*M_PI);
     book(_h["BaselineSR_DEta_lep01"],"BaselineSR_DEta_lep01",10,0,5);
     book(_h["BaselineSR_DPhi_lep01"],"BaselineSR_DPhi_lep01",10,0,4);

     book(_h["BaselineSR_jet0Pt_1"],"BaselineSR_jet0Pt_1",20,0,600);
     book(_h["BaselineSR_jet0Pt_2"],"BaselineSR_jet0Pt_2",40,0,2000);
     book(_h["BaselineSR_jet0Eta"],"BaselineSR_jet0Eta",10,-2.5,2.5);

     book(_h["BaselineSR_jet1Pt_1"],"BaselineSR_jet1Pt_1",20,0,600);
     book(_h["BaselineSR_jet1Pt_2"],"BaselineSR_jet1Pt_2",40,0,2000);
     book(_h["BaselineSR_jet1Eta"],"BaselineSR_jet1Eta",10,-2.5,2.5);



     book(_h["BaselineSR_bjet0Pt"],"BaselineSR_bjet0Pt",20,0,400);
     book(_h["BaselineSR_bjet1Pt"],"BaselineSR_bjet1Pt",20,0,300);

     book(_h["BaselineSR_entries"],"BaselineSR_entries",3,-0.5,3.5);


     book(_h["BaselineSR_deltaR_ll_min"],"BaselineSR_deltaR_ll_min",8,0,4);
     book(_h["BaselineSR_deltaR_ll_sum"],"BaselineSR_deltaR_ll_sum",12,0,8);
     book(_h["BaselineSR_deltaR_lb_max"],"BaselineSR_deltaR_lb_max",10,2,4.5);
     book(_h["BaselineSR_deltaR_bj_min"],"BaselineSR_deltaR_bj_min",12,0,2);

    }


    void analyze(const Event& event) {
      // Use the "LFS" projection to require at least one hard charged
      // lepton. This is an experimental signature for the leptonically decaying
      // W. This helps to reduce pure QCD backgrounds.

    //   const MissingMomentum& met = applyProjection<MissingMomentum>(event, "MissingET");
    //   const double event_met	 = met.vectorEt().mod();

      /*if(zeeFinder.bosons().size()==0 && zmumuFinder.bosons().size()==0)
      {
          MSG_INFO("ZeeFinder size: "<<zeeFinder.size());
          MSG_INFO("ZmumuFinder size: "<<zmumuFinder.size());
          MSG_INFO("Veto Event");
          vetoEvent;
      }*/

      //
      Particles eMinusFromTaus, ePlusFromTaus, muonsFromTaus, antiMuonsFromTaus;
      for(const Particle& tau : apply<UnstableParticles>(event, "UFS").particles(Cuts::abspid==PID::TAU))
      {
          for(const Particle & p : tau.children())
          {
              if (p.pid()  == PID::EMINUS)
              {
                 eMinusFromTaus.push_back(p);
              }
              else if (p.pid() == PID::EPLUS)
              {
                 ePlusFromTaus.push_back(p);
              }
              else if (p.pid() == PID::MUON)
              {
                 muonsFromTaus.push_back(p);
              }
              else if (p.pid() == PID::ANTIMUON)
              {
                 antiMuonsFromTaus.push_back(p);
              }
          }
      }


      Particles elVec,muVec,tauVec,lepVec;
      Particles elVec_15GeV,muVec_15GeV,tauVec_15GeV,lepVec_15GeV;

      Particles Inclusive_elVec,Inclusive_muVec, Inclusive_tauVec, Inclusive_allVec;
      //Count the total number of leptons

      for (const Particle & el: applyProjection<PromptFinalState>(event,"electrons").particlesByPt())
      {
          Inclusive_elVec.push_back(el);
          Inclusive_allVec.push_back(el);
          if(el.pT()/GeV > 10 && fabs(el.eta()) <2.5)
          {
              elVec.push_back(el);
      	      lepVec.push_back(el);

              if(el.pT()/GeV > 15){
                elVec_15GeV.push_back(el);
        	      lepVec_15GeV.push_back(el);
              }

          }
      }
      for(const Particle &mu: applyProjection<PromptFinalState>(event,"muons").particlesByPt())
      {
          Inclusive_muVec.push_back(mu);
          Inclusive_allVec.push_back(mu);
          if(mu.pT()/GeV >10 && fabs(mu.eta()) <2.5)
          {
              muVec.push_back(mu);
       	      lepVec.push_back(mu);

              if(mu.pT()/GeV >15){
                muVec_15GeV.push_back(mu);
         	      lepVec_15GeV.push_back(mu);
              }
          }
      }

      elVec = sortByPt(elVec);
      muVec = sortByPt(muVec);
      lepVec = sortByPt(lepVec);

      elVec_15GeV = sortByPt(elVec_15GeV);
      muVec_15GeV = sortByPt(muVec_15GeV);
      lepVec_15GeV = sortByPt(lepVec_15GeV);


      Inclusive_elVec  = sortByPt(Inclusive_elVec);
      Inclusive_muVec  = sortByPt(Inclusive_muVec);
      Inclusive_allVec = sortByPt(Inclusive_allVec);

      unsigned int nLep = lepVec.size();
      int elqsum=0;
      int muqsum=0;

      for(const Particle& el: elVec)
      {
          elqsum += el.charge();
      }
      for(const Particle &mu: muVec)
      {
          muqsum += mu.charge();
      }



      Jets alljets;
      for(const Jet &jet : applyProjection<FastJets>(event, "Jets").jetsByPt(Cuts::pT> 25*GeV))
      {

         // alljets.push_back(jet);
          if(fabs(jet.eta()) < 2.5 )
          {
              alljets.push_back(jet);
          }
      }
      // MSG_INFO("alljets = " << alljets.size() << ", alljets_validation = "<< alljets_validation.size() );


      // Identify b-jets
      const Particles bhadrons = sortByPt(applyProjection<HeavyHadrons>(event, "BCHadrons").bHadrons());

      Jets bjets, ljets;
      for(const Jet& jet: alljets)
      {
          if(jet.bTagged())
          {
              bjets.push_back(jet);
          }
          else
          {
              ljets.push_back(jet);
          }
     }

     // MSG_INFO("bjets = " << bjets.size() << ", bjets_validation = "<< bjets_validation.size() );
     // MSG_INFO("ljets = " << ljets.size() << ", ljets_validation = "<< ljets_validation.size() );


     alljets    =   sortByPt(alljets);
     bjets      =   sortByPt(bjets);
     ljets      =   sortByPt(ljets);


     // Include Hadronic tau in the jet collection
     std::vector<FourMomentum> alljets_withHadTau, ljets_withHadTau;
     alljets_withHadTau = alljets;
     ljets_withHadTau = ljets;

      const TauFinder &tauhad = applyProjection<TauFinder>(event,"TauHadronic");
      for(const Particle &tau: tauhad.taus())
      {
          Inclusive_tauVec.push_back(tau);
          Inclusive_allVec.push_back(tau);

          if(tau.pT()/GeV >15 && fabs(tau.eta()) < 2.5 ){
            int nProng = countProngs(tau);
            if(nProng ==2 || nProng ==3)
            {
              tauVec_15GeV.push_back(tau);
            }
          }

          if(tau.pT()/GeV >25 && fabs(tau.eta()) < 2.5 )
          {
            int nProng = countProngs(tau);
            if(nProng ==2 || nProng ==3)
            {
              tauVec.push_back(tau);
              alljets_withHadTau.push_back(tau);
              ljets_withHadTau.push_back(tau);
            }
          }
      }

      tauVec= sortByPt(tauVec);
      tauVec_15GeV = sortByPt(tauVec_15GeV);
      Inclusive_tauVec = sortByPt(Inclusive_tauVec);

     alljets_withHadTau  =   sortByPt(alljets_withHadTau);
     ljets_withHadTau    =   sortByPt(ljets_withHadTau);

     // MSG_INFO("tauVec = " << tauVec.size()  );
     // MSG_INFO("alljets = " << alljets.size() << ", alljets_withHadTau = "<< alljets_withHadTau.size() );
     // MSG_INFO("ljets = " << ljets.size() << ", ljets_withHadTau = "<< ljets_withHadTau.size() );


      double ht_jets = 0.0;
      double ht = 0.0;
      for(const FourMomentum& j: alljets_withHadTau) {
        ht_jets += j.pT();
        ht += j.pT();
      }
      for(const Particle & lep: lepVec){
        ht += lep.pT();
      }


      float min_lj_deltaR=100;
      for(const FourMomentum& jet: alljets_withHadTau){ // Use alljets+Hadronic Tau
          for(const Particle & part: lepVec){
     	     if(min_lj_deltaR > fabs(deltaR(jet,part))) {min_lj_deltaR = fabs(deltaR(jet,part)); }
       	 }
      }


     if (debug){ // to check the lepton from tau is included in the inclusive electron/muon collections -
       // conclusion: yes, ele/mu collections include the e/m from leptonic tau
       Inclusive_elVec = sortByPt(Inclusive_elVec);
       Inclusive_muVec = sortByPt(Inclusive_muVec);
       eMinusFromTaus = sortByPt(eMinusFromTaus);
       ePlusFromTaus = sortByPt(ePlusFromTaus);

       MSG_INFO("All electron = " << Inclusive_elVec.size() << ", All muon = "<< Inclusive_muVec.size());
       MSG_INFO("electron from tau = " << eMinusFromTaus.size()+ePlusFromTaus.size() << ", muon from tau  = "<< muonsFromTaus.size()+antiMuonsFromTaus.size());
       MSG_INFO("After 10GeV, abs(eta) < 2.5");
       MSG_INFO(">> lepton numer = " << lepVec.size() << " , electron number = " << elVec.size() << " , muon number " << muVec.size() << " , tau number = " << tauVec.size());

       if ( (Inclusive_elVec.size() == eMinusFromTaus.size()+ePlusFromTaus.size()) && (Inclusive_elVec.size()>0) ){
         float ele0 = Inclusive_elVec.at(0).pT()/GeV;

         float tmp1 = 0;
         float tmp2 = 0;
         float ele_tau0 = 0;

         if (eMinusFromTaus.size() > 0) {
            tmp1 = eMinusFromTaus.at(0).pT()/GeV;
         }

         if (ePlusFromTaus.size() > 0) {
            tmp2 = ePlusFromTaus.at(0).pT()/GeV;
         }

         if (tmp1 > tmp2){
          ele_tau0 = tmp1;
         }
         else if (tmp2 > tmp1){
          ele_tau0 = tmp2;
         }

         MSG_INFO("electron 0 pt = " << ele0 << ", electron 0 from tau pt =  "<< ele_tau0);
       }
     }

      _h["Inclusive_nJets"]->fill(alljets_withHadTau.size());
      _h["Inclusive_HT"]->fill(ht);
      _h["Inclusive_HT_jets"]->fill(ht_jets);
      _h["Inclusive_nBjets"]->fill(bjets.size());
      _h["Inclusive_nHadTau"]->fill(tauVec.size());
      _h["Inclusive_entries"]->fill(1,1);
      _h["Inclusive_HT_2"]->fill(ht);
      _h["Inclusive_HT_jets_2"]->fill(ht_jets);


      if (alljets_withHadTau.size() >= 1){
        _h["Inclusive_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
        _h["Inclusive_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);
        _h["Inclusive_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());
        _h["Inclusive_jet0Phi"]->fill(alljets_withHadTau.at(0).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 2){
        _h["Inclusive_jet1Pt"]->fill(alljets_withHadTau.at(1).pT()/GeV);
        _h["Inclusive_jet1Eta"]->fill(alljets_withHadTau.at(1).eta());
        _h["Inclusive_jet1Phi"]->fill(alljets_withHadTau.at(1).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 3){
        _h["Inclusive_jet2Pt"]->fill(alljets_withHadTau.at(2).pT()/GeV);
        _h["Inclusive_jet2Eta"]->fill(alljets_withHadTau.at(2).eta());
        _h["Inclusive_jet2Phi"]->fill(alljets_withHadTau.at(2).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 4){
        _h["Inclusive_jet3Pt"]->fill(alljets_withHadTau.at(3).pT()/GeV);
        _h["Inclusive_jet3Eta"]->fill(alljets_withHadTau.at(3).eta());
        _h["Inclusive_jet3Phi"]->fill(alljets_withHadTau.at(3).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 5){
        _h["Inclusive_jet4Pt"]->fill(alljets_withHadTau.at(4).pT()/GeV);
        _h["Inclusive_jet4Eta"]->fill(alljets_withHadTau.at(4).eta());
        _h["Inclusive_jet4Phi"]->fill(alljets_withHadTau.at(4).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 6){
        _h["Inclusive_jet5Pt"]->fill(alljets_withHadTau.at(5).pT()/GeV);
        _h["Inclusive_jet5Eta"]->fill(alljets_withHadTau.at(5).eta());
        _h["Inclusive_jet5Phi"]->fill(alljets_withHadTau.at(5).phi(MINUSPI_PLUSPI));
      }



      if (lepVec.size() >= 1){
        _h["Inclusive_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
        _h["Inclusive_lep0Eta"]->fill(lepVec.at(0).eta());
        _h["Inclusive_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);
        _h["Inclusive_lep0Phi"]->fill(lepVec.at(0).phi(MINUSPI_PLUSPI));
      }

      if (lepVec.size() >= 2){
        _h["Inclusive_lep1Pt"]->fill(lepVec.at(1).pT()/GeV);
        _h["Inclusive_lep1Eta"]->fill(lepVec.at(1).eta());
        _h["Inclusive_lep1Phi"]->fill(lepVec.at(1).phi(MINUSPI_PLUSPI));
      }

      if (lepVec.size() >= 3){
        _h["Inclusive_lep2Pt"]->fill(lepVec.at(2).pT()/GeV);
        _h["Inclusive_lep2Eta"]->fill(lepVec.at(2).eta());
        _h["Inclusive_lep2Phi"]->fill(lepVec.at(2).phi(MINUSPI_PLUSPI));
      }

      if (lepVec.size() >= 4){
        _h["Inclusive_lep3Pt"]->fill(lepVec.at(3).pT()/GeV);
        _h["Inclusive_lep3Eta"]->fill(lepVec.at(3).eta());
        _h["Inclusive_lep3Phi"]->fill(lepVec.at(3).phi(MINUSPI_PLUSPI));
      }


      // Lepton 15 GeV
      if (lepVec_15GeV.size() >= 1){
        _h["Inclusive_lep0Pt_15GeV"]->fill(lepVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_lep0Eta_15GeV"]->fill(lepVec_15GeV.at(0).eta());
        _h["Inclusive_lep0Pt_15GeV_2"]->fill(lepVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_lep0Phi_15GeV"]->fill(lepVec_15GeV.at(0).phi(MINUSPI_PLUSPI));
      }

      if (lepVec_15GeV.size() >= 2){
        _h["Inclusive_lep1Pt_15GeV"]->fill(lepVec_15GeV.at(1).pT()/GeV);
        _h["Inclusive_lep1Eta_15GeV"]->fill(lepVec_15GeV.at(1).eta());
        _h["Inclusive_lep1Phi_15GeV"]->fill(lepVec_15GeV.at(1).phi(MINUSPI_PLUSPI));
      }

      if (lepVec_15GeV.size() >= 3){
        _h["Inclusive_lep2Pt_15GeV"]->fill(lepVec_15GeV.at(2).pT()/GeV);
        _h["Inclusive_lep2Eta_15GeV"]->fill(lepVec_15GeV.at(2).eta());
        _h["Inclusive_lep2Phi_15GeV"]->fill(lepVec_15GeV.at(2).phi(MINUSPI_PLUSPI));
      }

      if (lepVec_15GeV.size() >= 4){
        _h["Inclusive_lep3Pt_15GeV"]->fill(lepVec_15GeV.at(3).pT()/GeV);
        _h["Inclusive_lep3Eta_15GeV"]->fill(lepVec_15GeV.at(3).eta());
        _h["Inclusive_lep3Phi_15GeV"]->fill(lepVec_15GeV.at(3).phi(MINUSPI_PLUSPI));
      }


      // Electron 15 GeV
      if (elVec_15GeV.size() >= 1){
        _h["Inclusive_e0Pt_15GeV"]->fill(elVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_e0Eta_15GeV"]->fill(elVec_15GeV.at(0).eta());
        _h["Inclusive_e0Pt_15GeV_2"]->fill(elVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_e0Phi_15GeV"]->fill(elVec_15GeV.at(0).phi(MINUSPI_PLUSPI));
      }

      if (elVec_15GeV.size() >= 2){
        _h["Inclusive_e1Pt_15GeV"]->fill(elVec_15GeV.at(1).pT()/GeV);
        _h["Inclusive_e1Eta_15GeV"]->fill(elVec_15GeV.at(1).eta());
        _h["Inclusive_e1Phi_15GeV"]->fill(elVec_15GeV.at(1).phi(MINUSPI_PLUSPI));
      }

      if (elVec_15GeV.size() >= 3){
        _h["Inclusive_e2Pt_15GeV"]->fill(elVec_15GeV.at(2).pT()/GeV);
        _h["Inclusive_e2Eta_15GeV"]->fill(elVec_15GeV.at(2).eta());
        _h["Inclusive_e2Phi_15GeV"]->fill(elVec_15GeV.at(2).phi(MINUSPI_PLUSPI));
      }

      if (elVec_15GeV.size() >= 4){
        _h["Inclusive_e3Pt_15GeV"]->fill(elVec_15GeV.at(3).pT()/GeV);
        _h["Inclusive_e3Eta_15GeV"]->fill(elVec_15GeV.at(3).eta());
        _h["Inclusive_e3Phi_15GeV"]->fill(elVec_15GeV.at(3).phi(MINUSPI_PLUSPI));
      }

      // Muon 15 GeV
      if (muVec_15GeV.size() >= 1){
        _h["Inclusive_mu0Pt_15GeV"]->fill(muVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_mu0Eta_15GeV"]->fill(muVec_15GeV.at(0).eta());
        _h["Inclusive_mu0Pt_15GeV_2"]->fill(muVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_mu0Phi_15GeV"]->fill(muVec_15GeV.at(0).phi(MINUSPI_PLUSPI));
      }

      if (muVec_15GeV.size() >= 2){
        _h["Inclusive_mu1Pt_15GeV"]->fill(muVec_15GeV.at(1).pT()/GeV);
        _h["Inclusive_mu1Eta_15GeV"]->fill(muVec_15GeV.at(1).eta());
        _h["Inclusive_mu1Phi_15GeV"]->fill(muVec_15GeV.at(1).phi(MINUSPI_PLUSPI));
      }

      if (muVec_15GeV.size() >= 3){
        _h["Inclusive_mu2Pt_15GeV"]->fill(muVec_15GeV.at(2).pT()/GeV);
        _h["Inclusive_mu2Eta_15GeV"]->fill(muVec_15GeV.at(2).eta());
        _h["Inclusive_mu2Phi_15GeV"]->fill(muVec_15GeV.at(2).phi(MINUSPI_PLUSPI));
      }

      if (muVec_15GeV.size() >= 4){
        _h["Inclusive_mu3Pt_15GeV"]->fill(muVec_15GeV.at(3).pT()/GeV);
        _h["Inclusive_mu3Eta_15GeV"]->fill(muVec_15GeV.at(3).eta());
        _h["Inclusive_mu3Phi_15GeV"]->fill(muVec_15GeV.at(3).phi(MINUSPI_PLUSPI));
      }

      // Tau 15 GeV
      if (tauVec_15GeV.size() >= 1){
        _h["Inclusive_tau0Pt_15GeV"]->fill(tauVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_tau0Eta_15GeV"]->fill(tauVec_15GeV.at(0).eta());
        _h["Inclusive_tau0Pt_15GeV_2"]->fill(tauVec_15GeV.at(0).pT()/GeV);
        _h["Inclusive_tau0Phi_15GeV"]->fill(tauVec_15GeV.at(0).phi(MINUSPI_PLUSPI));
      }

      if (tauVec_15GeV.size() >= 2){
        _h["Inclusive_tau1Pt_15GeV"]->fill(tauVec_15GeV.at(1).pT()/GeV);
        _h["Inclusive_tau1Eta_15GeV"]->fill(tauVec_15GeV.at(1).eta());
        _h["Inclusive_tau1Phi_15GeV"]->fill(tauVec_15GeV.at(1).phi(MINUSPI_PLUSPI));
      }

      if (tauVec_15GeV.size() >= 3){
        _h["Inclusive_tau2Pt_15GeV"]->fill(tauVec_15GeV.at(2).pT()/GeV);
        _h["Inclusive_tau2Eta_15GeV"]->fill(tauVec_15GeV.at(2).eta());
        _h["Inclusive_tau2Phi_15GeV"]->fill(tauVec_15GeV.at(2).phi(MINUSPI_PLUSPI));
      }

      if (tauVec_15GeV.size() >= 4){
        _h["Inclusive_tau3Pt_15GeV"]->fill(tauVec_15GeV.at(3).pT()/GeV);
        _h["Inclusive_tau3Eta_15GeV"]->fill(tauVec_15GeV.at(3).eta());
        _h["Inclusive_tau3Phi_15GeV"]->fill(tauVec_15GeV.at(3).phi(MINUSPI_PLUSPI));
      }


      // Tau 25 GeV
      if (tauVec.size() >= 1){
        _h["Inclusive_tau0Pt_25GeV"]->fill(tauVec.at(0).pT()/GeV);
        _h["Inclusive_tau0Eta_25GeV"]->fill(tauVec.at(0).eta());
        _h["Inclusive_tau0Pt_25GeV_2"]->fill(tauVec.at(0).pT()/GeV);
        _h["Inclusive_tau0Phi_25GeV"]->fill(tauVec.at(0).phi(MINUSPI_PLUSPI));
      }

      if (tauVec.size() >= 2){
        _h["Inclusive_tau1Pt_25GeV"]->fill(tauVec.at(1).pT()/GeV);
        _h["Inclusive_tau1Eta_25GeV"]->fill(tauVec.at(1).eta());
        _h["Inclusive_tau1Phi_25GeV"]->fill(tauVec.at(1).phi(MINUSPI_PLUSPI));
      }

      if (tauVec.size() >= 3){
        _h["Inclusive_tau2Pt_25GeV"]->fill(tauVec.at(2).pT()/GeV);
        _h["Inclusive_tau2Eta_25GeV"]->fill(tauVec.at(2).eta());
        _h["Inclusive_tau2Phi_25GeV"]->fill(tauVec.at(2).phi(MINUSPI_PLUSPI));
      }

      if (tauVec.size() >= 4){
        _h["Inclusive_tau3Pt_25GeV"]->fill(tauVec.at(3).pT()/GeV);
        _h["Inclusive_tau3Eta_25GeV"]->fill(tauVec.at(3).eta());
        _h["Inclusive_tau3Phi_25GeV"]->fill(tauVec.at(3).phi(MINUSPI_PLUSPI));
      }


    // 2LSS+3L region
    if(  ( nLep==2 && (lepVec.at(0).charge()*lepVec.at(1).charge() >0 && lepVec.at(0).pT()/GeV >15 && lepVec.at(1).pT()/GeV > 15) ) || ( nLep==3 &&  abs(elqsum + muqsum) ==1 && (lepVec.at(0).pT()/GeV >15 && lepVec.at(1).pT()/GeV > 15 && lepVec.at(2).pT()/GeV > 15) ) ){

       _h["2lSS3l_nJets"]->fill(alljets_withHadTau.size());
       _h["2lSS3l_HT"]->fill(ht);
       _h["2lSS3l_HT_jets"]->fill(ht_jets);
       _h["2lSS3l_nBjets"]->fill(bjets.size());
       _h["2lSS3l_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
       _h["2lSS3l_lep0Eta"]->fill(lepVec.at(0).eta());
       _h["2lSS3l_lepJetMinDR"]->fill(min_lj_deltaR);
       _h["2lSS3l_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
       _h["2lSS3l_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
       _h["2lSS3l_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
       _h["2lSS3l_entries"]->fill(1,1);


       _h["2lSS3l_HT_2"]->fill(ht);
       _h["2lSS3l_HT_jets_2"]->fill(ht_jets);

       if (alljets_withHadTau.size() >= 1){
         _h["2lSS3l_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
         _h["2lSS3l_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());

         _h["2lSS3l_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);

       }
       if (bjets.size()>=1){
         _h["2lSS3l_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);
       }

      if (lepVec.size() >= 1){
        _h["2lSS3l_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);
      }

    }


    // Baseline SR region
    if( (  ( nLep==2 && (lepVec.at(0).charge()*lepVec.at(1).charge() >0 && lepVec.at(0).pT()/GeV >28 && lepVec.at(1).pT()/GeV > 28) ) || ( nLep==3 &&  abs(elqsum + muqsum) ==1 && (lepVec.at(0).pT()/GeV >28 && lepVec.at(1).pT()/GeV > 28 && lepVec.at(2).pT()/GeV > 28) )   ) && (alljets_withHadTau.size() >= 6) && (bjets.size() >= 2) && (ht>500) ){

       _h["BaselineSR_nJets"]->fill(alljets_withHadTau.size());
       _h["BaselineSR_nBjets"]->fill(bjets.size());

       _h["BaselineSR_HT_1"]->fill(ht);
       _h["BaselineSR_HT_2"]->fill(ht);
       _h["BaselineSR_HT_3"]->fill(ht);

       _h["BaselineSR_HT_jets_1"]->fill(ht_jets);
       _h["BaselineSR_HT_jets_2"]->fill(ht_jets);
       _h["BaselineSR_HT_jets_3"]->fill(ht_jets);


       _h["BaselineSR_lep0Pt_1"]->fill(lepVec.at(0).pT()/GeV);
       _h["BaselineSR_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);
       _h["BaselineSR_lep0Eta"]->fill(lepVec.at(0).eta());

       _h["BaselineSR_lep1Pt_1"]->fill(lepVec.at(1).pT()/GeV);
       _h["BaselineSR_lep1Pt_2"]->fill(lepVec.at(1).pT()/GeV);
       _h["BaselineSR_lep1Eta"]->fill(lepVec.at(1).eta());


       _h["BaselineSR_lepJetMinDR"]->fill(min_lj_deltaR);
       _h["BaselineSR_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
       _h["BaselineSR_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
       _h["BaselineSR_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));


       _h["BaselineSR_jet0Pt_1"]->fill(alljets_withHadTau.at(0).pT()/GeV);
       _h["BaselineSR_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);
       _h["BaselineSR_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());

       _h["BaselineSR_jet1Pt_1"]->fill(alljets_withHadTau.at(1).pT()/GeV);
       _h["BaselineSR_jet1Pt_2"]->fill(alljets_withHadTau.at(1).pT()/GeV);
       _h["BaselineSR_jet1Eta"]->fill(alljets_withHadTau.at(1).eta());


       _h["BaselineSR_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);
       _h["BaselineSR_bjet1Pt"]->fill(bjets.at(1).pT()/GeV);

       _h["BaselineSR_entries"]->fill(1,1);



       // delta R
      float deltaR_ll_min = 100;
      float deltaR_ll_sum = 0;
      float deltaR_lb_max = 0;
      float deltaR_bj_min = 100;

       for (unsigned int i = 0; i < nLep; i++) {
         for (unsigned int k = i + 1; k < nLep; k++) {
           float deltaR_ll_temp = fabs(deltaR(lepVec.at(i),lepVec.at(k)));
           deltaR_ll_sum += deltaR_ll_temp;
           if (deltaR_ll_min > deltaR_ll_temp) deltaR_ll_min = deltaR_ll_temp;
         }
         for (unsigned int b = 0; b < bjets.size(); b++) {
           float deltaR_lb_temp = fabs(deltaR(lepVec.at(i),bjets.at(b)));
           if (deltaR_lb_max < deltaR_lb_temp) deltaR_lb_max = deltaR_lb_temp;
         }
       }


       for (unsigned int j = 0; j < ljets_withHadTau.size(); j++) {
         for (unsigned int b = 0; b < bjets.size(); b++) {
            float deltaR_jb_temp = fabs(deltaR(ljets_withHadTau.at(j),bjets.at(b)));
            if (deltaR_bj_min > deltaR_jb_temp) deltaR_bj_min = deltaR_jb_temp;
         }
       }


       _h["BaselineSR_deltaR_ll_min"]->fill(deltaR_ll_min);
       _h["BaselineSR_deltaR_ll_sum"]->fill(deltaR_ll_sum);
       _h["BaselineSR_deltaR_lb_max"]->fill(deltaR_lb_max);
       _h["BaselineSR_deltaR_bj_min"]->fill(deltaR_bj_min);

    }


    //two light-leptons
    if(nLep==2)
    {
        //same sign + lepton pT
        // Region-1
        if(lepVec.at(0).charge()*lepVec.at(1).charge() >0 && lepVec.at(0).pT()/GeV >15 && lepVec.at(1).pT()/GeV > 15) // subleading 10 -> 15 GeV
        {
             _h["2lSS_nJets"]->fill(alljets_withHadTau.size());
             _h["2lSS_HT"]->fill(ht);
             _h["2lSS_HT_jets"]->fill(ht_jets);
             _h["2lSS_nBjets"]->fill(bjets.size());
             _h["2lSS_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
             _h["2lSS_lep0Eta"]->fill(lepVec.at(0).eta());
             _h["2lSS_lepJetMinDR"]->fill(min_lj_deltaR);
             _h["2lSS_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
             _h["2lSS_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
             _h["2lSS_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
             _h["2lSS_entries"]->fill(1,1);


             _h["2lSS_HT_2"]->fill(ht);
             _h["2lSS_HT_jets_2"]->fill(ht_jets);

             // _h["2lSS_sumW"]->fill(1);

             if (alljets_withHadTau.size() >= 1){
               _h["2lSS_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
               _h["2lSS_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());
               _h["2lSS_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);

             }
             if (bjets.size()>=1){
               _h["2lSS_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);
             }
            if (lepVec.size() >= 1){
              _h["2lSS_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);
            }

                // 1b+4j
                if(bjets.size()>=1 && alljets_withHadTau.size() >= 4)
                {
           		     _h["2lSS_1b4j_nJets"]->fill(alljets_withHadTau.size());
           		     _h["2lSS_1b4j_HT"]->fill(ht);
           		     _h["2lSS_1b4j_HT_jets"]->fill(ht_jets);
           		     _h["2lSS_1b4j_nBjets"]->fill(bjets.size());
           		     _h["2lSS_1b4j_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);
           		     _h["2lSS_1b4j_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
                   _h["2lSS_1b4j_lep0Eta"]->fill(lepVec.at(0).eta());
           		     _h["2lSS_1b4j_lepJetMinDR"]->fill(min_lj_deltaR);
           		     _h["2lSS_1b4j_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
           		     _h["2lSS_1b4j_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
           		     _h["2lSS_1b4j_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
                   _h["2lSS_1b4j_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
                   _h["2lSS_1b4j_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());
                   // _h["2lSS_1b4j_sumW"]->fill(1);
                   _h["2lSS_1b4j_entries"]->fill(1,1);
                   _h["2lSS_1b4j_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);
           		     _h["2lSS_1b4j_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);


           		     _h["2lSS_1b4j_HT_2"]->fill(ht);
           		     _h["2lSS_1b4j_HT_jets_2"]->fill(ht_jets);


                }
         }
     }
     else if (nLep==3){
       if( abs(elqsum + muqsum) ==1){
         if(lepVec.at(0).pT()/GeV >15 && lepVec.at(1).pT()/GeV > 15 && lepVec.at(2).pT()/GeV > 15){
         		     _h["3l_nJets"]->fill(alljets_withHadTau.size());
         		     _h["3l_HT"]->fill(ht);
                 _h["3l_HT_jets"]->fill(ht_jets);
         		     _h["3l_nBjets"]->fill(bjets.size());
         		     _h["3l_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
                 _h["3l_lep0Eta"]->fill(lepVec.at(0).eta());
         		     _h["3l_lepJetMinDR"]->fill(min_lj_deltaR);
         		     _h["3l_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
         		     _h["3l_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
         		     _h["3l_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
                 // _h["3l_sumW"]->fill(1);

         		     _h["3l_HT_2"]->fill(ht);
                 _h["3l_HT_jets_2"]->fill(ht_jets);


                 if (alljets_withHadTau.size() >= 1){
                   _h["3l_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
                   _h["3l_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());
                   _h["3l_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);

                 }
                 if (bjets.size()>=1){
          		     _h["3l_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);

                 }
                  _h["3l_entries"]->fill(1,1);


             if(bjets.size()>=1 && alljets_withHadTau.size() >= 2){
           		     _h["3l_1b2j_nJets"]->fill(alljets_withHadTau.size());
           		     _h["3l_1b2j_HT"]->fill(ht);
                   _h["3l_1b2j_HT_jets"]->fill(ht_jets);
           		     _h["3l_1b2j_nBjets"]->fill(bjets.size());
           		     _h["3l_1b2j_bjet0Pt"]->fill(bjets.at(0).pT()/GeV);
           		     _h["3l_1b2j_lep0Pt"]->fill(lepVec.at(0).pT()/GeV);
                   _h["3l_1b2j_lep0Eta"]->fill(lepVec.at(0).eta());
           		     _h["3l_1b2j_lepJetMinDR"]->fill(min_lj_deltaR);
           		     _h["3l_1b2j_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
           		     _h["3l_1b2j_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
           		     _h["3l_1b2j_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
                   _h["3l_1b2j_jet0Pt"]->fill(alljets_withHadTau.at(0).pT()/GeV);
                   _h["3l_1b2j_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());
                   // _h["3l_1b2j_sumW"]->fill(1);
                   _h["3l_1b2j_entries"]->fill(1,1);


                   _h["3l_1b2j_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);
           		     _h["3l_1b2j_lep0Pt_2"]->fill(lepVec.at(0).pT()/GeV);

           		     _h["3l_1b2j_HT_2"]->fill(ht);
                   _h["3l_1b2j_HT_jets_2"]->fill(ht_jets);

               }
         }
       }
    }

  }


    void finalize() {
        //
        // For Powheg
        //
        // MSG_INFO("CROSS SSECTION:"<<crossSection());
        // auto xsec = isnan(crossSection()) ? 1 : crossSection();
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

    // @name Histogram data members
    //@{
    //
    map<std::string,Histo1DPtr> _h;

    //@}

  };



  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(tttt_event);
}