#!/bin/bash

# enable model
export PYTHONPATH=$PWD/models:$PYTHONPATH

# set DSID
DSID=${1}
if [[ -z ${DSID} ]]; then
    echo "DSID not provided, using 100000 as default.";
    DSID=100000;
fi

# number of events
NEVENTS=1

# launch job
RESULTDIR=$PWD/output/$DSID
TMPWORKDIR=/tmp/evtgen_$DSID

mkdir -p $RESULTDIR

rm -rf $TMPWORKDIR && mkdir -p $TMPWORKDIR
cp -r ${DSID:0:3}xxx/$DSID $TMPWORKDIR/
cd $TMPWORKDIR
Gen_tf.py --ecmEnergy=13000. --firstEvent=1 --maxEvents=$NEVENTS --randomSeed=1234 --jobConfig=${DSID} --outputEVNTFile=test_DSID_${DSID}.EVNT.root --rivetAnas=MC_FSPARTICLES,MC_JETS,MC_ELECTRONS,MC_MUONS
ls
pwd
cp $TMPWORKDIR/test_DSID_${DSID}.EVNT.root $RESULTDIR/
cp $TMPWORKDIR//Rivet.yoda $RESULTDIR/
rm -rf $TMPWORKDIR
cd -
