#!/bin/bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh -q

# r21 most recent release
MYRELEASE="AthGeneration,21.6.106"

mkdir -p workdir
cd workdir
asetup ${MYRELEASE}
source setupRivet.sh
cd -
