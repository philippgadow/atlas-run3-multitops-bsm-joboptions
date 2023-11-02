#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh -q

# r22 default release
MYRELEASE="AthGeneration,23.6.18"

mkdir -p workdir
cd workdir
asetup ${MYRELEASE}
source setupRivet
cd -
