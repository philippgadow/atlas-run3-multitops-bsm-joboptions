import os
import re
import csv
import argparse


def parse_arguments():
    """ Parse command line arguments. """
    parser = argparse.ArgumentParser(description='Scan the directory and extract cross-section and GenFiltEff from the log file.')
    parser.add_argument('-i', '--input', required=True, help='Input directory')
    parser.add_argument('-o', '--output', required=True, help='Output CSV file')
    return parser.parse_args()


def extract_data_from_log(file_path):
    """ Extract cross-section and GenFiltEff from the log file. """
    cross_section = None
    gen_filt_eff = None

    with open(file_path, 'r') as file:
        for line in file:
            if 'cross-section' in line:
                cross_section = re.search(r'cross-section \(nb\)= ([\d.e-]+)', line)
                if cross_section:
                    cross_section = cross_section.group(1)
            elif 'GenFiltEff' in line:
                gen_filt_eff = re.search(r'GenFiltEff = ([\d.e-]+)', line)
                if gen_filt_eff:
                    gen_filt_eff = gen_filt_eff.group(1)

    return cross_section, gen_filt_eff

def scan_directory(base_path, output_csv):
    """ Scan the directory, sort by filename, and write results to a CSV file. """
    data = []

    for root, dirs, files in os.walk(base_path):
        for file in files:
            if file == 'log.generate':
                file_path = os.path.join(root, file)
                cross_section, gen_filt_eff = extract_data_from_log(file_path)
                if cross_section and gen_filt_eff:
                    # Extract the directory name which matches the pattern
                    directory_name = re.search(r'(\d+_\d+GeV_\d+)', root)
                    if directory_name:
                        directory_name = directory_name.group(1)
                        data.append((directory_name, cross_section, gen_filt_eff))

    # Sort the data by the filename
    data.sort(key=lambda x: x[0])

    with open(output_csv, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['File Name', 'Cross-section', 'GenFiltEff'])
        csvwriter.writerows(data)

def main():
    """ Main function. """
    args = parse_arguments()
    scan_directory(args.input, args.output)


if __name__ == '__main__':
    main()
