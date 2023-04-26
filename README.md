## Development of job options in Atlas MC Generation for Multi-Top-Quark searches

### Run this example quickly
Run in release `AthGeneration,23.6,11`

List of releases: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgMcSoftware

```
git clone git@github.com:philippgadow/bsm4tops_joboptions.git
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

### Overview of samples

| DSID   | process | mass | width | ct   | theta | decay chain                        | reweight |
| ------ | ------- | ---- | ----- | ---- | ----- | ---------------------------------- | -------- |
| 100000 | restt   | 1000 | AUTO  |  2.5 |  pi/4 | p > v1 t t~, v1 > t t~             | yes      |
