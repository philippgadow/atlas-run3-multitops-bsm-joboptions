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

#include <vector>
#include <algorithm>
#include <cmath>

namespace Rivet {

  using namespace Cuts;
  bool debug = false;

  double calculateInvariantMass(const Particle& p1, const Particle& p2) {
    return (p1.momentum() + p2.momentum() ).mass()/GeV;
  }

  std::vector<Particle> calculateAllPairsInvariantMass(std::vector<Particle>& particles) {
    std::vector<std::pair<double, std::pair<int, int>>> pairs;
    for (unsigned int i = 0; i < particles.size(); i++) {
        for (unsigned int j = i + 1; j < particles.size(); j++) {
            double invariantMass = calculateInvariantMass(particles[i], particles[j]);
            pairs.push_back({invariantMass, {i, j}});
        }
    }

    std::sort(pairs.begin(), pairs.end(), [](const std::pair<double, std::pair<int, int>>& a, const std::pair<double, std::pair<int, int>>& b) {
        return a.first > b.first;
    });

    std::vector<Particle> sortedParticles;
    std::set<int> addedIndices;
    for (const auto& pair : pairs) {
        if (addedIndices.find(pair.second.first) == addedIndices.end()) {
            sortedParticles.push_back(particles[pair.second.first]);
            addedIndices.insert(pair.second.first);
        }
        if (addedIndices.find(pair.second.second) == addedIndices.end()) {
            sortedParticles.push_back(particles[pair.second.second]);
            addedIndices.insert(pair.second.second);
        }
    }

    return sortedParticles;
  }

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

        book(_h["Inclusive_mH400"],"Inclusive_mH400",20,300,500);
        book(_h["Inclusive_mH500"],"Inclusive_mH500",20,400,600);
        book(_h["Inclusive_mH600"],"Inclusive_mH600",20,500,700);
        book(_h["Inclusive_mH700"],"Inclusive_mH700",20,600,800);
        book(_h["Inclusive_mH800"],"Inclusive_mH800",20,700,900);
        book(_h["Inclusive_mH900"],"Inclusive_mH900",20,800,1000);
        book(_h["Inclusive_mH1000"],"Inclusive_mH1000",20,900,1100);
        book(_h["Inclusive_mH1100"],"Inclusive_mH1100",20,1000,1200);
        book(_h["Inclusive_mH1200"],"Inclusive_mH1200",20,1100,1300);
        book(_h["Inclusive_mH1250"],"Inclusive_mH1250",20,1150,1350);
        book(_h["Inclusive_mH1300"],"Inclusive_mH1300",20,1200,1400);
        book(_h["Inclusive_mH1400"],"Inclusive_mH1400",20,1300,1500);
        book(_h["Inclusive_mH1500"],"Inclusive_mH1500",20,1400,1600);
        book(_h["Inclusive_mH1600"],"Inclusive_mH1600",20,1500,1700);
        book(_h["Inclusive_mH1700"],"Inclusive_mH1700",20,1600,1800);
        book(_h["Inclusive_mH1800"],"Inclusive_mH1800",20,1700,1900);
        book(_h["Inclusive_mH1900"],"Inclusive_mH1900",20,1800,2000);
        book(_h["Inclusive_mH2000"],"Inclusive_mH2000",20,1900,2100);
        book(_h["Inclusive_mH2100"],"Inclusive_mH2100",20,2000,2200);
        book(_h["Inclusive_mH2200"],"Inclusive_mH2200",20,2100,2300);
        book(_h["Inclusive_mH2300"],"Inclusive_mH2300",20,2200,2400);
        book(_h["Inclusive_mH2400"],"Inclusive_mH2400",20,2300,2500);
        book(_h["Inclusive_mH2500"],"Inclusive_mH2500",20,2400,2600);
        book(_h["Inclusive_mH2600"],"Inclusive_mH2600",20,2500,2700);
        book(_h["Inclusive_mH2700"],"Inclusive_mH2700",20,2600,2800);
        book(_h["Inclusive_mH2800"],"Inclusive_mH2800",20,2700,2900);
        book(_h["Inclusive_mH2900"],"Inclusive_mH2900",20,2800,3000);
        book(_h["Inclusive_mH3000"],"Inclusive_mH3000",20,2900,3100);

