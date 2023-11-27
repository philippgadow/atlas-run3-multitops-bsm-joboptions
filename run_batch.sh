#!/bin/bash

# range of DSID to run over from 100000 to 100020
DSIDS="100000 100001 100002 100003 100004 100005 100006 100007 100008 100009 100010 100011 100012 100013 100014 100015 100016 100017 100018 100019 100020"
 #DSIDs in job option directory

EVENTS=10000               #Events per job

COMMAND="python3 batch_management/submit.py --eventsPerJob ${EVENTS} -d ${DSIDS}"
echo $COMMAND
$COMMAND
