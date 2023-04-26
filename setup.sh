#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh

MYRELEASE="AthGeneration,23.6,11"

rm -rf workdir
mkdir workdir
cp -r 100xxx/* workdir/
cd workdir
asetup ${MYRELEASE}
cd -
