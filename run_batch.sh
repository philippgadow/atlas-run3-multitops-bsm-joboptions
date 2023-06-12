#!/bin/bash

DSIDS="100200 100300 100400" #DSIDs in job option directory

EVENTS=1000               #Events per job

COMMAND="python batch_management/submit.py --eventsPerJob ${EVENTS} -d ${DSIDS}"
echo $COMMAND
$COMMAND
