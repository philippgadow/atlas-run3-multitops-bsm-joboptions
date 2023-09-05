from MadGraphControl.MadGraphUtils import *

# General settings
name="ttbarWH"
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
generate p p > t t~ w h
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
evgenConfig.contact = ["Philipp Gadow <paul.philipp.gadow@cern.ch>", "nedaa.asbah@cern.ch"]
evgenConfig.process = "pp > tt~WH"

# Finally, run the parton shower...
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
# ...and pull in MadGraph-specific stuff
include("Pythia8_i/Pythia8_MadGraph.py")


#include("Pythia8_i/Pythia8_SMHiggs125_inc.py")
# the Higgs decay part is added here

genSeq.Pythia8.Commands += [ '25:onMode = off',
                             '25:oneChannel = 1 0.5770   100 5 -5',
                             '25:addChannel = 1 0.0291   100 4 -4',
                             '25:addChannel = 1 0.000246 100 3 -3',
                             '25:addChannel = 1 0.00000  100 6 -6',
                             '25:addChannel = 1 0.000219 100 13 -13',
                             '25:addChannel = 1 0.0632   100 15 -15',
                             '25:addChannel = 1 0.0857   100 21 21',
                             '25:addChannel = 1 0.00228  100 22 22',
                             '25:addChannel = 1 0.00154  100 22 23',
                             '25:addChannel = 1 0.0264   100 23 23',
                             '25:addChannel = 1 0.2150   100 24 -24'
]

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = -1 #no-allhad
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.
