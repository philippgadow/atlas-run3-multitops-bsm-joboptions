#!/bin/bash

# global settings
RUNRIVET=1 # set to 0 if you do not wish the run rivet right after evgen.
MAKERIVETPLOTS=0 # set to 1 if you wish to produce the rivet plots and html files (must have RUNRIVET=1), otherwise set to 0
RIVETTITLE="ttH/A plots" # if using MAKERIVETPLOTS

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

# Input LHE file
INPUTGENFILE=${5}
if [[ -z ${INPUTGENFILE} ]]; then
    echo "input generator file not provided, running without it.";
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
# copy directory with mother job option as well

# copy 100000 job options if DSID is not 100000
if [[ $DSID -ne 100000 ]]; then
    echo "DSID is not 100000, copying 100000 job options"
    cp -r 100xxx/100000/ $TMPWORKDIR/
fi
# copy 100021 job options if DSID is not 100021
if [[ $DSID -ne 100021 ]]; then
    echo "DSID is not 100021, copying 100021 job options"
    cp -r 100xxx/100021/ $TMPWORKDIR/
fi
cp rivet/rivet.py $TMPWORKDIR
if [[ -f "${INPUTGENFILE}" ]]; then
  cp -r ${INPUTGENFILE} $TMPWORKDIR/
fi
cd $TMPWORKDIR

# Run event generation
COMMAND="Gen_tf.py --firstEvent=1 --maxEvents=$NEVENTS --ecmEnergy=$COMENERGY --randomSeed=$SEED \
  --jobConfig=${DSID} --outputEVNTFile=test_DSID_${DSID}.EVNT.root"
if [[ -f "${INPUTGENFILE}" ]]; then
   COMMAND+=" --inputGeneratorFile=${INPUTGENFILE}"
fi
$COMMAND

# Run rivet
if [[ $RUNRIVET -eq 1 ]]; then
    rm PoolFileCatalog.xml
    athena rivet.py --filesInput test_DSID_${DSID}.EVNT.root
    cp Rivet.yoda.gz $RESULTDIR/
fi 

# Diagnostics
ls
pwd

# copy results over
cp $TMPWORKDIR/test_DSID_${DSID}.EVNT.root $RESULTDIR/
cp $TMPWORKDIR/Rivet.yoda $RESULTDIR/
cat log.generate
cp $TMPWORKDIR/log.generate $RESULTDIR/
rm -rf $TMPWORKDIR
cd -

# Generate the rivet plots
if [[ $MAKERIVETPLOTS -eq 1 ]]; then
    cd $RESULTDIR
    rivet-mkhtml --errs --no-weights -o rivet_plots Rivet.yoda.gz:Title=$RIVETTITLE
    cd -
fi
