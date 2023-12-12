#!/bin/bash

mkdir -p plots

SM4TOPS_OUTPUT=`ls output/100022_13000GeV_353862/Rivet.yoda.gz`

RIVET_OUTPUT=`ls output/100000_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1000 $RIVET_OUTPUT:"Title=ttH(tt) 1 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100001_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1100 $RIVET_OUTPUT:"Title=ttH(tt) 1.1 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100002_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1200 $RIVET_OUTPUT:"Title=ttH(tt) 1.2 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100003_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1300 $RIVET_OUTPUT:"Title=ttH(tt) 1.3 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100004_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1400 $RIVET_OUTPUT:"Title=ttH(tt) 1.4 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100005_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1500 $RIVET_OUTPUT:"Title=ttH(tt) 1.5 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100006_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_1600 $RIVET_OUTPUT:"Title=ttH(tt) 1.6 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100007_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_1700 $RIVET_OUTPUT:"Title=ttH(tt) 1.7 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100008_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_1800 $RIVET_OUTPUT:"Title=ttH(tt) 1.8 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100009_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_1900 $RIVET_OUTPUT:"Title=ttH(tt) 1.9 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100010_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_2000 $RIVET_OUTPUT:"Title=ttH(tt) 2 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100011_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2100 $RIVET_OUTPUT:"Title=ttH(tt) 2.1 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100012_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2200 $RIVET_OUTPUT:"Title=ttH(tt) 2.2 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100013_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2300 $RIVET_OUTPUT:"Title=ttH(tt) 2.3 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100014_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2400 $RIVET_OUTPUT:"Title=ttH(tt) 2.4 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100015_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_2500 $RIVET_OUTPUT:"Title=ttH(tt) 2.5 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100016_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2600 $RIVET_OUTPUT:"Title=ttH(tt) 2.6 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100017_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2700 $RIVET_OUTPUT:"Title=ttH(tt) 2.7 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100018_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2800 $RIVET_OUTPUT:"Title=ttH(tt) 2.8 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100019_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_2900 $RIVET_OUTPUT:"Title=ttH(tt) 2.9 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

# RIVET_OUTPUT=`ls output/100020_13000GeV_*/Rivet.yoda.gz`
# rivet-mkhtml --errs --no-weights  -o plots/ttH_3000 $RIVET_OUTPUT:"Title=ttH(tt) 3 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100023_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_1750 $RIVET_OUTPUT:"Title=ttH(tt) 1.75 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"

RIVET_OUTPUT=`ls output/100024_13000GeV_*/Rivet.yoda.gz`
rivet-mkhtml --errs --no-weights  -o plots/ttH_2250 $RIVET_OUTPUT:"Title=ttH(tt) 2.25 TeV" $SM4TOPS_OUTPUT:"Title=SM tttt (LO)"