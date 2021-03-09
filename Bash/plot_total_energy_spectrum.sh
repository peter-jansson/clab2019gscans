#!/bin/bash

# Script to plot, in SVG format, a total energy spectrum of counts
# out of the file from the data archive given as $1.
# The spectrum plot is written to file given as $2.
# Uses the C++ program ../Cpp/total_energy_spectrum_from_stdin and curl.
# Remember to set the search path to total_energy_spectrum_from_stdin.

F=spectrum.json

echo -n "[" > "${F}"
cat "$1" | total_energy_spectrum_from_stdin >> "${F}"
echo "]" >> "${F}"

curl -F "datafile=@${F}" \
     -F "plottype=spectrum" \
     -F "format=svg" \
     -F "xlabel=Channel" \
     -F "ylabel=Count" \
     -F "yscale=log10" \
     https://apps.jansson.net/plot/ -o "$2"
