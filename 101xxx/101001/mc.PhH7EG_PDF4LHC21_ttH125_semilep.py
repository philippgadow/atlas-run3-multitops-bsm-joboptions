#--------------------------------------------------------------
# JO to be used with this input TXT container:
# mc21_13p6TeV.601453.Ph_PDF4LHC21_semilep_ttH125_LHE.evgen.TXT.e8453
#--------------------------------------------------------------

#--------------------------------------------------------------
# Herwig showering
#--------------------------------------------------------------
# initialize Herwig7 generator configuration for showering of LHE files
include("Herwig7_i/Herwig72_LHEF.py")

# configure Herwig7
Herwig7Config.me_pdf_commands(order="NLO", name="NNPDF30_nlo_as_0118")
Herwig7Config.tune_commands()
Herwig7Config.lhef_powhegbox_commands(lhe_filename=runArgs.inputGeneratorFile, me_pdf_order="NLO", usepwhglhereader=True)

# add EvtGen
include("Herwig7_i/Herwig71_EvtGen.py")

# run Herwig7
Herwig7Config.run()

#--------------------------------------------------------------
# EVGEN configuration
#--------------------------------------------------------------
evgenConfig.description = "POWHEG+HERWIG7 ttH (semilep) production"
evgenConfig.keywords    = [ 'SM', 'top', 'Higgs' ]
evgenConfig.contact     = [ 'elise.maria.le.boulicaut@cern.ch' ]
evgenConfig.generators  = [ 'Powheg','Herwig7' ]
evgenConfig.tune        = "H7.1-Default"
evgenConfig.inputFilesPerJob = 5
evgenConfig.nEventsPerJob    = 20000

#--------------------------------------------------------------
# TTbarWToLeptonFilter
# l+jets ttbar decay - input lhe files are inclusive
#--------------------------------------------------------------
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = 1 #(-1: non-all had, 0: all had, 1: l+jets, 2: dilepton)
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.0



