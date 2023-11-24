From https://github.com/philippgadow/atlas-run3-multitops-bsm-joboptions/tree/main

# Development of job options in Atlas MC Generation for Multi-Top-Quark searches

**Modified to run for ttH/A r21 sample production**

## Run this example quickly
Run in release `AthGeneration,21.6.106`

List of releases: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgMcSoftware

```
git clone --recursive git@github.com:philippgadow/atlas-run3-multitops-bsm-joboptions.git
git checkout r21
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
source setupRivet.sh

# single set of events
rivet-mkhtml --errs --no-weights  -o my_plots Rivet.yoda:"Title=validation plots"

# compare 13 TeV and 13.6 TeV samples
rivet-mkhtml --errs --no-weights  -o my_plots output/100400_13000GeV_372777/Rivet.yoda:"Title=sqrt(s)=13TeV" output/100400_13600GeV_126313/Rivet.yoda:"Title=sqrt(s)=13.6TeV"
```

## Overview of samples

### Signals

| DSID   | process      | mass | width | decay chain                        |
| ------ | ------------ | ---- | ----- | ---------------------------------- |
| 100000 | ttH (s+t ch) | 1000 | 30  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100001 | ttH (s+t ch) | 1100 | 40  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100002 | ttH (s+t ch) | 1200 | 45  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100003 | ttH (s+t ch) | 1300 | 50  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100004 | ttH (s+t ch) | 1400 | 60  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100005 | ttH (s+t ch) | 1500 | 75  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100006 | ttH (s+t ch) | 1600 | 80  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100007 | ttH (s+t ch) | 1700 | 85  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100008 | ttH (s+t ch) | 1800 | 90  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100009 | ttH (s+t ch) | 1900 | 95  | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100010 | ttH (s+t ch) | 2000 | 100 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100011 | ttH (s+t ch) | 2100 | 105 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100012 | ttH (s+t ch) | 2200 | 110 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100013 | ttH (s+t ch) | 2300 | 115 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100014 | ttH (s+t ch) | 2400 | 120 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100015 | ttH (s+t ch) | 2500 | 125 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100016 | ttH (s+t ch) | 2600 | 130 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100017 | ttH (s+t ch) | 2700 | 135 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100018 | ttH (s+t ch) | 2800 | 140 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100019 | ttH (s+t ch) | 2900 | 145 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
| 100020 | ttH (s+t ch) | 3000 | 150 | generate p p > t t~ t t~ / a h3 h1 z QCD=2 QED=2, (t > b w+, w+ > wdec wdec) |
