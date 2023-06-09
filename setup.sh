#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh -q

MYRELEASE="AthGeneration,23.6.11"

rm -rf workdir
mkdir workdir
cd workdir
asetup ${MYRELEASE}
cd -
