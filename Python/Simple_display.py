#A simple script to read the raw data, and plot a histogram of the data as a function of time.
#No corrections for dead-time,detector efficiency e.t.c. is made, only the raw data is handled
#Erik Branger

import sys
import os
import numpy as np
import matplotlib.pyplot as plt
import time
import math

if len(sys.argv) < 2:
    print("Usage: python Simple_display <input file name>")
    sys.exit(0)   
    
input_file = sys.argv[1]

plt.ion()

#sum up a number of frames into one histogram.
frames_per_draw = 16
current_frame = 0

#plot in linear or log scale
plot_logscale = True

file = open(input_file, 'r')

start_time = 0
end_time = 0

#to hold the pulse height values.
data_size = 10000 * frames_per_draw

data = data_size * [0]
data_index = 0

#Histogram bin edges.
bin_edges = range(0,4048,8)

#ymax will be dynamically adjusted to the maximum bin count seen so far.
#ymin requires adjustment based on if ti is a lin or log scale
ymax = 5000
ymin = 0
if plot_logscale == True:
    ymin = 1

plt.show()

for line in file:
    #Check for frame start
    if line.startswith("#"):
        if line.startswith("# Batch begin at live time "):
            #Record the start time of the batch
            start_time = line[27:]
            start_time = start_time[0:start_time.find(" ")]
            current_frame += 1
        
        if current_frame == frames_per_draw:
            #plot the histogram
            
            #make the histogram
            n, bins, patches = plt.hist(data[0:data_index], bins = bin_edges, histtype = 'stepfilled', log=plot_logscale)
            
            #for adjustign the y-axis to be more consistent
            if max(n) > ymax:
                ymax = max(n)
            
            #Draw the plot
            plt.title("Spectrum at t = " + str(math.floor(int(start_time) / 1000000)) + " seconds") #Well, the time is actually the start time of the last batch...
            plt.xlabel("Energy bin")
            plt.ylabel("Counts")
            plt.xlim(0,max(bin_edges))
            plt.ylim(ymin,ymax)
            plt.grid(True)
            plt.draw()
            
            #reset
            for i in range(0,data_index):
                data[i] = 0
                
            data_index = 0
            current_frame = 0
            
            #for updating the plot
            plt.pause(0.05)
            
    else:
        #Data!
        temp = line.split(',')
        data[data_index] = int(temp[1])
        data_index +=1

print("Finished!")