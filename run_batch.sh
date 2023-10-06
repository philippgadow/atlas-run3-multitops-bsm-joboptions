#!/bin/bash

#DSIDS="100200 100201 100202 100300 100301 100302 100400 100401 100402 100500 100501 100502 100600 100601 100602" #DSIDs in job option directory
DSIDS="100200 100500 100501 100502 100601 100602" #DSIDs in job option directory
# DSIDS="101004 101005 101006 101007 101008"
 #DSIDs in job option directory

EVENTS=10000               #Events per job

COMMAND="python batch_management/submit.py --eventsPerJob ${EVENTS} -d ${DSIDS}"
echo $COMMAND
$COMMAND
