theApp.EvtMax = -1

import AthenaPoolCnvSvc.ReadAthenaPool
from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from Rivet_i.Rivet_iConf import Rivet_i
rivet = Rivet_i()
import os
from os.path import join
rivet.AnalysisPath = join(os.environ['PWD'], 'rivet')

rivet.Analyses += [ 'tttt_parton', 'tttt_event' , 'tttt_ttH']
rivet.RunName = ''
rivet.HistoFile = 'Rivet_tttt.yoda.gz'
rivet.CrossSection = 1.0
#rivet.IgnoreBeamCheck = True
#rivet.SkipWeights=True
job += rivet
