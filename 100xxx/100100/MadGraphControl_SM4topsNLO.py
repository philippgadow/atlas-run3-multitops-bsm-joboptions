from MadGraphControl.MadGraphUtils import *
import fileinput

### General settings

# Number of events
minevents = 10000
nevents = 11000

# PDF
pdflabel = 'lhapdf'
lhaid = 303400 # NNPDF31_nlo_as_0118

# MadSpin
bwcut = 15

# Parton showering and Systematics
syst = "True"
partShow = "PYTHIA8"

# Gridpacks
gridpack_mode=False
gridpack_dir=None
mode=0
runName='run_01'


#---------------------------------------------------------------------------
# MG5 process
#---------------------------------------------------------------------------

mgproc="""generate p p > t t~ t t~ [QCD]"""
name="SM4topsNLO"
process="pp>tt~tt~"
keyword=['SM','top','4top','NLO']
topdecay = "decay t > w+ b, w+ > all all \ndecay t~ > w- b~, w- > all all \n"
gridpack_mode=True
gridpack_dir='madevent/'

process_string = """
import model loop_sm-no_b_mass
define p = g u c d s b u~ c~ d~ s~ b~
define j = g u c d s b u~ c~ d~ s~ b~
"""+mgproc+"""
output -f
"""


#---------------------------------------------------------------------------
# MG5 Run Card
#---------------------------------------------------------------------------

#Fetch default LO run_card.dat and set parameters
extras = {
    'dynamical_scale_choice':10,
    'lhe_version'   : '3.0',
    'parton_shower' : partShow,
    'pdlabel'      : pdflabel,
    'lhaid'        : lhaid,
    'maxjetflavor' : 5,
    'reweight_scale' : syst,
    'reweight_PDF'   : syst,
    'PDF_set_min'    : 303401,
    'PDF_set_max'    : 303500,
    'nevents'        : nevents,
    }

process_dir = new_process(process=process_string)
modify_run_card(process_dir=process_dir, runArgs=runArgs, settings=extras)
print_cards()


#---------------------------------------------------------------------------
# Cook the setscales file for the user defined dynamical scale
#---------------------------------------------------------------------------

fileN = process_dir+'/SubProcesses/setscales.f'
mark  = '      elseif(dynamical_scale_choice.eq.10) then'
rmLines = ['ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc',
           'cc      USER-DEFINED SCALE: ENTER YOUR CODE HERE                                 cc',
           'cc      to use this code you must set                                            cc',
           'cc                 dynamical_scale_choice = 10                                   cc',
           'cc      in the run_card (run_card.dat)                                           cc',
           'ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc',
           'write(*,*) "User-defined scale not set"',
           'stop 1',
           'temp_scale_id=\'User-defined dynamical scale\' ! use a meaningful string',
           'tmp = 0d0',
           'ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc',
           'cc      USER-DEFINED SCALE: END OF USER CODE                                     cc',
           'ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc'
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
        newline = """
c         sum of the transverse mass divide by 2
c         m^2+pt^2=p(0)^2-p(3)^2=(p(0)+p(3))*(p(0)-p(3))
          tmp=0d0
          do i=3,nexternal
            tmp=tmp+dsqrt(max(0d0,(pp(0,i)+pp(3,i))*(pp(0,i)-pp(3,i))))
          enddo
          tmp=tmp/4d0
          temp_scale_id=\'H_T/4 := sum_i mT(i)/4, i=final state\'"""
        print(newline)


#---------------------------------------------------------------------------
# MadSpin Card
#---------------------------------------------------------------------------

madspin_card_loc='madspin_card.dat'

if not hasattr(runArgs, 'inputGenConfFile'):
    mscard = open('madspin_card.dat','w')
    mscard.write('import Events/'+runName+'/events.lhe.gz\n')
    mscard.write('set ms_dir MadSpin\n')
else:
    os.unlink(gridpack_dir+'Cards/madspin_card.dat')
    mscard = open(gridpack_dir+'Cards/madspin_card.dat','w')
    mscard.write('import '+gridpack_dir+'Events/'+runName+'/events.lhe.gz\n')
    mscard.write('set ms_dir '+gridpack_dir+'MadSpin\n')
    mscard.write('set seed '+str(10000000+int(runArgs.randomSeed))+'\n')
mscard.write("""set max_weight_ps_point 400
set Nevents_for_max_weigth 75
set BW_cut %i
%s
launch
"""%(bwcut, topdecay))
mscard.close()


#---------------------------------------------------------------------------
# MG5 Generation
#---------------------------------------------------------------------------

generate(process_dir=process_dir, runArgs=runArgs)
arrange_output(process_dir=process_dir, runArgs=runArgs, lhe_version=3, saveProcDir=True)


#---------------------------------------------------------------------------
# Parton Showering Generation
#---------------------------------------------------------------------------

if 'ATHENA_PROC_NUMBER' in os.environ:
    evgenLog.info('Noticed that you have run with an athena MP-like whole-node setup.  Will re-configure now to make sure that the remainder of the job runs serially.')
    njobs = os.environ.pop('ATHENA_PROC_NUMBER')
    if not hasattr(opts,'nprocs'): mglog.warning('Did not see option!')
    else: opts.nprocs = 0
    print(opts)

evgenConfig.generators += ["aMcAtNlo"]
evgenConfig.description = 'aMcAtNlo_'+str(name)
evgenConfig.keywords += keyword
#evgenConfig.inputfilecheck = outputDS
#evgenConfig.inputconfcheck = ""
evgenConfig.minevents = minevents
evgenConfig.contact = ['S. Berlendis <simon.berlendis@cern.ch>',
                       'P. Sabatini <paolo.sabatini@cern.ch>',
                       'L. Serkin <Leonid.Serkin@cern.ch>']
runArgs.inputGeneratorFile = outputDS

evgenConfig.generators += ["Pythia8"]
include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_aMcAtNlo.py")
# include("MC15JobOptions/Pythia8_ShowerWeights.py")