        book(_h["Inclusive_mH"],"Inclusive_mH",870,150,4500);
        book(_h["Inclusive_mH_zoomin"],"Inclusive_mH_zoomin",1740,150,4500);
        book(_h["Inclusive_pT_H"],"Inclusive_pT_H",25,0,1000);

        book(_h["Inclusive_InvM_400"],"Inclusive_InvM_400",20,300,500);
        book(_h["Inclusive_InvM_500"],"Inclusive_InvM_500",20,400,600);
        book(_h["Inclusive_InvM_600"],"Inclusive_InvM_600",20,500,700);
        book(_h["Inclusive_InvM_700"],"Inclusive_InvM_700",20,600,800);
        book(_h["Inclusive_InvM_800"],"Inclusive_InvM_800",20,700,900);
        book(_h["Inclusive_InvM_900"],"Inclusive_InvM_900",20,800,1000);
        book(_h["Inclusive_InvM_1000"],"Inclusive_InvM_1000",20,900,1100);
        book(_h["Inclusive_InvM_1100"],"Inclusive_InvM_1100",20,1000,1200);
        book(_h["Inclusive_InvM_1200"],"Inclusive_InvM_1200",20,1100,1300);
        book(_h["Inclusive_InvM_1250"],"Inclusive_InvM_1250",20,1150,1350);
        book(_h["Inclusive_InvM_1300"],"Inclusive_InvM_1300",20,1200,1400);
        book(_h["Inclusive_InvM_1400"],"Inclusive_InvM_1400",20,1300,1500);
        book(_h["Inclusive_InvM_1500"],"Inclusive_InvM_1500",20,1400,1600);
        book(_h["Inclusive_InvM_1600"],"Inclusive_InvM_1600",20,1500,1700);
        book(_h["Inclusive_InvM_1700"],"Inclusive_InvM_1700",20,1600,1800);
        book(_h["Inclusive_InvM_1800"],"Inclusive_InvM_1800",20,1700,1900);
        book(_h["Inclusive_InvM_1900"],"Inclusive_InvM_1900",20,1800,2000);
        book(_h["Inclusive_InvM_2000"],"Inclusive_InvM_2000",20,1900,2100);
        book(_h["Inclusive_InvM_2100"],"Inclusive_InvM_2100",20,2000,2200);
        book(_h["Inclusive_InvM_2200"],"Inclusive_InvM_2200",20,2100,2300);
        book(_h["Inclusive_InvM_2300"],"Inclusive_InvM_2300",20,2200,2400);
        book(_h["Inclusive_InvM_2400"],"Inclusive_InvM_2400",20,2300,2500);
        book(_h["Inclusive_InvM_2500"],"Inclusive_InvM_2500",20,2400,2600);
        book(_h["Inclusive_InvM_2600"],"Inclusive_InvM_2600",20,2500,2700);
        book(_h["Inclusive_InvM_2700"],"Inclusive_InvM_2700",20,2600,2800);
        book(_h["Inclusive_InvM_2800"],"Inclusive_InvM_2800",20,2700,2900);
        book(_h["Inclusive_InvM_2900"],"Inclusive_InvM_2900",20,2800,3000);
        book(_h["Inclusive_InvM_3000"],"Inclusive_InvM_3000",20,2900,3100);

        book(_h["Inclusive_InvM_ttbar12"],"Inclusive_InvM_ttbar12",870,150,4500);
        book(_h["Inclusive_pT_ttbar12"],"Inclusive_pT_ttbar12",25,0,1000);
        book(_h["Inclusive_dR_ttbar12"],"Inclusive_dR_ttbar12",20,0,5);

        book(_h["Inclusive_mTop1"],"Inclusive_mTop1",25,150,200);
        book(_h["Inclusive_mTop2"],"Inclusive_mTop2",25,150,200);
        book(_h["Inclusive_mTop1_zoomin"],"Inclusive_mTop1_zoomin",40,165,175);
        book(_h["Inclusive_mTop2_zoomin"],"Inclusive_mTop2_zoomin",40,165,175);

