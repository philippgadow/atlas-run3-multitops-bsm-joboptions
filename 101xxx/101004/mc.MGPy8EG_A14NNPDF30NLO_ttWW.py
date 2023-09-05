from MadGraphControl.MadGraphUtils import *

# General settings
name="ttbarWW"
keyword=['SM','top','ttVV']
lhe_version = 3.0

# safe factor to generate sufficient events for filter
maxEvents = runArgs.maxEvents
runArgs.maxEvents *= 5

#---------------------------------------------------------------------------------------------------                                               
# Define MadGraph process                                                                                                                                 
#---------------------------------------------------------------------------------------------------    

process = """
import model sm
define p = g u c d s u~ c~ d~ s~
define j = g u c d s u~ c~ d~ s~
define w = w+ w-
generate p p > t t~ w w
output -f
"""

process_dir = new_process(process)

#---------------------------------------------------------------------------------------------------                                               
# Set PDF via base fragment                                                                                                                                 
#---------------------------------------------------------------------------------------------------    

import MadGraphControl.MadGraph_NNPDF30NLO_Base_Fragment

#---------------------------------------------------------------------------------------------------                                               
# Define run card                                                                                                                                   
#---------------------------------------------------------------------------------------------------                                               

extras = { 'lhe_version'  : lhe_version }
modify_run_card(process_dir=process_dir, runArgs=runArgs, settings=extras)

#---------------------------------------------------------------------------------------------------                                               
# Check cards and proceed with event generation                                                                                                                             
#---------------------------------------------------------------------------------------------------   

print_cards()
generate(process_dir=process_dir, runArgs=runArgs)
arrange_output(process_dir=process_dir, runArgs=runArgs, lhe_version=lhe_version)

#---------------------------------------------------------------------------------------------------                                               
# Storing information and post-processing with parton shower                                                                                                                            
#---------------------------------------------------------------------------------------------------   

runArgs.maxEvents = maxEvents
evgenConfig.description = 'MadGraph_'+str(name)
evgenConfig.keywords+=keyword 
evgenConfig.contact = ["Philipp Gadow <paul.philipp.gadow@cern.ch>"]
evgenConfig.process = "pp > tt~W+W-"

# Finally, run the parton shower...
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
# ...and pull in MadGraph-specific stuff
include("Pythia8_i/Pythia8_MadGraph.py")

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = -1 #no-allhad
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.
