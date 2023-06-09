## Development of job options in Atlas MC Generation for Multi-Top-Quark searches

### Run this example quickly
Run in release `AthGeneration,23.6.11`

List of releases: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgMcSoftware

```
git clone --recursive git@github.com:philippgadow/atlas-run3-multitops-bsm-joboptions.git
source setup.sh
source run.sh
```

### Batch submission
On DESY NAF run:

```
source setup_batch.sh
source run_batch.sh
```

### Modify job option

Take the job option [`100xxx/100000/MadGraphControl_TopPhilicG_4t_v2.py`](https://github.com/philippgadow/bsm4tops_joboptions/blob/master/100xxx/100000/MadGraphControl_TopPhilicG_4t_v2.py) to implement your changes for testing.
All other copies of that job option are symlinks to this file.


### Make validation plots

With the generation event, also four rivet subroutines are launched:

- [MC_FSPARTICLES](https://rivet.hepforge.org/analyses/MC_FSPARTICLES.html)
- [MC_JETS](https://rivet.hepforge.org/analyses/MC_JETS.html)
- [MC_ELECTRONS](https://rivet.hepforge.org/analyses/MC_ELECTRONS.html)
- [MC_MUONS](https://rivet.hepforge.org/analyses/MC_MUONS.html)

You can plot the results with Rivet:

```bash
# the setupRivet script is provided to the PATH after AthGeneration was setup, see e.g.
# /cvmfs/atlas.cern.ch/repo/sw/software/23.6/AthGeneration/23.6.11/InstallArea/x86_64-centos7-gcc11-opt/bin/setupRivet
source setupRivet
rivet-mkhtml --errs --no-weights  -o my_plots Rivet.yoda:"Title=validation plots"
```

### Overview of samples

#### Signals

| DSID   | process | mass | width | ct   | theta | decay chain                        | reweight |
| ------ | ------- | ---- | ----- | ---- | ----- | ---------------------------------- | -------- |
| 100000 | restt   | 1000 | AUTO  |  2.5 |  pi/4 | p > v1 t t~, v1 > t t~             | yes      |


#### Backgrounds

| DSID   | r21 DSID | process | link to JO |
| ------ | -------- | ------- | ---------- |
| 100100 | 412043   | tttt (NLO) aMCPy8EG | [412043](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412043.aMcAtNloPythia8EvtGen_A14NNPDF31_SM4topsNLO.py) [`MadGraphControl_SM4topsNLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsNLO.py) |
| 100101 | 412043   | tttt (NLO) aMCHw7EG | [412044](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412044.aMcAtNloHerwig7EvtGen_H7UE_SM4topsNLO.py) [`MadGraphControl_SM4topsNLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsNLO.py) |
| 100102 | 412115   | tttt (LO) QCD | [412115](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/share/DSID412xxx/MC15.412115.MadGraphPythia8EvtGen_A14NNPDF31_SM4topsLO.py) [`MadGraphControl_SM4topsLO.py`](https://gitlab.cern.ch/atlas-physics/pmg/infrastructure/mc15joboptions/-/blob/master/common/MadGraph/MadGraphControl_SM4topsLO.py) |
| 100103 | 500326   | tttt (LO) QCD + EWK | [500326](https://gitlab.cern.ch/atlas-physics/pmg/mcjoboptions/-/tree/master/500xxx/500326) |

