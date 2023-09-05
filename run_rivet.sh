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

# directories
INITIALDIR=$PWD
TAG=${DSID}_${COMENERGY/.*}GeV_${SEED}
RESULTDIR=$PWD/output/$TAG
TMPWORKDIR=/tmp/rivet_$TAG

# alternatively just provide input file
INPUTFILE=${4}
if [[ -z ${INPUTFILE} ]]; then
    echo "input path not provided, using information from parameters";
    INPUTFILE=$(readlink -f "$RESULTDIR/test_DSID_${DSID}.EVNT.root"); #get full path
else
    INPUTFILE=$(readlink -f "$INPUTFILE") #get full path
    mkdir -p $RESULTDIR
fi

echo $I


export RIVET_ANALYSIS_PATH=$RIVET_ANALYSIS_PATH:$PWD/rivet/

rm -rf $TMPWORKDIR && mkdir -p $TMPWORKDIR
cp rivet/rivet.py $TMPWORKDIR
cd $TMPWORKDIR

athena rivet.py --filesInput ${INPUTFILE}

cp $TMPWORKDIR/Rivet.yoda.gz $RESULTDIR/
rm -rf $TMPWORKDIR
cd $RESULTDIR
rivet-mkhtml --errs --no-weights -o rivet_plots Rivet.yoda.gz:Title="Rivet Plots"

cd $INITIALDIR
