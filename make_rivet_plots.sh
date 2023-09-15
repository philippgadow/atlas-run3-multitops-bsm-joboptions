#!/bin/bash

mkdir -p plots

rivet-mkhtml --errs --no-weights  -o plots/ttWW \
    output/101004_13000GeV_232718/Rivet.yoda.gz:"Title=ttWW sqrt(s)=13TeV" \
    output/101004_13600GeV_211691/Rivet.yoda.gz:"Title=ttWW sqrt(s)=13.6TeV" \
    output/410081_13000GeV_1234/Rivet.yoda.gz:"Title=ttWW MC16"

rivet-mkhtml --errs --no-weights  -o plots/ttWZ \
    output/101005_13000GeV_205354/Rivet.yoda.gz:"Title=ttWZ sqrt(s)=13TeV" \
    output/101005_13600GeV_352296/Rivet.yoda.gz:"Title=ttWZ sqrt(s)=13.6TeV" \
    output/500463_13000GeV_1234/Rivet.yoda.gz:"Title=ttWZ MC16"

rivet-mkhtml --errs --no-weights  -o plots/ttHH \
    output/101006_13000GeV_169702/Rivet.yoda.gz:"Title=ttHH sqrt(s)=13TeV" \
    output/101006_13600GeV_276325/Rivet.yoda.gz:"Title=ttHH sqrt(s)=13.6TeV" \
    output/500460_13000GeV_1234/Rivet.yoda.gz:"Title=ttHH MC16"

rivet-mkhtml --errs --no-weights  -o plots/ttWH \
    output/101007_13000GeV_214083/Rivet.yoda.gz:"Title=ttWH sqrt(s)=13TeV" \
    output/101007_13600GeV_157325/Rivet.yoda.gz:"Title=ttWH sqrt(s)=13.6TeV" \
    output/500461_13000GeV_1234/Rivet.yoda.gz:"Title=ttWH MC16"

rivet-mkhtml --errs --no-weights  -o plots/ttZZ \
    output/101008_13000GeV_196065/Rivet.yoda.gz:"Title=ttZZ sqrt(s)=13TeV" \
    output/101008_13600GeV_251554/Rivet.yoda.gz:"Title=ttZZ sqrt(s)=13.6TeV" \
    output/500462_13000GeV_1234/Rivet.yoda.gz:"Title=ttZZMC16"
