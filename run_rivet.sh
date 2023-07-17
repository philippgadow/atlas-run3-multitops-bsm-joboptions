#!/bin/bash


# set DSID
DSID=${1}
if [[ -z ${DSID} ]]; then
    echo "DSID not provided, using 100000 as default.";
    DSID=100000;
fi

# center of mass energy (in GeV)
COMENERGY=${2}
if [[ -z ${COMENERGY} ]]; then
    echo "center of mass energy not provided, using 13000. as default.";
    COMENERGY=13000.;
fi

# random number generator seed
SEED=${3}
if [[ -z ${SEED} ]]; then
    echo "random seed not provided, using 1234 as default.";
    SEED=1234;
fi

# launch job
TAG=${DSID}_${COMENERGY/.*}GeV_${SEED}
RESULTDIR=$PWD/output/$TAG
TMPWORKDIR=/tmp/rivet_$TAG
RIVETDIR=$PWD/rivet/

rm -rf $TMPWORKDIR && mkdir -p $TMPWORKDIR
cd $TMPWORKDIR
athena $RIVETDIR/rivet.py --filesInput $RESULTDIR/test_DSID_${DSID}.EVNT.root

ls
pwd
cp $TMPWORKDIR/Rivet_tttt.yoda.gz $RESULTDIR/
rm -rf $TMPWORKDIR
cd -




