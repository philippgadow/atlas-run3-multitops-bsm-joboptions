#! /usr/bin/env pythonrun
from MadGraphControl.MadGraphUtils import *
from itertools import product
from math import pi, sqrt, sin

#---------------------------------------------------------------------------------------------------                                               
# Set parameters                                                                                                                                   
#---------------------------------------------------------------------------------------------------                                               
lhe_version = 3.0

# Set defaults if parameters are not set in entry level job option
try:
  mass
except NameError:
  mass = 1500.0
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="resonance mass (mass)", default=mass))
try:
  width
except NameError:
  width = "auto"
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="resonance width (width)", default=width))
try:
  ct1
except NameError:
  ct1 = 1.0
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="resonance coupling to top quarks (ct1)", default=ct1))
try:
  theta1
except NameError:
  theta1 = pi / 4.
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="chirality parameter (theta1)", default=theta1))
try:
  process_id
except NameError:
  process_id = "restt"
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="Process type (process_id: restt, resjt, or reswt)", default=process_id))

try:
  reweight
except NameError:
  reweight = True
  print('Warning: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="Reweighting enabled flag", default=reweight))

print("Job option parameters:")
print("- resonance mass {p}".format(p=mass))
print("- resonance width {p}".format(p=width))
print("- resonance coupling to top quarks {p}".format(p=ct1))
print("- chirality parameter {p}".format(p=theta1))
print("- process ID {p}".format(p=process_id))
print("- ME reweighting enabled {p}".format(p=reweight))


# MadGraph PDF base fragment + definitions for 4FS and 5FS
doFiveFlavourScheme = True
model = "Top-Philic_UFO_V1_v2-no_b_mass"
protoncontent = "g u c d s u~ c~ d~ s~ b b~"
if process_id in ['resjt_4f', 'reswt_4f', 'ttjt_4f', 'ttwt_4f']:
  import MadGraphControl.MadGraph_NNPDF30NLOnf4_Base_Fragment
  doFiveFlavourScheme = False
  model = "Top-Philic_UFO_V1_v2"
  protoncontent = "g u c d s u~ c~ d~ s~"
else:
  import MadGraphControl.MadGraph_NNPDF30NLO_Base_Fragment

extras = {'auto_ptj_mjj':'False',
          'maxjetflavor':'5' if doFiveFlavourScheme else '4',
          'asrwgtflavor': '5' if doFiveFlavourScheme else '4',
          'event_norm':'sum',
          'cut_decays':'F', 
          'dynamical_scale_choice':3,
          }

parameters = {
    'mass':{
        'Mv1': mass,
    },
    'decay':{
        'Wv1': width,
    },
    'v0params': {
      'ct1': ct1,
    },
    'v1params': {
      'theta1': theta1
    }
}

# this could be changed if event multipliers were ever needed
nevents=runArgs.maxEvents
if (nevents <0):
  nevents=10000

#---------------------------------------------------------------------------------------------------                                               
# Determine MadGraph process                                                                                                                                 
#---------------------------------------------------------------------------------------------------                                               
process_string = {
 "restt": "generate p p > t t~ v1/v1, v1 > t t~",
 "resjt": "generate p p > top j v1/v1, v1 > t t~",
 "resjt_4f": "generate p p > top j bottom v1/v1, v1 > t t~",
 "reswt": "generate p p > top w v1/v1, v1 > t t~",
 "reswt_4f": "generate p p > top w bottom v1/v1, v1 > t t~",
 "tttt": "generate p p > t t~ t t~ QCD<=2 Qv1==2 QED==0",
 "ttttsm": "generate p p > t t~ t t~ QCD<=4 Qv1<=2 QED<=2",
 "ttjt": "generate p p > t t~ j top QCD<=2 Qv1==2",
 "ttwt": "generate p p > t t~ w top / h Z a w+ w-",
 "ttjt_4f": "generate p p > t t~ j top bottom QCD<=2 Qv1==2 QED==0",
 "ttwt_4f": "generate p p > t t~ w top bottom QCD<=2 Qv1==2",
}

process = """
set stdout_level DEBUG
import model {model}
define p = {protoncontent}
define j = {protoncontent}
define top = t t~
define bottom = b b~
define w = w+ w-
{process_string}
output -f""".format(
  process_string=process_string[process_id],
  model=model,
  protoncontent=protoncontent,
)

process_dir = new_process(process)

#---------------------------------------------------------------------------------------------------                                               
# Define run card                                                                                                                                   
#---------------------------------------------------------------------------------------------------                                               
modify_run_card(process_dir=process_dir, runArgs=runArgs, settings=extras)

#---------------------------------------------------------------------------------------------------                                               
# Define parameter card                                                                                                                             
#---------------------------------------------------------------------------------------------------                                               
modify_param_card(process_dir=process_dir, params={k:v for (k,v) in parameters.items()})

#---------------------------------------------------------------------------------------------------                                               
# Add reweight card, therefore allowing for scans of theta1 and ct1
#---------------------------------------------------------------------------------------------------                

def compute_width(mass, ct, theta):
  mtop = 173.1
  return (ct**2 * mass / (8 * pi)) * \
         sqrt(1 - ((4 * mtop**2) / (mass**2))) * \
         (1 - ((mtop**2) / (mass**2)) * (1 - 3 * sin(2 * theta)))


if reweight:
  ct1_scan = [0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50, 2.75, 3.00, 3.50, 4.00, 4.50, 5.00]
  theta1_scan = [0., 1./8.*pi, 2./8.*pi, 3./8.*pi, 4./8.*pi, 5./8.*pi, 6./8.*pi, 7./8.*pi, pi]

  reweightCommand=""
  for i_ct1, i_theta1 in product(ct1_scan, theta1_scan):
    reweightCommand += "launch --rwgt_name=rwgt_ct_{ct1_str}_theta_{theta1_str}\n".format(
      ct1_str=str(i_ct1).replace('.', 'p'), theta1_str="{0:.2f}".format(i_theta1).replace('.', 'p')
    )
    reweightCommand += "set v0params 1 {ct1}\n".format(ct1=i_ct1)
    reweightCommand += "set v1params 1 {theta1}\n".format(theta1=i_theta1)
    width = compute_width(mass, i_ct1, i_theta1)
    reweightCommand += "set decay 6000055 {width}\n\n".format(width=width)

  rcard = open(os.path.join(process_dir,'Cards', 'reweight_card.dat'), 'w')
  rcard.write(reweightCommand)
  rcard.close()

#---------------------------------------------------------------------------------------------------                                               
# Check cards and proceed with event generation                                                                                                                             
#---------------------------------------------------------------------------------------------------   
print_cards()
generate(process_dir=process_dir, runArgs=runArgs)
arrange_output(process_dir=process_dir, runArgs=runArgs, lhe_version=lhe_version)

#---------------------------------------------------------------------------------------------------                                               
# Storing information and post-processing with parton shower                                                                                                                            
#---------------------------------------------------------------------------------------------------   
# Some more information
evgenConfig.description = "pp -> tttt, ttjt and ttWt signal points with top-philic V1 resonance"
evgenConfig.keywords = ["exotic", "BSM", "RandallSundrum", "warpedED"]
evgenConfig.contact = ["Philipp Gadow <paul.philipp.gadow@cern.ch>"]
evgenConfig.process = "pp>ttv1> tttt"  # e.g. pp>G*>WW>qqqq

# Finally, run the parton shower...
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")

# ...and pull in MadGraph-specific stuff
include("Pythia8_i/Pythia8_MadGraph.py")
