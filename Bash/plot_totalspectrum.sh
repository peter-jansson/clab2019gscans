#!/bin/bash

# Script to plot, in SVG format, a total spectrum of counts
# out of the file from the data archive given as $1.
# The spectrum plot is written to file given as $2.
# Uses the C++ program ../Cpp/total_spectrum_from_stdin and curl.

F=spectrum.json

echo -n "[" > "${F}"
cat "$1" | ../Cpp/total_spectrum_from_stdin >> "${F}"
echo "]" >> "${F}"

curl -F "datafile=@${F}" \
     -F "plottype=spectrum" \
     -F "format=svg" \
     -F "xlabel=Channel"  \
     -F "ylabel=Count" \
     -F "yscale=log10" \
     https://jansson.net/apps/plot/ -o "$2"
