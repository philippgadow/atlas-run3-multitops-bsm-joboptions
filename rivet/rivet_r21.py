import AthenaPoolCnvSvc.ReadAthenaPool
from AthenaCommon.AppMgr import ServiceMgr as svcMgr
svcMgr.EventSelector.InputCollections = ["/nfs/dust/atlas/user/pgadow/multitop/data/evnt/mc15_13TeV.500463.MGPy8EG_A14NNPDF23LO_ttWZ.evgen.EVNT.e8041/EVNT.21001371._000038.pool.root.1"]

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from Rivet_i.Rivet_iConf import Rivet_i

import os
rivet = Rivet_i()
rivet.AnalysisPath = os.environ['PWD']

from os.path import join
rivet.AnalysisPath = join(os.environ['TestArea'], '..', 'rivet')
rivet.Analyses += ['ttX_ttVV']
rivet.RunName = ''
rivet.HistoFile = 'Rivet.yoda.gz'
job += rivet
