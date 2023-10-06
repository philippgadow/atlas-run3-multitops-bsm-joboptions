From https://github.com/philippgadow/atlas-run3-multitops-bsm-joboptions/tree/main

# Development of job options in Atlas MC Generation for Multi-Top-Quark searches

## Run this example quickly
Run in release `AthGeneration,23.6.11`

List of releases: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgMcSoftware

```
git clone --recursive git@github.com:philippgadow/atlas-run3-multitops-bsm-joboptions.git
source setup.sh
bash run.sh
```
Arguments can be provided in the following order: DSID, number of events, COM energy (in GeV), random seed, input LHE file. 

## Batch submission
On DESY NAF modify `run_batch.sh` to include DSIDs of choice and run:

```
source setup.sh
bash run_batch.sh
```


## Make validation plots

Some rivet routines are included in this repo. To run, include the desired routines in `rivet.Analyses` in `rivet/rivet.py`. Then run
```bash run_rivet.sh```

To produce only the plots (run this from the directory where the `.yoda` file is found): 

```bash
# the setupRivet script is provided to the PATH after AthGeneration was setup, see e.g.
# /cvmfs/atlas.cern.ch/repo/sw/software/23.6/AthGeneration/23.6.11/InstallArea/x86_64-centos7-gcc11-opt/bin/setupRivet
source setupRivet

# single set of events
rivet-mkhtml --errs --no-weights  -o my_plots Rivet.yoda:"Title=validation plots"

# compare 13 TeV and 13.6 TeV samples
rivet-mkhtml --errs --no-weights  -o my_plots output/100400_13000GeV_372777/Rivet.yoda:"Title=sqrt(s)=13TeV" output/100400_13600GeV_126313/Rivet.yoda:"Title=sqrt(s)=13.6TeV"
```

## Overview of samples

### Signals

| DSID   | process      | mass | width | ct   | theta | decay chain                        | reweight |
| ------ | ------------ | ---- | ----- | ---- | ----- | ---------------------------------- | -------- |
| 100000 | ttZ' restt   | 1000 | AUTO  |  2.5 |  pi/4 | p > v1 t t~, v1 > t t~             | yes      |

| DSID   | process      | mass | width | tan beta | decay chain                      |
| ------ | ------------ | ---- | ----- | -------- | -------------------------------- |
| 100200 | ttH restt    |  400 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100201 | ttH restt    | 1000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100202 | ttH restt    | 2000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100300 | tjH 5FS      |  400 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100301 | tjH 5FS      | 1000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100302 | tjH 5FS      | 2000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100400 | tWH 5FS      | 400  | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100401 | tWH 5FS      | 1000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100402 | tWH 5FS      | 2000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100500 | tjH 4FS      |  400 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100501 | tjH 4FS      | 1000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100502 | tjH 4FS      | 2000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100600 | tWH 4FS      |  400 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100601 | tWH 4FS      | 1000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |
| 100602 | tWH 4FS      | 2000 | 5     |  10      | H > t t~, (t > w+ b, t~ > w- b~) |

### Backgrounds

#### Multi-top

| DSID   | r21 DSID | process | link to JO |
| ------ | -------- | ------- | ---------- |
| 100100 | 412043   | tttt (NLO) aMCPy8EG | [412043](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412043.aMcAtNloPythia8EvtGen_A14NNPDF31_SM4topsNLO.py) [`MadGraphControl_SM4topsNLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsNLO.py) |
| 100101 | 412043   | tttt (NLO) aMCHw7EG | [412044](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412044.aMcAtNloHerwig7EvtGen_H7UE_SM4topsNLO.py) [`MadGraphControl_SM4topsNLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsNLO.py) |
| 100102 | 412115   | tttt (LO) QCD | [412115](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412115.MadGraphPythia8EvtGen_A14NNPDF31_SM4topsLO.py) [`MadGraphControl_SM4topsLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsLO.py) |
| 100103 | 500326   | tttt (LO) QCD + EWK | [500326](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500326) |

#### ttH

| DSID   | r21 DSID | process | link to JO |
| ------ | -------- | ------- | ---------- |
| 101000 |          | ttH (semilep tt) PhPy8 | still testing |
| 101001 |          | ttH (semilep tt) PhH7  | still testing |
| 101002 |          | ttH (dilep tt) PhPy8   | still testing |
| 101002 |          | ttH (dilep tt) PhH7    | still testing |

#### rare tt+X

| DSID   | r21 DSID | process | link to JO |
| ------ | -------- | ------- | ---------- |
| 101004 | 410081   | ttWW | [410081](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID410xxx/MC15.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.py) [`MadGraphControl_ttVV_LO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_ttVV_LO.py) |
| 101005 | 500463   | ttWZ | [500463](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500463) |
| 101006 | 500460   | ttHH | [500460](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500460) |
| 101007 | 500461   | ttWH | [500461](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500461) |
| 101008 | 500462   | ttZZ | [500462](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500462) |
