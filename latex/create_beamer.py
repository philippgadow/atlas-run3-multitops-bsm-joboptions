"""
A python script which assembles plots from a directory and creates a LaTeX beamer presentation. The presentation will show plots for a number of samples. The directory is called "plots" and is a nested directory. It contains sub-directories, which each correspond a sample. Each same has a name like "ttH_1000", where "ttH_" is the same for each sample but the number which encodes the mass of a Higgs boson is different. Each sub-directory has the same content structure, two directories "tttt_ttH" and "tttt_ttH_1LOS" which contain the plots that should populate the slides. The slides should have the following structure: after a title slide, for each sample there will be one slide. The first slide will contain six plots which are located in the "plots/<sample>/tttt_ttH" directory. The layout will have three plots in the top row below the title and three plots in the bottom row. The filenames of the plots are "Inclusive_mH.png", "Inclusive_nTop.png", "Inclusive_nH.png", "Inclusive_InvM_ttbar12.png", "Inclusive_InvM_ttbar34.png", "Inclusive_dR_ttbar12.png". The second slide will contain six plots which are located in the "plots/<sample>/tttt_ttH_1LOS" directory. The layout will have three plots in the top row below the title and three plots in the bottom row. The filenames of the plots are "BaselineSR_HT_3.png", "BaselineSR_MET.png", "BaselineSR_centrality.png", "BaselineSR_deltaR_bl_min.png", "BaselineSR_nJets.png", "BaselineSR_nBjets.png".
This script plots all samples. It should populate the first slide only with six files. The filenames of the files are "Inclusive_mH.png", "Inclusive_nTop.png", "Inclusive_nH.png", "Inclusive_InvM_ttbar12.png", "Inclusive_InvM_ttbar34.png", "Inclusive_dR_ttbar12.png". Similarly, on the second slide, the only files which should be shown are "BaselineSR_HT_3.png", "BaselineSR_MET.png", "BaselineSR_centrality.png", "BaselineSR_deltaR_bl_min.png", "BaselineSR_nJets.png", "BaselineSR_nBjets.png".
"""
import os

def create_beamer_presentation():
    # Create the LaTeX beamer file
    with open("presentation.tex", "w") as f:
        # Write the title slide
        f.write("\\documentclass{beamer}\n")
        f.write("\\begin{document}\n")
        f.write("\\begin{frame}\n")
        f.write("\\title{Validation plots for ttH BSM high mass samples (s+t channel)}\n")
        f.write("\\author{Hui-Chi Lin (UMich), Meng-Ju Tsai (UMich), Philipp Gadow (CERN)}\n")
        f.write("\\date{\\today}\n")
        f.write("\\maketitle\n")
        f.write("\\end{frame}\n")


        # Add intro slide
        f.write("\\begin{frame}\n")
        f.write("\\frametitle{Introduction}\n")
        f.write("\\begin{itemize}\n")
        f.write("\\item Study of ttH signal samples on parton and particle/event level.\n")
        f.write("\\begin{itemize}\n")
        f.write("\\item Samples studied range from 1 TeV to 3 TeV with 100 GeV spacing in mass.\n")
        f.write("\\item Both s-channel and t-channel simulations were conducted.\n")
        f.write("\\item Utilized the release AthGeneration,21.6.106 for the generation of samples.\n")
        f.write("\\end{itemize}\n")
        f.write("\\item Link to the code used for producing results: \\url{https://github.com/philippgadow/atlas-run3-multitops-bsm-joboptions/tree/r21}\n")
        f.write("\\end{itemize}\n")
        f.write("\\end{frame}\n")

        # Table with signal parameters
        f.write("\\begin{frame}\n")
        f.write("\\frametitle{Signal Mass and Width}\n")
        f.write("\\begin{table}\n")
        f.write("\\begin{tabular}{cc}\n")
        f.write("\\textbf{Signal Mass} & \\textbf{Signal Width} \\\\\n")
        f.write("\\textbf{(GeV)} & \\textbf{(GeV)} \\\\\n")
        masses = [1000, 1100, 1200, 1300, 1400, 1500, 1750, 2000, 2250, 2500]
        widths = [30, 40, 40, 50, 50, 60, 90, 100, 110, 125]
        for mass, width in zip(masses, widths):
            f.write(f"{mass} & {width} \\\\\n")
        f.write("\\end{tabular}\n")
        f.write("\\end{table}\n")
        f.write("\\end{frame}\n")
        
        # Iterate over the samples
        samples_dir = "../plots"
        sample_whitelist = masses
        samples = [d for d in os.listdir(samples_dir) if os.path.isdir(os.path.join(samples_dir, d))]

        for sample in sorted(samples):
            sample_mass = sample.split("_")[1]
            if int(sample_mass) not in sample_whitelist:
                continue
            sample_dir = os.path.join(samples_dir, sample)
            
            # Write the slide for tttt_ttH plots
            f.write("\\begin{frame}\n")
            f.write("\\frametitle{Sample: " + sample.replace('_', ' ') + " GeV - parton level plots}\n")
            
            plots_dir = os.path.join(sample_dir, "tttt_ttH")
            plots = ["Inclusive_mH.png", "Inclusive_nTop.png", "Inclusive_nH.png", "Inclusive_InvM_ttbar12.png", "Inclusive_InvM_ttbar34.png", "Inclusive_dR_ttbar12.png"]
            
            # Write the plots in a 2x3 grid
            for i, plot in enumerate(plots):
                plotname = plot.replace("_", " ")[:-4]
                focus_mass_plot = False
                if focus_mass_plot:
                    if plot == "Inclusive_mH.png":
                        plot = "Inclusive_mH{0}.png".format(sample_mass)
                    if plot == "Inclusive_InvM_ttbar12.png":
                        plot = "Inclusive_InvM_{0}.png".format(sample_mass)

                if i % 3 == 0:
                    f.write("\\begin{columns}\n")
                f.write("\\column{0.3\\textwidth}\n")
                f.write("\\includegraphics[width=\\textwidth]{" + os.path.join(plots_dir, plot) + "}\\\\\n")
                f.write("\\textit{\\small " + plotname + "}\n")
                if i % 3 == 2:
                    f.write("\\end{columns}\n")           
            f.write("\\end{frame}\n")
            
            # Write the slide for tttt_ttH_1LOS plots
            f.write("\\begin{frame}\n")
            f.write("\\frametitle{Sample: " + sample.replace('_', ' ') + " GeV - event level plots}\n")
            
            plots_dir = os.path.join(sample_dir, "tttt_ttH_1LOS")
            plots = ["BaselineSR_HT_3.png", "BaselineSR_MET.png", "BaselineSR_centrality.png", "BaselineSR_deltaR_bl_min.png", "BaselineSR_nJets.png", "BaselineSR_nBjets.png"]
            
            # Write the plots in a 2x3 grid
            for i, plot in enumerate(plots):
                plotname = plot.replace("_", " ")[:-4]
                if i % 3 == 0:
                    f.write("\\begin{columns}\n")
                f.write("\\column{0.3\\textwidth}\n")
                f.write("\\includegraphics[width=\\textwidth]{" + os.path.join(plots_dir, plot) + "}\\\\\n")
                f.write("\\textit{\\small " + plotname + "}\n")
                if i % 3 == 2:
                    f.write("\\end{columns}\n")           
            f.write("\\end{frame}\n")
        
        f.write("\\end{document}\n")

# Call the function to create the beamer presentation
create_beamer_presentation()
