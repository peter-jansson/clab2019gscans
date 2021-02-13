PROJECT(clab2019gscans)

cmake_minimum_required(VERSION 3.5)

add_executable(total_spectrum_from_stdin Cpp/total_spectrum_from_stdin.cpp)
set_property(TARGET total_spectrum_from_stdin PROPERTY CXX_STANDARD 11)
set_property(TARGET total_spectrum_from_stdin PROPERTY CXX_STANDARD_REQUIRED ON)
target_include_directories(total_spectrum_from_stdin PUBLIC Cpp)

configure_file(Bash/plot_totalspectrum.sh plot_totalspectrum.sh COPYONLY)
