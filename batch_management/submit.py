from argparse import ArgumentParser
from itertools import product
from condor_handler import CondorHandler
import os
import random


parser = ArgumentParser()
parser.add_argument("-d", "--dsids", nargs="+", default=[], type=int)
parser.add_argument(
    "--eventsPerJob",
    help="Events generated per job, default: 10_000",
    type=int,
    default=10_000,
)
parser.add_argument(
    "--ecmEnergy",
    help="Center of mass energy(s) default: [13_600., 13_000.]",
    type=float,
    nargs="+",
    # default=[13_600., 13_000.],
    default=[13_000.],
)
args = parser.parse_args()


batch_dir = os.path.join(os.getcwd(), "condor")
batch_path = os.path.join(batch_dir, "batch")
log_path = os.path.join(batch_dir, "batch_logs")
for item in [batch_path, log_path]:
    if not os.path.exists(item): os.makedirs(item)

handler = CondorHandler(batch_path, log_path)
handler['runtime'] = 259_199 # in seconds (7200 = 2h, 28_800 = 8h, 43_200 = 12h, 86_399 < 24h, 259_199 < 3d)
handler['memory'] = "8GB"
handler['cpu'] = 1
handler['project'] = "af-atlas"
## only for lxplus
# handler['jobflavour'] = "nextweek"

for dsid, com in product(args.dsids, args.ecmEnergy):
    seed = int(random.uniform(100000, 500000))
    tag = "evgen_{dsid}_{com}TeV_{seed}".format(dsid=dsid, com=int(com)*0.001, seed=seed)
    workdir = os.getcwd()

    command = "cd {0} && source {0}/setup.sh && bash {0}/run.sh ".format(workdir)
    command += " {dsid} {nevents} {com} {seed}".format(dsid=dsid, nevents=args.eventsPerJob, com=com, seed=seed)

    handler.send_job(command, tag)
