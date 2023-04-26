#!bin/bash

# Job submission for DESY HTCondor - copy to project directory and adapt to your needs
JOBNAME="TRUTH1_bsm4tops"

DSIDS="100000" #DSIDs in job option directory

RUNTIME="03:00:00"         #Run time per job HH:MM:SS
MEMORY=2000                #Memory per job in MB
MODELSDIR=$PWD/models

cd batch_submission
COMMAND="python SubmitMC/python/submit_derivation.py --jobName ${JOBNAME} --engine HTCONDOR -r ${DSIDS} --noBuildJob --accountinggroup af-atlas --deriv_runtime ${RUNTIME} --deriv_memory ${MEMORY}"
echo $COMMAND
$COMMAND
