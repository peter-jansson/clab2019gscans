#!/bin/bash

# Script to write out the raw counts (one channel count per row) for the
# total energy spectrum of counts out of the file from the data archive
# given as $1.
# Uses the C++ program ../Cpp/total_energy_spectrum_from_stdin and curl.
# Remember to set the search path to total_energy_spectrum_from_stdin.

cat "$1" \
	| total_energy_spectrum_from_stdin \
	| sed -e 's/\[//g' -e 's/\]//g' -e 's/,/\n/g'
