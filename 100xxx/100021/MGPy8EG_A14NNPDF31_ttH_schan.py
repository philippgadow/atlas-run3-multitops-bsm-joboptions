#---------------------------------------------------
# on-the-fly generation of FV heavy Higgs MG5 events
#---------------------------------------------------
from MadGraphControl.MadGraphUtils import *
import fnmatch
import os
import sys
from random import randrange

# Common factor working for all processes, minimum filter eff of the order of 30%
nevents=int(8.0*runArgs.maxEvents)
mode=0

# Initial pdf set NNPDF23_lo_as_0130_qed (247000)
import MadGraphControl.MadGraphUtils

# MadGraphControl.MadGraphUtils.MADGRAPH_PDFSETTING={
#     'central_pdf': 315000, # NNPDF31_lo_as_0118 as nominal pdf set
#     'pdf_variations':[315000], # NNPDF31_nnlo_as_0118 variations
#     'alternative_pdfs':[247000,263000,247000,315200], # NNPDF23_lo_as_0130_qed, NNPDF30_lo_as_0130, NNPDF30_lo_as_0118, NNPDF31_lo_as_0130
#     'scale_variations':[0.5,1,2], # muR and muF variations (6-points scale variations)
# }

beamEnergy=-999
if hasattr(runArgs,'ecmEnergy'):
    beamEnergy = runArgs.ecmEnergy / 2.
else:
    raise RuntimeError("No center of mass energy found.")

process_str="""
set group_subprocesses Auto
set ignore_six_quark_processes False
set loop_optimized_output True
set gauge unitary
set complex_mass_scheme False
import model sm
define p = g u c d s u~ c~ d~ s~
define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
import model 2HDMtypeII --modelname
generate p p > t t~ h2, (h2 > t t~, (t > b w+, w+ > wdec wdec), (t~ > b~ w-, w- > wdec wdec)), (t > b w+, w+ > wdec wdec), (t~ > b~ w-, w- > wdec wdec)
output -f
"""

#--------------------------------------------------------------
# Masses in GeV, plus model specific couplings
#--------------------------------------------------------------
###
# Parameters in the model parsed via JO
# MH
model_pars_str = str(jofile)
mh2=int(15000)
wh2=int(5)

for s in model_pars_str.split("_"):
    print('jobConfig fragment used to extract the model configuration '+s)
    if 'mh2' in s:
        ss=s.replace("mh2","")
        if ss.isdigit():
            mh2 = int(ss)
            print("BSM Higgs mass mh2 set to %i"%mh2)
    if 'wh2' in s:
        ss=s.replace("wh2","")
        if ss.isdigit():
            wh2 = int(ss)
            print("BSM Higgs mass wh2 set to %i"%wh2)


seed_num = randrange(500000)
print("hlin - random seed %i" % seed_num)

extras = { 'python_seed': str(seed_num),
           'lhe_version':'3.0',
           'cut_decays':'F',
           'nevents' :int(nevents),
           'pdlabel': 'lhapdf',
           'lhaid': 315000,
           'sys_pdf': 'NNPDF31_lo_as_0118',
           'use_syst' : "True",
           'sys_scalefact': '1 0.5 2'
           }

process_dir = new_process(process_str)
modify_run_card(process_dir=process_dir,runArgs=runArgs,settings=extras)

masses={'35':str(mh2)+' # mh2',
        '36':str(mh2),
        '37':str(mh2),
        '25':str(125),

        }
# parameters={'35':str(wh2)}
parameters={'35':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   9.941240e-01   2    6  -6 # 3.08868086759
   5.608530e-03   2    5  -5 # 0.0174253506876
   2.674649e-04   2    15  -15 # 0.000830996644579
""",
'36':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   9.984624e-01   2    6  -6 # 11.8612936543
   1.467645e-03   2    5  -5 # 0.0174349791549
   6.995181e-05   2    15  -15 # 0.000830996644579
""",
'37':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   9.999462e-01   2    6  -5 # 15.4587096386
   5.375300e-05   2    16  -15 # 0.000830996644579
"""}

frblock={'1':str(10)} # tanbeta = 10
higgs={'5':str(0)}

params={}
params['MASS']=masses
params['DECAY']=parameters
params['FRBLOCK']=frblock
params['HIGGS']=higgs

modify_param_card(process_dir=process_dir,params=params)

generate(process_dir=process_dir,runArgs=runArgs)
arrange_output(process_dir=process_dir,runArgs=runArgs,lhe_version=3,saveProcDir=True)

include('Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py')
include("Pythia8_i/Pythia8_MadGraph.py")

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
# Semi-leptonic decay filter
include('GeneratorFilters/TTbarWToLeptonFilter.py')
filtSeq.TTbarWToLeptonFilter.NumLeptons = -1 #no-allhad
filtSeq.TTbarWToLeptonFilter.Ptcut = 0.

evgenConfig.description = 'MadGraph control heavy Higgs, 4tops'
evgenConfig.keywords+=['Higgs','BSMHiggs']
evgenConfig.contact = ['Nicola Orlando <nicola.orlando@cern.ch>']
