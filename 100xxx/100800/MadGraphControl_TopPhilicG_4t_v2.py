#! /usr/bin/env pythonrun
from MadGraphControl.MadGraphUtils import *
from itertools import product
from math import pi, sqrt, sin
from re import findall
#---------------------------------------------------------------------------------------------------
# Set parameters
#---------------------------------------------------------------------------------------------------                                               
lhe_version = 3.0
safefactor = 6
development_mode=False

# get job option name to extract parameters
from MadGraphControl.MadGraphUtilsHelpers import get_physics_short
shortname = get_physics_short()

# infer parameters from structure of job option unless they are explicitly set
# assumed structure of JO name: mc.MGPy8EG_ttZp_{process}_m{mass}_ct{coupling}_th{chirality}.py
process_ids = {
  'restt': 'resonant s-channel production of BSM resonance: tt + Zp, Zp > tt',
  'resjt': 'resonant s-channel production of BSM resonance: tj + Zp, Zp > tt',
  'reswt': 'resonant s-channel production of BSM resonance: tW + Zp, Zp > tt',
  'tttt': 'BSM four top quark production with resonance, tt + tt considering both s- and t-channel processes',
  'ttjt': 'BSM four top quark production with resonance, tj + tt',
  'ttwt': 'BSM four top quark production with resonance, tw + tt',
  'ttttsm': 'SM+BSM four top quark production with resonance, considering both s- and t-channel processes',
}
try:
  process_id
except NameError:
  try:
    process_id = findall(r"ttZp_([tsmrejw]+)", shortname)[0]
  except IndexError:
    print('Fatal: {parameter} not set. Could also not infer it from job option name. Fix the job option.'.format(
    parameter="Process type: choose from " + ', '.join(process_ids.keys())))
    raise RuntimeError
try:
  mass
except NameError:
  try:
    mass = int(findall(r"m([0-9]+)", shortname)[0])
  except IndexError:
    print('Fatal: {parameter} not set. Could also not infer it from job option name. Fix the job option.'.format(
    parameter="resonance mass (mass)"))
    raise RuntimeError
try:
  ct1
except NameError:
  try:
    ct1 = re.findall(r"ct([0-9,p]+)", shortname)[0]
    # convert 'p' in string to '.' and return float
    ct1 = float(ct1.replace('p', '.'))
  except IndexError:
    print('Fatal: {parameter} not set. Could also not infer it from job option name. Fix the job option.'.format(
    parameter="resonance coupling to top quarks (ct1)"))
    raise RuntimeError
try:
  theta1
except NameError:
  try:
    theta1 = re.findall(r"th([0-9,p]+)", shortname)[0]
    # convert 'p' in string to '.' and return float
    theta1 = float(theta1.replace('p', '.'))
  except IndexError:
    print('Fatal: {parameter} not set. Could also not infer it from job option name. Fix the job option.'.format(
    parameter="chirality parameter (theta1)"))
    raise RuntimeError
try:
  width
