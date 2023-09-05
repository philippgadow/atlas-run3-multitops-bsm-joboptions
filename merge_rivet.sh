#!/bin/bash

OUTPUTPATH="/eos/user/e/elebouli/ttH_mc23/output/" #Path to EVNT files
DSID="101001" #DSIDs in job option directory
ENERGY="13600" # COM energy
TITLE="ttH semilep PhH7"

export RIVET_ANALYSIS_PATH=$RIVET_ANALYSIS_PATH:$PWD/rivet/

mkdir -p output/${DSID}_${ENERGY}GeV_merged
cd output/${DSID}_${ENERGY}GeV_merged
COMMAND="rivet-merge -e ${OUTPUTPATH}/${DSID}_${ENERGY}GeV_*/Rivet.yoda.gz -o Rivet.yoda.gz"
$COMMAND
rivet-mkhtml --errs --no-weights -o rivet_plots Rivet.yoda.gz:Title="$TITLE"
cd -

