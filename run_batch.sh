#!bin/bash

# Job submission for DESY HTCondor - copy to project directory and adapt to your needs
JOBNAME="EVGEN_bsm4tops"
DSIDS="100000" #DSIDs in job option directory


EVENTS=10000               #Events per job
NJOBS=1                    #Number of jobs per DSID
RUNTIME="03:00:00"         #Run time per job HH:MM:SS
MEMORY=2000                #Memory per job in MB
MODELSDIR=$PWD/models

cd batch_submission
COMMAND="python SubmitMC/python/submit.py --jobName ${JOBNAME} --engine HTCONDOR --eventsPerJob ${EVENTS} --nJobs ${NJOBS} -r ${DSIDS} --noBuildJob --modelsDir ${MODELSDIR} --accountinggroup af-atlas --evgen_runtime ${RUNTIME} --evgen_memory ${MEMORY}"
echo $COMMAND
$COMMAND
