import numpy as np 
import matplotlib.pyplot as plt

# Change these if running on a different sample
path = "./output/101004_13000GeV_232718/rivet_plots/ttX_ttVV/"
particle = "W"
title=particle + " branching ratios"

if particle == "W":
    ids_to_names = { 
            1. : "$d / \\bar{d}$"        ,  2. : "$u / \\bar{u}$"             ,  3. : "$s / \\bar{s}$", 
            4. : "$c / \\bar{c}$"        ,  5. : "$b / \\bar{b}$"             , 
            11. : "$e^{+} / e^{-}$"       , 13. : "$\\mu^{+} / \\mu^{-}}$"     , 15. : "$\\tau^{+} / \\tau^{-}$",
            12. : "$\\nu^{e}$"       , 14. : "$\\nu^{\\mu}$"     , 16. : "$\\nu^{\\tau}$",
            21. : "gg"                 , 22. : "$\\gamma\\gamma$"        , 
            23. : "ZZ"                 , 24. : "$W^{+}W^{-}$"            , 45.  : "$ZZ/\\gamma\\gamma/Z\\gamma$"
    } 

    theory = {  
            "$e^{+/-}\\nu$" : 0.1046, 
            "$\\mu^{+/-}\\nu$" : 0.1050, 
            "$\\tau^{+/-}\\nu$" : 0.1075,
            "qq" : 0.6832, 
    }

if particle == "Z":
    ids_to_names = { 
            1. : "$d / \\bar{d}$"        ,  2. : "$u / \\bar{u}$"             ,  3. : "$s / \\bar{s}$", 
            4. : "$c / \\bar{c}$"        ,  5. : "$b / \\bar{b}$"             , 
            11. : "$e^{+} / e^{-}$"       , 13. : "$\\mu^{+} / \\mu^{-}}$"     , 15. : "$\\tau^{+} / \\tau^{-}$",
            12. : "$\\nu^{e}$"       , 14. : "$\\nu^{\\mu}$"     , 16. : "$\\nu^{\\tau}$",
            21. : "gg"                 , 22. : "$\\gamma\\gamma$"        , 
            23. : "ZZ"                 , 24. : "$W^{+}W^{-}$"            , 45.  : "$ZZ/\\gamma\\gamma/Z\\gamma$"
    } 

    theory = {  
            "$e^{+}e^{-}}$" : 0.035, 
            "$\\mu^{+}\\mu^{-}}$" : 0.035, 
            "$\\tau^{+}\\tau^{-}$" : 0.035,
            "qq" : 0.683, 
            "$\\nu\\bar{\\nu}$" : 0.212, 
    }

if particle == "H":
    ids_to_names = { 
            1. : "$d\\bar{d}$"        ,  2. : "$u\\bar{u}$"             ,  3. : "$s\\bar{s}$", 
            4. : "$c\\bar{c}$"        ,  5. : "$b\\bar{b}$"             , 
            11. : "$e^{+}e^{-}$"       , 13. : "$\\mu^{+}\\mu^{-}}$"     , 15. : "$\\tau^{+}\\tau^{-}$",
            21. : "gg"                 , 22. : "$\\gamma\\gamma$"        , 
            23. : "ZZ"                 , 24. : "$W^{+}W^{-}$"            , 45.  : "$ZZ/\\gamma\\gamma/Z\\gamma$"
    } 

    theory = {  
            "$c\\bar{c}$" : 2.891,  
            "$b\\bar{b}$" : 58.24, 
            "$\\mu^{+}\\mu^{-}}$" : 0.02176, 
            "$\\tau^{+}\\tau^{-}$" : 6.272,
            "gg" : 8.187, 
            "$W^{+}W^{-}$" : 21.37, 
            "$ZZ/\\gamma\\gamma/Z\\gamma$"  : 2.9993
    }



# Extract info from dat file
filename = particle+"_decay.dat"
data = np.loadtxt(path+filename, skiprows=14) # Make sure to check that header is indeed 14 lines (excluding white spaces)
pdgids = data[:,0] + 0.5
nEvents = data[:,2]
decays = {pdgid: 0 for pdgid in np.unique(abs(pdgids))}
for i,pdgid in enumerate(pdgids):
    decays[abs(pdgid)] += nEvents[i]
decays.update({45.: decays[22]+decays[23]}) # Combine ZZ, yy, and Zy
decays.update({22.: 0.})
decays.update({23.: 0.})
branching_ratios = {ids_to_names[pdgid]: events/sum(decays.values()) for pdgid,events in decays.items() if events > 0}

# Plot pie chart
fig, ax = plt.subplots()
labels = [name + f" ({ratio*100.:1.2f}%)" for name,ratio in branching_ratios.items()]
wedges, labels = ax.pie(branching_ratios.values(), labels=labels, labeldistance=1.05)

# Set the text color of labels to match the color of wedges
for label, wedge in zip(labels, wedges):
    label.set_color(wedge.get_facecolor())
    if "$d\\bar{d}$" in label.get_text(): # Move ddbar label if present so that it doesn't overlap
        x, y = label.get_position()
        label.set_position((x+0.5, y))

plt.title(title)

# Text box for expected BRs
text_theory = "Expected:\n"
for name, percent in theory.items():
    text_theory += name + f": {percent:1.2f}%\n"
plt.text(0.02, 0.55, text_theory, horizontalalignment='left', verticalalignment='center', bbox=dict(facecolor='white', edgecolor='black', boxstyle='square,pad=0.5'), transform=fig.transFigure)

# Save plot
output = path + particle + "_decay_pie.png"
fig.savefig(output)
print(f"Made plot in {output}")
plt.close()


