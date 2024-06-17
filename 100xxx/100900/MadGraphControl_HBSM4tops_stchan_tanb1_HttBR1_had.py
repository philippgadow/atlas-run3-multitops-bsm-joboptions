#---------------------------------------------------
# on-the-fly generation of FV heavy Higgs MG5 events
#---------------------------------------------------
from MadGraphControl.MadGraphUtils import *
import MadGraphControl.MadGraph_NNPDF30NLO_Base_Fragment
import fileinput

# Common factor working for all processes, minimum filter eff of the order of 30%
nevents=int(8.0*runArgs.maxEvents)
mode=0

process_str="""
set group_subprocesses Auto
set ignore_six_quark_processes False
set loop_optimized_output True
set gauge unitary
set complex_mass_scheme False
import model sm
define p = g u c d s b u~ c~ d~ s~ b~
define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
import model 2HDMtypeII --modelname
generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2
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

extras = { 'lhe_version':'3.0',
           'cut_decays':'F',
           'nevents' :int(nevents),
           'event_norm':"sum",
           'dynamical_scale_choice':0
         }

process_dir = new_process(process_str)
modify_run_card(process_dir=process_dir,runArgs=runArgs,settings=extras)

#---------------------------------------------------------------------------
# Cook the setscales file for the user defined dynamical scale
#---------------------------------------------------------------------------

fileN = process_dir+'/SubProcesses/setscales.f'
mark  = '      elseif(dynamical_scale_choice.eq.0) then'
rmLines = ['ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc',
           'cc      USER-DEFINED SCALE: ENTER YOUR CODE HERE                                 cc',
           'cc      to use this code you must set                                            cc',
           'cc                 dynamical_scale_choice = 0                                    cc',
           'cc      in the run_card (run_card.dat)                                           cc',
           'write(*,*) "User-defined scale not set"',
           'stop 1',
           'temp_scale_id=\'User-defined dynamical scale\' ! use a meaningful string',
           'tmp = 0',
           'cc      USER-DEFINED SCALE: END OF USER CODE                                     cc',
           'stop 21',
           'rscale = 0'
           ]

flag=0
for line in fileinput.input(fileN, inplace=1):
    toKeep = True
    for rmLine in rmLines:
        if line.find(rmLine) >= 0:
           toKeep = False
           break
    if toKeep:
        print(line),
    if line.startswith(mark) and flag==0:
        flag +=1
        print("""
c         sum of the transverse mass divide by 4
c         m^2+pt^2=p(0)^2-p(3)^2=(p(0)+p(3))*(p(0)-p(3))
          rscale=0d0
          do i=3,nexternal
            rscale=rscale+dsqrt(max(0d0,(P(0,i)+P(3,i))*(P(0,i)-P(3,i))))
          enddo
          rscale=rscale/4d0
     """)


masses={'35':str(mh2)+' # mh2',
        '36':str(mh2),
        '37':str(mh2),
        '25':str(125),
        '24':str(8.039900e+01),
        '6' :str(1.725000e+02), # top mass gets set in 2 places
        }

# parameters={'35':str(wh2)}
parameters={'25':str(4.1e-03), # SM higgs width is 4.1 MeV
'6':str(1.320000e+00),
'35':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   1   2    6  -6 # 3.08868086759
""",
'36':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   1   2    6  -6 # 11.8612936543
""",
'37':
str(wh2)+"""
#  BR             NDA  ID1    ID2   ...
   1   2    6  -5 # 15.4587096386
"""}

sminputs={'1':str(1.323489e+02),
          '2':str(1.166370e-05),
          '3':str(1.184000e-01)
         }

yukawa={'6':str(1.725000e+02)}

frblock={'1':str(0.785398163)} # tanbeta = 1
higgs={'5':str(0)} # mixh = pi/2-(beta-alpha)=the angle that is zero for alignment limit


params={}
params['MASS']=masses
params['DECAY']=parameters
params['SMINPUTS']=sminputs
params['YUKAWA']=yukawa
params['FRBLOCK']=frblock
params['HIGGS']=higgs

modify_param_card(process_dir=process_dir,params=params)


#---------------------------------------------------------------------------
# MadSpin Card
#---------------------------------------------------------------------------

bwcut = 15
topdecay = "decay t > w+ b, w+ > wdec wdec \ndecay t~ > w- b~, w- > wdec wdec \n"

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
set max_weight_ps_point 400  # number of PS to estimate the maximum for each event
set BW_cut %i
set seed %i
define p = g u c d s b u~ c~ d~ s~ b~
define wdec = e+ mu+ ta+ e- mu- ta- ve vm vt ve~ vm~ vt~ g u c d s b u~ c~ d~ s~ b~
%s
launch
"""%(bwcut, runArgs.randomSeed, topdecay))
mscard.close()


#---------------------------------------------------------------------------
# MG5 Generation
#---------------------------------------------------------------------------

generate(process_dir=process_dir,runArgs=runArgs)
arrange_output(process_dir=process_dir,runArgs=runArgs,lhe_version=3)

include('Pythia8_i/Pythia8_A14_NNPDF23LO_EvtGen_Common.py')
include("Pythia8_i/Pythia8_MadGraph.py")

#--------------------------------------------------------------
# Event filter
#--------------------------------------------------------------
### Set lepton filters
if not hasattr(filtSeq, "MultiLeptonFilter" ):
   from GeneratorFilters.GeneratorFiltersConf import MultiLeptonFilter
   lepfilter = MultiLeptonFilter("lepfilter")
   filtSeq += lepfilter


filtSeq.lepfilter.Ptcut = 12000.0 #MeV
filtSeq.lepfilter.Etacut = 2.8
filtSeq.lepfilter.NLeptons = 1 #minimum



filtSeq.Expression = "(!lepfilter)"


evgenConfig.description = 'MadGraph control heavy Higgs, 4tops'
evgenConfig.keywords+=['Higgs','BSMHiggs']
evgenConfig.contact = ['Hui-Chi Lin <hlin@cern.ch>']
