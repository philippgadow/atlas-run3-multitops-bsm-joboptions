#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh -q

# ancient rivet version for r21
MYRELEASE="AthGeneration,21.6.33"

mkdir -p workdir
cd workdir
asetup ${MYRELEASE}
source setupRivet.sh
cd ../

# compile rivet analysi
cd rivet 
rivet-build RivetttX_ttVV.so plugins/ttX_ttVV_r21.cc
cd ../

# set DSID
DSID=${1}
if [[ -z ${DSID} ]]; then
    echo "DSID not provided, using 100000 as default.";
    DSID=100000;
fi

# center of mass energy (in GeV)
COMENERGY=13000.;

# random number generator seed
SEED=1234;

# directories
INITIALDIR=$PWD
TAG=${DSID}_${COMENERGY/.*}GeV_${SEED}
RESULTDIR=$PWD/output/$TAG
TMPWORKDIR=/tmp/rivet_$TAG
mkdir -p $RESULTDIR

# provide input file
INPUTFILE=${2}
INPUTFILE=$(readlink -f "$INPUTFILE") #get full path


export RIVET_ANALYSIS_PATH=$RIVET_ANALYSIS_PATH:$PWD/rivet/

rm -rf $TMPWORKDIR && mkdir -p $TMPWORKDIR
cp rivet/rivet_r21.py $TMPWORKDIR
cd $TMPWORKDIR

athena rivet_r21.py --filesInput ${INPUTFILE}

cp $TMPWORKDIR/Rivet.yoda.gz $RESULTDIR/
rm -rf $TMPWORKDIR
cd $RESULTDIR
rivet-mkhtml --errs --no-weights -o rivet_plots Rivet.yoda.gz:Title="Rivet Plots"

cd $INITIALDIR
