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
 * Author : Rohin Narayan (narayan@cern.ch) 
 *
 *
 * This rivet can be compared to a  simple phasespace equivalent to the the region definitions in the ttH-ML analysis. 
 * The histograms need to be normalized to appropriate cross-section and total event weights. In an ATLAS environment
 * these histograms gets converted to ROOT format and the normalizations and handled by a subsequent script outside rivet.  
 *
 *
 */

namespace Rivet {

    int countProngs(Particle mother) {
        int n_prongs = 0;
        for(Particle p : mother.children())
            if (p.charge3()!=0) ++n_prongs;
        return n_prongs;
    }


  
  class ttw_ttH: public Analysis {
  public:

    /// Minimal constructor
    ttw_ttH() : Analysis("ttw_ttH")
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
      declare(FastJets(FinalState(Cuts::abseta <-2.5 && Cuts::pT>25*GeV),FastJets::ANTIKT,0.4),"Jets");
      //declare(FastJets(FinalState(), FastJets::ANTIKT, 0.4), "Jets");
      declare(MissingMomentum(FinalState(Cuts::abseta <5 && Cuts::pT >0*GeV)),"MissingET");


      //Histogramming 
      book(_h["sumOfWeights"],"sumOfWeights",2,0,2);
      book(_h["2lSS0tau_MET"], "2lSS0tau_MET",50,0,500);
      book(_h["2lSS1tau_MET"], "2lSS1tau_MET",50,0,500);

      book(_h["eMinusFromTaus_pt"],"eMinusFromTaus_pt",40,0,800);
      book(_h["eMinusFromTaus_phi"],"eMinusFromTaus_phi",10,0,2*M_PI);
      book(_h["eMinusFromTaus_Eta"],"eMinusFromTaus_Eta",100,-5,5);

      book(_h["ePlusFromTaus_pt"],"ePlusFromTaus_pt",40,0,800);
      book(_h["ePlusFromTaus_phi"],"ePlusFromTaus_phi",10,0,2*M_PI);
      book(_h["ePlusFromTaus_Eta"],"ePlusFromTaus_Eta",100,-5,5);

      book(_h["MuonsFromTaus_pt"],"MuonsFromTaus_pt",40,0,800);
      book(_h["MuonsFromTaus_phi"],"MuonsFromTaus_phi",10,0,2*M_PI);
      book(_h["MuonsFromTaus_Eta"],"MuonsFromTaus_Eta",100,-5,5);

      book(_h["AntiMuonsFromTaus_pt"],"AntiMuonsFromTaus_pt",40,0,800);
      book(_h["AntiMuonsFromTaus_phi"],"AntiMuonsFromTaus_phi",10,0,2*M_PI);
      book(_h["AntiMuonsFromTaus_Eta"],"AntiMuonsFromTaus_Eta",100,-5,5);


