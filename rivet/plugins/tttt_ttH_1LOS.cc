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

/*
 * Author : Philipp Gadow (philipp.gadow@cern.ch)
 * based on the ttH-ML rivet analysis by Rohin Narayan (narayan@cern.ch) and Meng-Ju Tsai (metsai@cern.ch)
 *
 * This rivet can be compared to a  simple phasespace equivalent to the the region definitions in the tttt ttH(tt) 1LOS analysis.
 * The histograms need to be normalized to appropriate cross-section and total event weights.
 */

namespace Rivet {
    bool debug = false;

    int countProngs(Particle mother) {
        int n_prongs = 0;
        for(Particle p : mother.children())
            if (p.charge3()!=0) ++n_prongs;
        return n_prongs;
    }

  class tttt_ttH_1LOS: public Analysis {
  public:

    /// Minimal constructor
    tttt_ttH_1LOS() : Analysis("tttt_ttH_1LOS")
    {}

    /// Set up projections and book histograms
    void init() {
      FinalState lepfs;
      
      //Projection to find prompt electrons
      IdentifiedFinalState el_id(lepfs);
      el_id.acceptIdPair(PID::ELECTRON);
      PromptFinalState electrons(el_id);
      electrons.acceptTauDecays(true);
      declare(electrons,"electrons");

      //Projection to find unstable final state particles
      declare(UnstableParticles(),"UFS");

      //Projection to find prompt muons
      IdentifiedFinalState mu_id(lepfs);
      mu_id.acceptIdPair(PID::MUON);
      PromptFinalState muons(mu_id);
      muons.acceptTauDecays(true);
      declare(muons,"muons");

      //Projection to find hadronic taus
      TauFinder tauhadronic(TauFinder::DecayMode::HADRONIC);
      declare(tauhadronic,"TauHadronic");

      //Projection to find B hadrons
      declare(HeavyHadrons(Cuts::abseta < 5 && Cuts::pT > 5*GeV), "BCHadrons");

      //Projection to find jets
      const FinalState fs(Cuts::abseta < 2.5);
      declare(fs, "FS");
      FastJets jetfs(fs, FastJets::ANTIKT, 0.4, JetAlg::Muons::NONE, JetAlg::Invisibles::NONE);
      declare(jetfs, "Jets");

      //Projection to find missing momentum
      declare(MissingMomentum(FinalState(Cuts::abseta < 5 && Cuts::pT >0*GeV)),"MissingET");

      //Histogramming

      // Inclusive histograms of objects and event variables
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

      book(_h["Inclusive_jet6Pt"],"Inclusive_jet6Pt",20,0,90);
      book(_h["Inclusive_jet6Eta"],"Inclusive_jet6Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet6Phi"],"Inclusive_jet6Phi",16,-4,4);

      book(_h["Inclusive_jet7Pt"],"Inclusive_jet7Pt",20,0,90);
      book(_h["Inclusive_jet7Eta"],"Inclusive_jet7Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet7Phi"],"Inclusive_jet7Phi",16,-4,4);

