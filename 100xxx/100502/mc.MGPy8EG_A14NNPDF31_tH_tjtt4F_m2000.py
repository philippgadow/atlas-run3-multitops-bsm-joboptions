import MadGraphControl.MadGraph_NNPDF30NLOnf4_Base_Fragment
from MadGraphControl.MadGraphUtils import *

str_param_card='MadGraph_2HDM_for_multitops_paramcard_2000_new.dat'

# Safe factor for events
nevents=int(8.0*runArgs.maxEvents)

#---------------------------------------------------------------------------
# MG5 Proc card
#---------------------------------------------------------------------------
process_string = """
set group_subprocesses Auto
set ignore_six_quark_processes False
set loop_optimized_output True
set gauge unitary
set complex_mass_scheme False
import model sm
define p = g u c d s u~ c~ d~ s~
define j = p
define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
import model 2HDMtypeII
generate p p > t j h2 b~ $$ w+ w-, (h2 > t t~, (t > b w+, w+ > wdec wdec), (t~ > b~ w-, w- > wdec wdec)), (t > b w+, w+ > wdec wdec)
add process p p > t~ j h2 b $$ w+ w-, (h2 > t t~, (t > b w+, w+ > wdec wdec), (t~ > b~ w-, w- > wdec wdec)), (t~ > b~ w-, w- > wdec wdec) 
output -f"""

#---------------------------------------------------------------------------
# MG5 Run Card
#---------------------------------------------------------------------------

#Fetch default LO run_card.dat and set parameters
extras = { 'lhe_version':'3.0',
           'cut_decays':'F',
           'nevents' : nevents}

process_dir = new_process(process_string)
modify_run_card(runArgs=runArgs,
                process_dir=process_dir,
                settings=extras)

modify_param_card(param_card_input=str_param_card,process_dir=process_dir)

print_cards()


#---------------------------------------------------------------------------
# MG5 Generation
#---------------------------------------------------------------------------
generate(process_dir=process_dir,runArgs=runArgs)

outputDS = arrange_output(
    process_dir=process_dir,
    runArgs=runArgs,
    lhe_version=3
)

#---------------------------------------------------------------------------
# Parton Showering Generation
#---------------------------------------------------------------------------
check_reset_proc_number(opts)

evgenConfig.generators  += [ "MadGraph"] 
evgenConfig.description = 'MadGraph_tttt'
evgenConfig.process= "p p ->t+j~+h2 -> t+j+t+t~"
evgenConfig.keywords+=['Higgs','jets']
evgenConfig.contact = ["philipp.gadow@cern.ch"]

evgenConfig.generators += ["Pythia8"]
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("Pythia8_i/Pythia8_MadGraph.py")

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = -1 #no-allhad
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.
