PROJECT(clab2019gscans)

cmake_minimum_required(VERSION 3.5)

foreach( cpp_program
        total_energy_spectrum_from_stdin
        total_time_energy_spectrum_from_stdin )
    add_executable(${cpp_program} Cpp/${cpp_program}.cpp)
    set_property(TARGET ${cpp_program} PROPERTY CXX_STANDARD 17)
    set_property(TARGET ${cpp_program} PROPERTY CXX_STANDARD_REQUIRED ON)
    target_include_directories(${cpp_program} PUBLIC Cpp)
endforeach()

configure_file(Bash/plot_total_energy_spectrum.sh plot_total_energy_spectrum.sh COPYONLY)