      book(_h["Inclusive_jet8Pt"],"Inclusive_jet8Pt",20,0,90);
      book(_h["Inclusive_jet8Eta"],"Inclusive_jet8Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet8Phi"],"Inclusive_jet8Phi",16,-4,4);

      book(_h["Inclusive_jet9Pt"],"Inclusive_jet9Pt",20,0,90);
      book(_h["Inclusive_jet9Eta"],"Inclusive_jet9Eta",10,-2.5,2.5);
      book(_h["Inclusive_jet9Phi"],"Inclusive_jet9Phi",16,-4,4);


      book(_h["Inclusive_lep0Pt"],"Inclusive_lep0Pt",20,0,300);
      book(_h["Inclusive_lep0Pt_2"],"Inclusive_lep0Pt_2",40,0,1200);
      book(_h["Inclusive_lep0Eta"],"Inclusive_lep0Eta",10,-2.5,2.5);
      book(_h["Inclusive_lep0Phi"],"Inclusive_lep0Phi",16,-4,4);

      book(_h["Inclusive_lep1Pt"],"Inclusive_lep1Pt",20,0,150);
      book(_h["Inclusive_lep1Eta"],"Inclusive_lep1Eta",10,-2.5,2.5);
      book(_h["Inclusive_lep1Phi"],"Inclusive_lep1Phi",16,-4,4);


      // 15 GeV leptons
      book(_h["Inclusive_lep0Pt_15GeV"],"Inclusive_lep0Pt_15GeV",20,0,300);
      book(_h["Inclusive_lep0Pt_15GeV_2"],"Inclusive_lep0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_lep0Eta_15GeV"],"Inclusive_lep0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep0Phi_15GeV"],"Inclusive_lep0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_lep1Pt_15GeV"],"Inclusive_lep1Pt_15GeV",20,0,150);
      book(_h["Inclusive_lep1Eta_15GeV"],"Inclusive_lep1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_lep1Phi_15GeV"],"Inclusive_lep1Phi_15GeV",16,-4,4);

      // electrons
      book(_h["Inclusive_e0Pt_15GeV"],"Inclusive_e0Pt_15GeV",20,0,300);
      book(_h["Inclusive_e0Pt_15GeV_2"],"Inclusive_e0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_e0Eta_15GeV"],"Inclusive_e0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e0Phi_15GeV"],"Inclusive_e0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_e1Pt_15GeV"],"Inclusive_e1Pt_15GeV",20,0,150);
      book(_h["Inclusive_e1Eta_15GeV"],"Inclusive_e1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_e1Phi_15GeV"],"Inclusive_e1Phi_15GeV",16,-4,4);

      // muon
      book(_h["Inclusive_mu0Pt_15GeV"],"Inclusive_mu0Pt_15GeV",20,0,300);
      book(_h["Inclusive_mu0Pt_15GeV_2"],"Inclusive_mu0Pt_15GeV_2",40,0,1200);
      book(_h["Inclusive_mu0Eta_15GeV"],"Inclusive_mu0Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu0Phi_15GeV"],"Inclusive_mu0Phi_15GeV",16,-4,4);

      book(_h["Inclusive_mu1Pt_15GeV"],"Inclusive_mu1Pt_15GeV",20,0,150);
      book(_h["Inclusive_mu1Eta_15GeV"],"Inclusive_mu1Eta_15GeV",10,-2.5,2.5);
      book(_h["Inclusive_mu1Phi_15GeV"],"Inclusive_mu1Phi_15GeV",16,-4,4);

      book(_h["Inclusive_entries"],"Inclusive_entries",3,-0.5,3.5);


      // BDT inputs in signal region
      book(_h["BaselineSR_HT_1"],"BaselineSR_HT_1",15,0,1500);
      book(_h["BaselineSR_HT_2"],"BaselineSR_HT_2",15,0,3000);
      book(_h["BaselineSR_HT_3"],"BaselineSR_HT_3",30,0,6000);

      book(_h["BaselineSR_centrality"],"BaselineSR_centrality",15,0,1);

      book(_h["BaselineSR_nJets"],"BaselineSR_nJets",6,5.5,11.5);
      book(_h["BaselineSR_nBjets"],"BaselineSR_nBjets",5,1.5,6.5);

      book(_h["BaselineSR_jet0Pt_1"],"BaselineSR_jet0Pt_1",20,0,600);
      book(_h["BaselineSR_jet0Pt_2"],"BaselineSR_jet0Pt_2",40,0,2000);
      book(_h["BaselineSR_jet0Eta"],"BaselineSR_jet0Eta",10,-2.5,2.5);

      book(_h["BaselineSR_deltaR_bl_min"],"BaselineSR_deltaR_bl_min",12,0,2);
      book(_h["BaselineSR_deltaR_bb_min"],"BaselineSR_deltaR_bb_min",12,0,2);
      book(_h["BaselineSR_MET"],"BaselineSR_MET",15,0,3000);
      book(_h["BaselineSR_mT_lepMET"],"BaselineSR_mT_lepMET",15,0,3000);
      book(_h["BaselineSR_mll"],"BaselineSR_mll",18,0,180);

      book(_h["BaselineSR_entries"],"BaselineSR_entries",3,-0.5,3.5);

      // not implemented: Average angular separation across all pairs of jets
      // not implemented: Invariant mass of the triplet jets with minimum angular separation
      // not implemented: Average invariant mass of all the jets triplets with angular separation smaller than three
      // not implemented: The ratio of transverse momentum sum of the first four leading jets to the transverse momentum sum of the remaining jets
      // not implemented: Average invariant mass of all the b-tagged jets triplets
      // not implemented: Minimum invariant mass of all pairs of b-tagged jets
      // not implemented: Sum of the pseudo continuous b-tagged score of the four leading jets ranked in DL1r score
      // not implemented: RC-jets information
    }


    void analyze(const Event& event) {
      const MissingMomentum& met = applyProjection<MissingMomentum>(event, "MissingET");
      const double event_met	 = met.vectorEt().mod();

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

      // Count the total number of leptons
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

      int nLep = lepVec.size();
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

      double ht_jets = 0.0;
      double ht = 0.0;
      double E = 0.0;
      for(const FourMomentum& j: alljets_withHadTau) {
        ht_jets += j.pT();
        ht += j.pT();
        E += j.E();
      }
      for(const Particle & lep: lepVec){
        ht += lep.pT();
        E += lep.E();
      }

      float min_lj_deltaR=100;
      for(const FourMomentum& jet: alljets_withHadTau){ // Use alljets+Hadronic Tau
          for(const Particle & part: lepVec){
     	     if(min_lj_deltaR > fabs(deltaR(jet,part))) {min_lj_deltaR = fabs(deltaR(jet,part)); }
       	 }
      }


      // Inclusive histograms
      _h["Inclusive_nJets"]->fill(alljets_withHadTau.size());
      _h["Inclusive_HT"]->fill(ht);
      _h["Inclusive_HT_jets"]->fill(ht_jets);
      _h["Inclusive_nBjets"]->fill(bjets.size());
      _h["Inclusive_nHadTau"]->fill(tauVec.size());
      _h["Inclusive_entries"]->fill(1,1);
      _h["Inclusive_HT_2"]->fill(ht);
      _h["Inclusive_HT_jets_2"]->fill(ht_jets);

      // Jets
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

      if (alljets_withHadTau.size() >= 7){
        _h["Inclusive_jet6Pt"]->fill(alljets_withHadTau.at(6).pT()/GeV);
        _h["Inclusive_jet6Eta"]->fill(alljets_withHadTau.at(6).eta());
        _h["Inclusive_jet6Phi"]->fill(alljets_withHadTau.at(6).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 8){
        _h["Inclusive_jet7Pt"]->fill(alljets_withHadTau.at(7).pT()/GeV);
        _h["Inclusive_jet7Eta"]->fill(alljets_withHadTau.at(7).eta());
        _h["Inclusive_jet7Phi"]->fill(alljets_withHadTau.at(7).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 9){
        _h["Inclusive_jet8Pt"]->fill(alljets_withHadTau.at(8).pT()/GeV);
        _h["Inclusive_jet8Eta"]->fill(alljets_withHadTau.at(8).eta());
        _h["Inclusive_jet8Phi"]->fill(alljets_withHadTau.at(8).phi(MINUSPI_PLUSPI));
      }

      if (alljets_withHadTau.size() >= 10){
        _h["Inclusive_jet9Pt"]->fill(alljets_withHadTau.at(9).pT()/GeV);
        _h["Inclusive_jet9Eta"]->fill(alljets_withHadTau.at(9).eta());
        _h["Inclusive_jet9Phi"]->fill(alljets_withHadTau.at(9).phi(MINUSPI_PLUSPI));
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

      // Baseline SR region
      if( (nLep==1 && (lepVec.at(0).pT()/GeV >28) && (alljets_withHadTau.size() >= 7) && (bjets.size() >= 2)) || (nLep==2 && (lepVec.at(0).charge()*lepVec.at(1).charge() < 0) && (lepVec.at(0).pT()/GeV >28 && lepVec.at(1).pT()/GeV > 28) && (alljets_withHadTau.size() >= 5) && (bjets.size() >= 2)) ){

       _h["BaselineSR_HT_1"]->fill(ht);
       _h["BaselineSR_HT_2"]->fill(ht);
       _h["BaselineSR_HT_3"]->fill(ht);

       _h["BaselineSR_centrality"]->fill(ht/E);

       _h["BaselineSR_nJets"]->fill(alljets_withHadTau.size());
       _h["BaselineSR_nBjets"]->fill(bjets.size());

       _h["BaselineSR_jet0Pt_1"]->fill(alljets_withHadTau.at(0).pT()/GeV);
       _h["BaselineSR_jet0Pt_2"]->fill(alljets_withHadTau.at(0).pT()/GeV);
       _h["BaselineSR_jet0Eta"]->fill(alljets_withHadTau.at(0).eta());

      float deltaR_bb_min = 100;
      float deltaR_bl_min = 100;
      for (unsigned int i = 0; i < bjets.size(); i++) {
         for (unsigned int k = i + 1; k < bjets.size(); k++) {
           float deltaR_bb_temp = fabs(deltaR(bjets.at(i),bjets.at(k)));
           if (deltaR_bb_min > deltaR_bb_temp) deltaR_bb_min = deltaR_bb_temp;
         }
         for (int l = 0; l < nLep; l++) {
           float deltaR_bl_temp = fabs(deltaR(lepVec.at(l),bjets.at(i)));
           if (deltaR_bl_min > deltaR_bl_temp) deltaR_bl_min = deltaR_bl_temp;
         }
       }
       _h["BaselineSR_deltaR_bb_min"]->fill(deltaR_bb_min);
       _h["BaselineSR_deltaR_bl_min"]->fill(deltaR_bl_min);

       _h["BaselineSR_MET"]->fill(event_met);
       if (nLep==1) {
         _h["BaselineSR_mT_lepMET"]->fill(sqrt(2*lepVec.at(0).pT()*event_met*(1-cos(deltaPhi(lepVec.at(0),met.vectorEt())))));
       }
       else if (nLep==2) {
         _h["BaselineSR_mll"]->fill((lepVec.at(0).mom()+lepVec.at(1).mom()).mass()/GeV);
       }

       _h["BaselineSR_entries"]->fill(1,1);
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

  private:
    // @name Histogram data members
    map<std::string,Histo1DPtr> _h;
  };

  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(tttt_ttH_1LOS);
}