except NameError:
  width = "auto"
  print('Info: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="resonance width (width)", default=width))
try:
  reweight
except NameError:
  reweight = True
  print('Info: {parameter} not set. Setting it to default value of {default}'.format(
    parameter="Reweighting enabled flag", default=reweight))

# check if process is defined
try:
  assert(process_id in process_ids.keys())
except AssertionError:
  print('Fatal: wrong process type, choose from: ' + ', '.join(process_ids.keys()))

# print summary of options
print("Job option parameters:")
print("- process ID {p}".format(p=process_id))
print("- process description: " + process_ids[process_id])
print("- resonance mass {p}".format(p=mass))
print("- resonance coupling to top quarks {p}".format(p=ct1))
print("- chirality parameter {p}".format(p=theta1))
print("- resonance width {p}".format(p=width))
print("- ME reweighting enabled {p}".format(p=reweight))


#---------------------------------------------------------------------------------------------------
# Set PDF via base fragment and set parameters
#---------------------------------------------------------------------------------------------------
import MadGraphControl.MadGraph_NNPDF30NLO_Base_Fragment

extras = {'auto_ptj_mjj':'False',
          'maxjetflavor':'5',
          'event_norm':'average',
          'cut_decays':'F', 
          'dynamical_scale_choice':3,
          }

# set bwcutoff to 15
extras['bwcutoff'] = 15

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

# apply multiplicative safe-factor to number of generated events
nevents=int(runArgs.maxEvents * safefactor)
if (nevents <0): nevents = 10000
extras['nevents'] = nevents

#---------------------------------------------------------------------------------------------------
# Determine MadGraph process
#---------------------------------------------------------------------------------------------------
v1_decay_string = ", (v1 > t t~, (t > w+ b, w+ > wdec wdec), (t~ > w- b~, w- > wdec wdec))"
top_decay_string = ", (t > w+ b, w+ > wdec wdec)"
antitop_decay_string = ", (t~ > w- b~, w- > wdec wdec)"
wp_decay_string = ", (w+ > wdec wdec)"
wm_decay_string = ", (w- > wdec wdec)"

process_string = {
 "restt": "generate p p > t t~ v1" + v1_decay_string + top_decay_string + antitop_decay_string,
 "resjt": "generate p p > t j v1" + v1_decay_string + top_decay_string + "\n" + \
          "add process p p > t~ j v1" + v1_decay_string + antitop_decay_string,
 "reswt": "generate p p > t~ w+ v1" + v1_decay_string + antitop_decay_string + wp_decay_string + "\n" + \
          "add process p p > t w- v1" + v1_decay_string + top_decay_string + wm_decay_string,
 "tttt": "generate p p > t t~ t t~ QCD=2 QED=0 Qv1=2 / a h z ",
 "ttjt": "generate p p > t t~ t j QCD=0 QED=2 Qv1=2" + "\n" + \
          "add process p p > t t~ t~ j QCD=0 QED=2 Qv1=2",
 "ttwt": "generate p p > t t~ t~ w+ QCD=1 QED=1 Qv1=2" + "\n" + \
          "add process p p > t t~ t w- QCD=1 QED=1 Qv1=2",
 "ttttsm": "generate p p > t t~ t t~ QCD=4 QED=2 Qv1=2",
}

# reweighting is not supported for resonant processes
if process_id in ["restt", "resjt", "reswt"]:
  reweight = False

process = """
import model Top-Philic_UFO_V1_v3-nobmass
# import model Top-Philic_UFO_V1_v2
define p = g u c d s u~ c~ d~ s~ b b~
define j = g u c d s u~ c~ d~ s~ b b~
define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
{process_string}
output -f""".format(process_string=process_string[process_id])

process_dir = new_process(process, keepJpegs=development_mode)

#---------------------------------------------------------------------------------------------------
# Define run card
#---------------------------------------------------------------------------------------------------
modify_run_card(process_dir=process_dir, runArgs=runArgs, settings=extras)

#---------------------------------------------------------------------------------------------------
# Define parameter card
#---------------------------------------------------------------------------------------------------
# apply PMG settings for top quark and SM particles
from MadGraphControl.MadGraphParamHelpers import set_top_params
mtop=172.5
set_top_params(process_dir=process_dir, mTop=mtop,FourFS=False)

modify_param_card(process_dir=process_dir, params={k:v for (k,v) in parameters.items()})

# ---------------------------------------------------------------------------
# MadSpin Card
# ---------------------------------------------------------------------------
if process_id in ['tttt', 'ttjt', 'ttwt', 'ttttsm']:
  bwcut = extras['bwcutoff']
  madspin_card_loc=process_dir+'/Cards/madspin_card.dat'
  mscard = open(madspin_card_loc,'w')
  mscard.write("""#************************************************************
  #*                        MadSpin                           *
  #*                                                          *
  #*    P. Artoisenet, R. Frederix, R. Rietkerk, O. Mattelaer *
  #*                                                          *
  #*    Part of the MadGraph5_aMC@NLO Framework:              *
  #*    The MadGraph5_aMC@NLO Development Team - Find us at   *
  #*    https://server06.fynu.ucl.ac.be/projects/madgraph     *
  #*                                                          *
  #************************************************************
  set max_weight_ps_point 450  # number of PS to estimate the maximum for each event
  set BW_cut %i
  set seed %i
  define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
  decay t > w+ b, w+ > wdec wdec
  decay t~ > w- b~, w- > wdec wdec
  decay w+ > wdec wdec
  decay w- > wdec wdec 
  launch
  """%(bwcut, runArgs.randomSeed))
  mscard.close()

#---------------------------------------------------------------------------------------------------
# Add reweight card, therefore allowing for scans of theta1 and ct1
#---------------------------------------------------------------------------------------------------                
def compute_width(mass, ct, theta, mtop=172.5):
  return (ct**2 * mass / (8 * pi)) * \
         sqrt(1 - ((4 * mtop**2) / (mass**2))) * \
         (1 - ((mtop**2) / (mass**2)) * (1 - 3 * sin(2 * theta)))

if reweight:
  ct1_scan = [1.00, 1.50, 2.00, 2.50, 3.00, 3.50, 4.00, 4.50]
  theta1_scan = [0., 1./4.*pi, 2./4.*pi, 3./4.*pi, pi]
  if development_mode: # reduced scan for development
    ct1_scan = [1.00, 2.00, 3.00, 4.00]
    theta1_scan = [0., 2./8.*pi, 4./8.*pi]

  reweightCommand = "change rwgt_dir rwgt\n"
  reweightCommand+= "change keep_ordering True\n"
  reweightCommand+= "change helicity True\n"
  for i_ct1, i_theta1 in product(ct1_scan, theta1_scan):
    reweightCommand += "launch --rwgt_info=rwgt_ct_{ct1_str}_theta_{theta1_str} --rwgt_name=rwgt_ct_{ct1_str}_theta_{theta1_str}\n".format(
      ct1_str=str(i_ct1).replace('.', 'p'), theta1_str="{0:.2f}".format(i_theta1).replace('.', 'p')
    )
    reweightCommand += "set v0params 1 {ct1}\n".format(ct1=i_ct1)
    reweightCommand += "set v1params 1 {theta1}\n".format(theta1=i_theta1)
    width = compute_width(mass, i_ct1, i_theta1, mtop)
    reweightCommand += "set decay 32 {width}\n".format(width=width)
    # reweightCommand += "set decay 6000055 {width}\n".format(width=width)

  reweight_card   = os.path.join(process_dir,'Cards', 'reweight_card.dat')
  rcard = open(reweight_card, 'w')
  rcard.write(reweightCommand)
  rcard.close()

#---------------------------------------------------------------------------------------------------
# Check cards and proceed with event generation
#---------------------------------------------------------------------------------------------------   
print_cards(reweight_card=reweight_card if reweight else None)
generate(process_dir=process_dir, runArgs=runArgs)
arrange_output(process_dir=process_dir, runArgs=runArgs, lhe_version=lhe_version, saveProcDir=development_mode)

#--------------------------------------------------------------
# Storing information
#--------------------------------------------------------------
# Some more information
evgenConfig.description = process_ids[process_id]
evgenConfig.keywords = ["exotic", "BSM", "RandallSundrum", "warpedED"]
evgenConfig.contact = ["James Ferrando <james.ferrando@desy.de>", "Philipp Gadow <paul.philipp.gadow@cern.ch>"]
evgenConfig.process = "pp>ttv1>tttt"  # e.g. pp>G*>WW>qqqq

#--------------------------------------------------------------
# Parton shower
#--------------------------------------------------------------
# Finally, run the parton shower...
include("Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")

# ...and pull in MadGraph-specific stuff
include("Pythia8_i/Pythia8_MadGraph.py")

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
### Set lepton filters
if not hasattr(filtSeq, "MultiLeptonFilter" ):
   from GeneratorFilters.GeneratorFiltersConf import MultiLeptonFilter
   lepfilter_leading = MultiLeptonFilter("lepfilter_leading")
   filtSeq += lepfilter_leading
   lepfilter = MultiLeptonFilter("lepfilter")
   filtSeq += lepfilter
if not hasattr(filtSeq, "LeptonPairFilter" ):
   from GeneratorFilters.GeneratorFiltersConf import LeptonPairFilter
   lepPairfilter = LeptonPairFilter("lepPairfilter")
   filtSeq += lepPairfilter


filtSeq.lepfilter_leading.Ptcut = 25000.0 #MeV
filtSeq.lepfilter_leading.Etacut = 2.8
filtSeq.lepfilter_leading.NLeptons = 1 #minimum

filtSeq.lepfilter.Ptcut = 12000.0 #MeV
filtSeq.lepfilter.Etacut = 2.8
filtSeq.lepfilter.NLeptons = 2 #minimum


# no requirement on the OS pairs
filtSeq.lepPairfilter.NSFOS_Max = -1 
filtSeq.lepPairfilter.NSFOS_Min = -1
filtSeq.lepPairfilter.NOFOS_Max = -1
filtSeq.lepPairfilter.NOFOS_Min = -1


filtSeq.lepPairfilter.NSFSS_Min = 0 # at least 0 SFSS pairs with NPairSum_Min which will give at least 1 SS pair
filtSeq.lepPairfilter.NOFSS_Min = 0 # at least 0 OSSS pairs with NPairSum_Min which will give at least 1 SS pair
filtSeq.lepPairfilter.NSFSS_Max = -1 # no requirement on max of SS pairs
filtSeq.lepPairfilter.NOFSS_Max = -1 # no requirement on max of SS pairs

# Count number of SS pair 
filtSeq.lepPairfilter.UseSFSSInSum = True
filtSeq.lepPairfilter.UseOFSSInSum = True
filtSeq.lepPairfilter.UseSFOSInSum = False # no requirement on the OS pairs
filtSeq.lepPairfilter.UseOFOSInSum = False # no requirement on the OS pairs

# At least >=1 SS pair
filtSeq.lepPairfilter.NPairSum_Min = 1 # at least 1 SS pairs
filtSeq.lepPairfilter.NPairSum_Max = -1 # at least 1 SS pairs


# Require the event have leptons from resonant decays but not heavy flavor decays (>20 GeV cut on the resonance...)
# However, it will find the first parent particle 
filtSeq.lepPairfilter.OnlyMassiveParents = False 

filtSeq.lepPairfilter.Ptcut = 12000.0 #MeV
filtSeq.lepPairfilter.Etacut = 2.8

filtSeq.lepPairfilter.NLeptons_Min = 2
filtSeq.lepPairfilter.NLeptons_Max = -1 # No max of leptons 

filtSeq.Expression = "(lepfilter_leading and lepfilter and lepPairfilter)"
