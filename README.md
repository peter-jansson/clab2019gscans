# clab2019gscans
Parsers and analysers of gamma-ray spectroscopy data from measurements on spent nuclear fuel at the central interim storage facility Clab in Sweden that is published in reference [1], structured into folders corresponding to the language or platform used.

![LGPL-3](https://www.gnu.org/graphics/lgplv3-with-text-154x68.png)

## Examples

To plot the energy spectrum of counts measured from the 45 degree corner of PWR01 on a file named "spectrum.svg", extract the data arvice and run the command:

`plot_total_energy_spectrum.sh "PWR01_start_2016-11-09 16.46.44_corner_45.txt" spectrum.svg`

To write the one-channel-count-per-row energy spectrum of counts measured from the 45 degree corner of PWR01 on a file named "spectrum.txt", extract the data archive and run the command:

`print_raw_total_energy_spectrum.sh "PWR01_start_2016-11-09 16.46.44_corner_45.txt" > spectrum.txt`

## References

[1] Jansson P., Bengtsson M., Bäckström U., Grape S., Branger E., Sjöland A.; "*Time stamped list mode data from gamma-ray spectroscopic measurements on 47 nuclear fuel assemblies performed at Clab, Sweden, September 2016 through March 2019*"; Journal: Data in Brief; Vol: 31; DOI: [10.1016/j.dib.2020.106039](http://dx.doi.org/10.1016/j.dib.2020.106039); (2020)
