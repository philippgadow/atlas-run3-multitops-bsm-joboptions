#!/bin/bash

DSIDS="100103" #DSIDs in job option directory

EVENTS=10000               #Events per job

COMMAND="python batch_management/submit.py --eventsPerJob ${EVENTS} -d ${DSIDS}"
echo $COMMAND
$COMMAND
