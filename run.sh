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
NEVENTS=${2}
if [[ -z ${NEVENTS} ]]; then
    echo "number of events not provided, using 1 as default.";
    NEVENTS=1;
fi

# center of mass energy (in GeV)
COMENERGY=${3}
if [[ -z ${COMENERGY} ]]; then
    echo "center of mass energy not provided, using 13000. as default.";
    COMENERGY=13000.;
fi

# random number generator seed
SEED=${4}
if [[ -z ${SEED} ]]; then
    echo "random seed not provided, using 1234 as default.";
    SEED=1234;
fi


# launch job
TAG=${DSID}_${COMENERGY/.*}GeV_${SEED}
RESULTDIR=$PWD/output/$TAG
TMPWORKDIR=/tmp/evtgen_$TAG


export RIVET_ANALYSIS_PATH=$RIVET_ANALYSIS_PATH:$PWD/rivet/

mkdir -p $RESULTDIR
rm -rf $TMPWORKDIR && mkdir -p $TMPWORKDIR
cp -r ${DSID:0:3}xxx/$DSID $TMPWORKDIR/
cp -r mcjoboptions/${DSID:0:3}xxx/$DSID $TMPWORKDIR/ 
cd $TMPWORKDIR

Gen_tf.py --firstEvent=1 --maxEvents=$NEVENTS --ecmEnergy=$COMENERGY --randomSeed=$SEED \
--jobConfig=${DSID} --outputEVNTFile=test_DSID_${DSID}.EVNT.root \
--rivetAnas=tttt_parton,tttt_event
# --rivetAnas=MC_FSPARTICLES,MC_JETS,MC_ELECTRONS,MC_MUONS
ls
pwd
cp $TMPWORKDIR/test_DSID_${DSID}.EVNT.root $RESULTDIR/
cp $TMPWORKDIR/Rivet.yoda $RESULTDIR/
cat log.generate
# rm -rf $TMPWORKDIR
cd -
