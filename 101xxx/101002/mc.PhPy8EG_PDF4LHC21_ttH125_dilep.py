#--------------------------------------------------------------
# JO to be used with this input TXT container:
# mc21_13p6TeV.601453.Ph_PDF4LHC21_semilep_ttH125_LHE.evgen.TXT.e8453
#--------------------------------------------------------------

#--------------------------------------------------------------
# Pythia A14 tune
#--------------------------------------------------------------
include('Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py')
include("Pythia8_i/Pythia8_Powheg_Main31.py")

#--------------------------------------------------------------
# Pythia8 main31 
#--------------------------------------------------------------
genSeq.Pythia8.Commands += [ 'Powheg:NFinal = 3' ]
genSeq.Pythia8.Commands += [ 'Powheg:pTHard = 0' ]
genSeq.Pythia8.Commands += [ 'Powheg:pTdef = 2' ]
genSeq.Pythia8.Commands += [ 'Powheg:veto = 1' ]
genSeq.Pythia8.Commands += [ 'Powheg:vetoCount = 3' ]
genSeq.Pythia8.Commands += [ 'Powheg:pTemt  = 0' ]
genSeq.Pythia8.Commands += [ 'Powheg:emitted = 0' ]
genSeq.Pythia8.Commands += [ 'Powheg:MPIveto = 0' ]

#--------------------------------------------------------------
# EVGEN configuration
#--------------------------------------------------------------
evgenConfig.description    = 'POWHEG+Pythia8 ttH (dilep) production with A14 NNPDF2.3 tune'
evgenConfig.keywords       = [ 'SM', 'top', 'Higgs' ]
evgenConfig.contact        = [ 'elise.maria.le.boulicaut@cern.ch' ]
evgenConfig.generators     = [ 'Powheg', 'Pythia8', 'EvtGen' ]
evgenConfig.inputFilesPerJob = 5
evgenConfig.nEventsPerJob    = 20000

#--------------------------------------------------------------
# TTbarWToLeptonFilter
# 2l ttbar decay - input lhe files are inclusive
#--------------------------------------------------------------
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = 2 #(-1: non-all had, 0: all had, 1: l+jets, 2: dilepton)
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.0