        book(_h["Inclusive_InvM_ttbar34"],"Inclusive_InvM_ttbar34",870,150,4500);
        book(_h["Inclusive_pT_ttbar34"],"Inclusive_pT_ttbar34",20,0,600);
        book(_h["Inclusive_dR_ttbar34"],"Inclusive_dR_ttbar34",20,0,5);

        book(_h["Inclusive_mTop3"],"Inclusive_mTop3",25,150,200);
        book(_h["Inclusive_mTop4"],"Inclusive_mTop4",25,150,200);
        book(_h["Inclusive_mTop3_zoomin"],"Inclusive_mTop3_zoomin",40,165,175);
        book(_h["Inclusive_mTop4_zoomin"],"Inclusive_mTop4_zoomin",40,165,175);
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // const double weight = event.weight();

      // MSG_INFO("#----------------Event--------------#");

      //DO PDG analysis
      vector<const HepMC::GenParticle*> genParticles = HepMCUtils::particles(event.genEvent());

      Particles topCands;
      Particles HCands;

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
                                     << ", barcode: " << part->barcode()
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
                                   << ", barcode: " << part->barcode()
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
      }

      _h["Inclusive_nH"]->fill(HCands.size());
      _h["Inclusive_nTop"]->fill(topCands.size());

      // fill Higgs properties
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
        _h["Inclusive_mH1100"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1200"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1250"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1300"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1400"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1500"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1600"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1700"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1800"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH1900"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2000"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2100"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2200"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2300"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2400"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2500"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2600"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2700"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2800"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH2900"]->fill(HCands.at(0).mass());
        _h["Inclusive_mH3000"]->fill(HCands.at(0).mass());
      } else{
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
        _h["Inclusive_mH1100"]->fill(-999);
        _h["Inclusive_mH1200"]->fill(-999);
        _h["Inclusive_mH1250"]->fill(-999);
        _h["Inclusive_mH1300"]->fill(-999);
        _h["Inclusive_mH1400"]->fill(-999);
        _h["Inclusive_mH1500"]->fill(-999);
        _h["Inclusive_mH1600"]->fill(-999);
        _h["Inclusive_mH1700"]->fill(-999);
        _h["Inclusive_mH1800"]->fill(-999);
        _h["Inclusive_mH1900"]->fill(-999);
        _h["Inclusive_mH2000"]->fill(-999);
        _h["Inclusive_mH2100"]->fill(-999);
        _h["Inclusive_mH2200"]->fill(-999);
        _h["Inclusive_mH2300"]->fill(-999);
        _h["Inclusive_mH2400"]->fill(-999);
        _h["Inclusive_mH2500"]->fill(-999);
        _h["Inclusive_mH3000"]->fill(-999);
      }

      // now sort, either by pt or by invariant mass
      isortByPt(topCands);
      auto sortedTopCands = topCands;

      // auto sortedTopCands = calculateAllPairsInvariantMass(topCands);

      if ( sortedTopCands.size() > 1 ){
        double InvM_ttbar12 = (sortedTopCands.at(0).momentum() + sortedTopCands.at(1).momentum() ).mass()/GeV;
        double pT_ttbar12 = (sortedTopCands.at(0).momentum() + sortedTopCands.at(1).momentum()).pT()/GeV;
        double dR_ttbar12 = fabs(deltaR(sortedTopCands.at(0),sortedTopCands.at(1)));

        _h["Inclusive_InvM_ttbar12"]->fill(InvM_ttbar12);
        _h["Inclusive_pT_ttbar12"]->fill(pT_ttbar12);
        _h["Inclusive_dR_ttbar12"]->fill(dR_ttbar12);
        _h["Inclusive_mTop1"]->fill(sortedTopCands.at(0).mass());
        _h["Inclusive_mTop2"]->fill(sortedTopCands.at(1).mass());
        _h["Inclusive_mTop1_zoomin"]->fill(sortedTopCands.at(0).mass());
        _h["Inclusive_mTop2_zoomin"]->fill(sortedTopCands.at(1).mass());
        _h["Inclusive_InvM_400"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_500"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_600"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_700"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_800"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_900"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1000"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1100"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1200"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1250"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1300"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1400"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1500"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1600"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1700"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1800"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_1900"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2000"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2100"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2200"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2300"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2400"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2500"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2600"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2700"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2800"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_2900"]->fill(InvM_ttbar12);
        _h["Inclusive_InvM_3000"]->fill(InvM_ttbar12);
      } else{
        _h["Inclusive_InvM_ttbar12"]->fill(-999);
        _h["Inclusive_pT_ttbar12"]->fill(-999);
        _h["Inclusive_dR_ttbar12"]->fill(-999);
        _h["Inclusive_mTop1"]->fill(-999);
        _h["Inclusive_mTop2"]->fill(-999);
        _h["Inclusive_mTop1_zoomin"]->fill(-999);
        _h["Inclusive_mTop2_zoomin"]->fill(-999);
        _h["Inclusive_InvM_400"]->fill(-999);
        _h["Inclusive_InvM_500"]->fill(-999);
        _h["Inclusive_InvM_600"]->fill(-999);
        _h["Inclusive_InvM_700"]->fill(-999);
        _h["Inclusive_InvM_800"]->fill(-999);
        _h["Inclusive_InvM_900"]->fill(-999);
        _h["Inclusive_InvM_1000"]->fill(-999);
        _h["Inclusive_InvM_1100"]->fill(-999);
        _h["Inclusive_InvM_1200"]->fill(-999);
        _h["Inclusive_InvM_1250"]->fill(-999);
        _h["Inclusive_InvM_1300"]->fill(-999);
        _h["Inclusive_InvM_1400"]->fill(-999);
        _h["Inclusive_InvM_1500"]->fill(-999);
        _h["Inclusive_InvM_1600"]->fill(-999);
        _h["Inclusive_InvM_1700"]->fill(-999);
        _h["Inclusive_InvM_1800"]->fill(-999);
        _h["Inclusive_InvM_1900"]->fill(-999);
        _h["Inclusive_InvM_2000"]->fill(-999);
        _h["Inclusive_InvM_2100"]->fill(-999);
        _h["Inclusive_InvM_2200"]->fill(-999);
        _h["Inclusive_InvM_2300"]->fill(-999);
        _h["Inclusive_InvM_2400"]->fill(-999);
        _h["Inclusive_InvM_2500"]->fill(-999);
        _h["Inclusive_InvM_2600"]->fill(-999);
        _h["Inclusive_InvM_2700"]->fill(-999);
        _h["Inclusive_InvM_2800"]->fill(-999);
        _h["Inclusive_InvM_2900"]->fill(-999);
        _h["Inclusive_InvM_3000"]->fill(-999);
      }

      if ( sortedTopCands.size() > 3 ) {
        double InvM_ttbar34 = (sortedTopCands.at(2).momentum() + sortedTopCands.at(3).momentum() ).mass()/GeV;
        double pT_ttbar34 = (sortedTopCands.at(2).momentum() + sortedTopCands.at(3).momentum()).pT()/GeV;
        double dR_ttbar34 = fabs(deltaR(sortedTopCands.at(2),sortedTopCands.at(3)));

        _h["Inclusive_InvM_ttbar34"]->fill(InvM_ttbar34);
        _h["Inclusive_pT_ttbar34"]->fill(pT_ttbar34);
        _h["Inclusive_dR_ttbar34"]->fill(dR_ttbar34);
        _h["Inclusive_mTop3"]->fill(sortedTopCands.at(2).mass());
        _h["Inclusive_mTop4"]->fill(sortedTopCands.at(3).mass());
        _h["Inclusive_mTop3_zoomin"]->fill(topCands.at(2).mass());
        _h["Inclusive_mTop4_zoomin"]->fill(topCands.at(3).mass());
      } else{
        _h["Inclusive_InvM_ttbar34"]->fill(-999);
        _h["Inclusive_pT_ttbar34"]->fill(-999);
        _h["Inclusive_dR_ttbar34"]->fill(-999);
        _h["Inclusive_mTop3"]->fill(-999);
        _h["Inclusive_mTop4"]->fill(-999);
        _h["Inclusive_mTop3_zoomin"]->fill(-999);
        _h["Inclusive_mTop4_zoomin"]->fill(-999);
      }

      if (debug){
        MSG_INFO( "Number of top quark : " << sortedTopCands.size());
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