      book(_h["2lSS0tau_region1_nJets"],"2lSS0tau_region1_nJets",10,-0.5,9.5);
      book(_h["2lSS0tau_region1_HT"],"2lSS0tau_region1_HT",100,0,2000);
      book(_h["2lSS0tau_region1_nBjets"],"2lSS0tau_region1_nBjets",4,-0.5,3.5);
      book(_h["2lSS0tau_region1_bjet0Pt"],"2lSS0tau_region1_bjet0Pt",50,0,500);
      book(_h["2lSS0tau_region1_lep0Pt"],"2lSS0tau_region1_lep0Pt",40,0,800);
      book(_h["2lSS0tau_region1_lep0pT"],"2lSS0tau_region1_lep0pT",5,0,0.5);
      book(_h["2lSS0tau_region1_lepJetMinDR"],"2lSS0tau_region1_lepJetMinDR",5,0,0.5);
      book(_h["2lSS0tau_region1_DR_lep01"],"2lSS0tau_region1_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region1_DEta_lep01"],"2lSS0tau_region1_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region1_DPhi_lep01"],"2lSS0tau_region1_DPhi_lep01",10,0,2*M_PI);

      book(_h["2lSS0tau_region2_nJets"],"2lSS0tau_region2_nJets",10,-0.5,9.5);
      book(_h["2lSS0tau_region2_HT"],"2lSS0tau_region2_HT",100,0,2000);
      book(_h["2lSS0tau_region2_nBjets"],"2lSS0tau_region2_nBjets",4,-0.5,3.5);
      book(_h["2lSS0tau_region2_bjet0pT"],"2lSS0tau_region2_bjet0Pt",50,0,500);
      book(_h["2lSS0tau_region2_lep0pT"],"2lSS0tau_region2_lep0Pt",40,0,800);
      book(_h["2lSS0tau_region2_lepJetMinDR"],"2lSS0tau_region2_lepJetminDR",5,0,0.5);
      book(_h["2lSS0tau_region2_DR_lep01"],"2lSS0tau_region2_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region2_DEta_lep01"],"2lSS0tau_region2_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region2_DPhi_lep01"],"2lSS0tau_region2_DPhi_lep01",10,0,2*M_PI);

      book(_h["2lSS0tau_region3_nJets"],"2lSS0tau_region3_nJets",10,-0.5,9.5);
      book(_h["2lSS0tau_region3_HT"],"2lSS0tau_region3_HT",100,0,2000);
      book(_h["2lSS0tau_region3_nBjets"],"2lSS0tau_region3_nBjets",4,-0.5,3.5);
      book(_h["2lSS0tau_region3_bjet0pT"],"2lSS0tau_region3_bjet0Pt",50,0,500);
      book(_h["2lSS0tau_region3_lep0pT"],"2lSS0tau_region3_lep0Pt",40,0,800);
      book(_h["2lSS0tau_region3_lepJetMinDR"],"2lSS0tau_region3_lepJetminDR",5,0,0.5);
      book(_h["2lSS0tau_region3_DR_lep01"],"2lSS0tau_region3_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region3_DEta_lep01"],"2lSS0tau_region3_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region3_DPhi_lep01"],"2lSS0tau_region3_DPhi_lep01",10,0,2*M_PI);


      book(_h["2lSS0tau_region4_nJets"],"2lSS0tau_region4_nJets",10,-0.5,9.5);
      book(_h["2lSS0tau_region4_HT"],"2lSS0tau_region4_HT",100,0,2000);
      book(_h["2lSS0tau_region4_nBjets"],"2lSS0tau_region4_nBjets",4,-0.5,3.5);
      book(_h["2lSS0tau_region4_bjet0pT"],"2lSS0tau_region4_bjet0Pt",50,0,500);
      book(_h["2lSS0tau_region4_lep0pT"],"2lSS0tau_region4_lep0Pt",40,0,800);
      book(_h["2lSS0tau_region4_lepJetMinDR"],"2lSS0tau_region4_lepJetminDR",5,0,0.5);
      book(_h["2lSS0tau_region4_DR_lep01"],"2lSS0tau_region4_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region4_DEta_lep01"],"2lSS0tau_region4_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region4_DPhi_lep01"],"2lSS0tau_region4_DPhi_lep01",10,0,2*M_PI);

      book(_h["2lSS0tau_region5_nJets"],"2lSS0tau_region5_nJets",10,-0.5,9.5);
      book(_h["2lSS0tau_region5_HT"],"2lSS0tau_region5_HT",100,0,2000);
      book(_h["2lSS0tau_region5_nBjets"],"2lSS0tau_region5_nBjets",4,-0.5,3.5);
      book(_h["2lSS0tau_region5_bjet0pT"],"2lSS0tau_region5_bjet0Pt",50,0,500);
      book(_h["2lSS0tau_region5_lep0pT"],"2lSS0tau_region5_lep0Pt",40,0,800);
      book(_h["2lSS0tau_region5_lepJetMinDR"],"2lSS0tau_region5_lepJetminDR",5,0,0.5);
      book(_h["2lSS0tau_region5_DR_lep01"],"2lSS0tau_region5_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region5_DEta_lep01"],"2lSS0tau_region5_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS0tau_region5_DPhi_lep01"],"2lSS0tau_region5_DPhi_lep01",10,0,2*M_PI);

      book(_h["2lSS1tau_region6_nJets"],"2lSS1tau_region6_nJets",10,-0.5,9.5);
      book(_h["2lSS1tau_region6_HT"],"2lSS1tau_region6_HT",100,0,2000);
      book(_h["2lSS1tau_region6_nBjets"],"2lSS1tau_region6_nBjets",4,-0.5,3.5);
      book(_h["2lSS1tau_region6_bjet0pT"],"2lSS1tau_region6_bjet0Pt",50,0,500);
      book(_h["2lSS1tau_region6_lep0pT"],"2lSS1tau_region6_lep0Pt",40,0,800);
      book(_h["2lSS1tau_region6_lepJetMinDR"],"2lSS1tau_region6_lepJetminDR",5,0,0.5);
      book(_h["2lSS1tau_region6_DR_lep01"],"2lSS1tau_region6_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region6_DEta_lep01"],"2lSS1tau_region6_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region6_DPhi_lep01"],"2lSS1tau_region6_DPhi_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region6_tauPt"],"2lSS1tau_region6_tauPt",50,0,500);


      book(_h["2lSS1tau_region7_nJets"],"2lSS1tau_region7_nJets",10,-0.5,9.5);
      book(_h["2lSS1tau_region7_HT"],"2lSS1tau_region7_HT",100,0,2000);
      book(_h["2lSS1tau_region7_nBjets"],"2lSS1tau_region7_nBjets",4,-0.5,3.5);
      book(_h["2lSS1tau_region7_bjet0pT"],"2lSS1tau_region7_bjet0Pt",50,0,500);
      book(_h["2lSS1tau_region7_lep0pT"],"2lSS1tau_region7_lep0Pt",40,0,800);
      book(_h["2lSS1tau_region7_lepJetMinDR"],"2lSS1tau_region7_lepJetminDR",5,0,0.5);
      book(_h["2lSS1tau_region7_DR_lep01"],"2lSS1tau_region7_DR_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region7_DEta_lep01"],"2lSS1tau_region7_DEta_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region7_DPhi_lep01"],"2lSS1tau_region7_DPhi_lep01",10,0,2*M_PI);
      book(_h["2lSS1tau_region7_tauPt"],"2lSS1tau_region7_tauPt",50,0,500);



    }


    void analyze(const Event& event) {
      // Use the "LFS" projection to require at least one hard charged
      // lepton. This is an experimental signature for the leptonically decaying
      // W. This helps to reduce pure QCD backgrounds.
      
      const MissingMomentum& met = applyProjection<MissingMomentum>(event, "MissingET");
      const double event_met	 = met.vectorEt().mod();

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

      for(const Particle &p: eMinusFromTaus)
      {
          _h["eMinusFromTaus_pt"]->fill(p.pT()/GeV);
          _h["eMinusFromTaus_Eta"]->fill(p.eta());
          _h["eMinusFromTaus_phi"]->fill(p.phi());
      }

      for(const Particle &p: ePlusFromTaus)
      {
          _h["ePlusFromTaus_pt"]->fill(p.pT()/GeV);
          _h["ePlusFromTaus_Eta"]->fill(p.eta());
          _h["ePlusFromTaus_phi"]->fill(p.phi());
      }

      for(const Particle &p: muonsFromTaus)
      {
          _h["MuonsFromTaus_pt"]->fill(p.pT()/GeV);
          _h["MuonsFromTaus_Eta"]->fill(p.eta());
          _h["MuonsFromTaus_phi"]->fill(p.phi());
      }

      for(const Particle &p: antiMuonsFromTaus)
      {
          _h["AntiMuonsFromTaus_pt"]->fill(p.pT()/GeV);
          _h["AntiMuonsFromTaus_Eta"]->fill(p.eta());
          _h["AntiMuonsFromTaus_phi"]->fill(p.phi());
      }

      Particles elVec,muVec,tauVec,lepVec;
      //Count the total number of leptons
      //
      //

      for (const Particle & el: applyProjection<PromptFinalState>(event,"electrons").particlesByPt())
      {
          if(el.pT()/GeV > 10 && fabs(el.eta()) <2.5)
          {
              elVec.push_back(el);
	      lepVec.push_back(el);
          }
      }
      for(const Particle &mu: applyProjection<PromptFinalState>(event,"muons").particlesByPt())
      {
          if(mu.pT()/GeV >10 && fabs(mu.eta()) <2.5)
          {
              muVec.push_back(mu);
 	      lepVec.push_back(mu);
          }
      }
      const TauFinder &tauhad = applyProjection<TauFinder>(event,"TauHadronic");
      for(const Particle &tau: tauhad.taus())
      {
          if(tau.pT()/GeV >25 )
          {
            int nProng = countProngs(tau);
            if(nProng ==2 || nProng ==3)
            {
              tauVec.push_back(tau);
            }
          }
      }

      elVec = sortByPt(elVec);
      muVec = sortByPt(muVec);
      tauVec= sortByPt(tauVec);
      lepVec= sortByPt(lepVec);

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
      for(const Jet &jet : applyProjection<FastJets>(event, "Jets").jetsByPt(25*GeV))
      {
          if(fabs(jet.eta()) <2.5 )
          {
              alljets.push_back(jet);
          }
      }
      double ht = 0.0;
      for(const Jet& j: alljets) { ht += j.pT(); }


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
     alljets    =   sortByPt(alljets);
     bjets      =   sortByPt(bjets);
     ljets      =   sortByPt(ljets);
     
     float min_lj_deltaR=100;
     for(const Jet& jet: alljets)
     {
         for(const Particle & part: lepVec)
	 {
	     if(min_lj_deltaR > fabs(deltaR(jet,part))) {min_lj_deltaR = fabs(deltaR(jet,part)); }
	 }
     }


     
     //two light-leptons
     if(nLep==2)
     {
         //same sign + lepton pT 
         // Region-1
         if(lepVec.at(0).charge()*lepVec.at(1).charge() >0 && lepVec.at(0).pT()/GeV >15 && lepVec.at(1).pT()/GeV > 10)
         {
              _h["2lSS0tau_region1_nJets"]->fill(alljets.size());
              _h["2lSS0tau_region1_HT"]->fill(ht);
              _h["2lSS0tau_region1_nBjets"]->fill(bjets.size());
              _h["2lSS0tau_region1_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
              _h["2lSS0tau_region1_lepJetMinDR"]->fill(min_lj_deltaR);
              _h["2lSS0tau_region1_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
              _h["2lSS0tau_region1_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
              _h["2lSS0tau_region1_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
 
	     // 0-tau
             if(tauVec.size()==0)
             {
		 _h["2lSS0tau_MET"]->fill(event_met/GeV);
                 // "Region-2"
                 if(bjets.size()==1 && alljets.size() >= 4)
                 {
      		     _h["2lSS0tau_region2_nJets"]->fill(alljets.size());
      		     _h["2lSS0tau_region2_HT"]->fill(ht);
		     _h["2lSS0tau_region2_nBjets"]->fill(bjets.size());
		     _h["2lSS0tau_region2_bjet0pT"]->fill(bjets.at(0).pT()/GeV);
		     _h["2lSS0tau_region2_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
		     _h["2lSS0tau_region2_lepJetMinDR"]->fill(min_lj_deltaR);
		     _h["2lSS0tau_region2_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region2_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region2_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
                 }
                 // "Region-3"
                 if(bjets.size()>=2 && alljets.size() >= 4)
                 {
      		     _h["2lSS0tau_region3_nJets"]->fill(alljets.size());
      		     _h["2lSS0tau_region3_HT"]->fill(ht);
		     _h["2lSS0tau_region3_nBjets"]->fill(bjets.size());
		     _h["2lSS0tau_region3_bjet0pT"]->fill(bjets.at(0).pT()/GeV);
		     _h["2lSS0tau_region3_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
		     _h["2lSS0tau_region3_lepJetMinDR"]->fill(min_lj_deltaR);
		     _h["2lSS0tau_region3_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region3_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region3_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));

                 }
                 // "Region-4"
                 if(bjets.size()==1 && alljets.size() >= 3)
                 {
      		     _h["2lSS0tau_region4_nJets"]->fill(alljets.size());
      		     _h["2lSS0tau_region4_HT"]->fill(ht);
		     _h["2lSS0tau_region4_nBjets"]->fill(bjets.size());
		     _h["2lSS0tau_region4_bjet0pT"]->fill(bjets.at(0).pT()/GeV);
		     _h["2lSS0tau_region4_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
		     _h["2lSS0tau_region4_lepJetMinDR"]->fill(min_lj_deltaR);
		     _h["2lSS0tau_region4_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region4_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region4_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));

                 }
                 // "Region-5"
                 if(bjets.size()>=2 && alljets.size() >= 3)
                 {
      		     _h["2lSS0tau_region5_nJets"]->fill(alljets.size());
      		     _h["2lSS0tau_region5_HT"]->fill(ht);
		     _h["2lSS0tau_region5_nBjets"]->fill(bjets.size());
		     _h["2lSS0tau_region5_bjet0pT"]->fill(bjets.at(0).pT()/GeV);
		     _h["2lSS0tau_region5_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
		     _h["2lSS0tau_region5_lepJetMinDR"]->fill(min_lj_deltaR);
		     _h["2lSS0tau_region5_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region5_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS0tau_region5_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
                 }
             }
	     // 1-tau
             else if (tauVec.size()>=1)
             {
	         _h["2lSS1tau_MET"]->fill(event_met/GeV);
		 // "Region-6"
		 _h["2lSS1tau_region6_nJets"]->fill(alljets.size());
      	         _h["2lSS1tau_region6_HT"]->fill(ht);
	         _h["2lSS1tau_region6_nBjets"]->fill(bjets.size());
	         _h["2lSS1tau_region6_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
	         _h["2lSS1tau_region6_lepJetMinDR"]->fill(min_lj_deltaR);
	         _h["2lSS1tau_region6_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
	         _h["2lSS1tau_region6_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
	         _h["2lSS1tau_region6_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
		 _h["2lSS1tau_region6_tauPt"]->fill(tauVec.at(0).pT()/GeV);

	         // "Region-7"
                 if(bjets.size() >= 1 && alljets.size() >= 3)
                 {
	             _h["2lSS1tau_region7_nJets"]->fill(alljets.size());
      	             _h["2lSS1tau_region7_HT"]->fill(ht);
	             _h["2lSS1tau_region7_nBjets"]->fill(bjets.size());
	             _h["2lSS1tau_region7_bjet0pT"]->fill(bjets.at(0).pT()/GeV);
	             _h["2lSS1tau_region7_lep0pT"]->fill(lepVec.at(0).pT()/GeV);
	             _h["2lSS1tau_region7_lepJetMinDR"]->fill(min_lj_deltaR);
	             _h["2lSS1tau_region7_DR_lep01"]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))));
	             _h["2lSS1tau_region7_DEta_lep01"]->fill(fabs(deltaEta(lepVec.at(0),lepVec.at(1))));
	             _h["2lSS1tau_region7_DPhi_lep01"]->fill(fabs(deltaPhi(lepVec.at(0),lepVec.at(1))));
		     _h["2lSS1tau_region7_tauPt"]->fill(tauVec.at(0).pT()/GeV);
	          }
              }
          }
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
  DECLARE_RIVET_PLUGIN(ttw_ttH);
}