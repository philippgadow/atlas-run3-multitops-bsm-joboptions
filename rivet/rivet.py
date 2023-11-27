from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()
from AthenaCommon.JobProperties import jobproperties

import AthenaPoolCnvSvc.ReadAthenaPool
from AthenaCommon.AppMgr import ServiceMgr as svcMgr
svcMgr.EventSelector.InputCollections = jps.AthenaCommonFlags.FilesInput()

from Rivet_i.Rivet_iConf import Rivet_i
import os
rivet = Rivet_i()
rivet.AnalysisPath = os.environ['PWD']

from os.path import join
rivet.AnalysisPath = join(os.environ['TestArea'], '..', 'rivet')
rivet.Analyses += ['tttt_ttH', 'tttt_ttH_1LOS']
rivet.RunName = ''
rivet.HistoFile = 'Rivet.yoda.gz'
job += rivet
