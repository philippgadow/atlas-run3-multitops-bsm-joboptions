#!/bin/bash

DSIDS="101004 101005 101006 101007 101008" #DSIDs in job option directory

EVENTS=10000               #Events per job

COMMAND="python batch_management/submit.py --eventsPerJob ${EVENTS} -d ${DSIDS}"
echo $COMMAND
$COMMAND
