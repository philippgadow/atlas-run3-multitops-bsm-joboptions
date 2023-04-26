# resonance mass and width
mass=1000.0
width="auto"
# process ID
# - restt: pp > resonance tt > tttt
# - resjt: pp > resonance jt > jttt
# - reswt: pp > resonance Wt > Wttt
# - tttt: pp > tttt (including both resonant and non-resonant production, but ignoring SM4tops)
# - ttttsm: pp > tttt (including both resonant and non-resonant production, including SM4tops)
process_id="tttt"
# resonance coupling to top quarks
ct1=0.5
#  chirality parameter
from math import pi
theta1=pi/4.
reweight = False
include("MadGraphControl_TopPhilicG_4t_v2.py")
