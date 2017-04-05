#
# view_nanosleep_test.py [version 1.0]
#
# This script plots the results of nanosleep() testing.
# (nanosleep(): c/c++ function)
#
# It reads the results from nanosleep_test.dat.
# Run:
#  $ python3 run_nanosleep_test.py
# to generate nanosleep_test.dat
#
# read more on: www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.
#
import numpy as np
import matplotlib.pyplot as plt
import pickle


def main():

    # Load the results from a file and unpack them
    f = open("nanosleep_test.dat", "rb")
    dResults = pickle.load(f)
    f.close()
    lNanoSleepArgs = dResults['lNanoSleepArgs']
    ltAvg = dResults['ltAvg']
    lErrRel = dResults['lErrRel']

    # Plot the results: requested and real sleep times for nanosleep() function
    hFig = plt.figure(1)
    hSubPlot = hFig.add_subplot(111)
    hSubPlot.loglog(np.array(lNanoSleepArgs), np.array(ltAvg),
                    'g-', linewidth=2, label="real")
    hSubPlot.loglog(np.array(lNanoSleepArgs), np.array(lNanoSleepArgs),
                    'b-', linewidth=2, label="requested")
    hSubPlot.grid(True)  # Grid on
    hSubPlot.set_xlabel('nanosleep argument [ns]')
    hSubPlot.set_ylabel('time [ns]')
    strTitle = "the measured average sleep time and requested sleep time"
    hSubPlot.set_title(strTitle)
    hSubPlot.legend(loc="best")

    # Plot the results: relative errors
    hFig = plt.figure(2)
    hSubPlot = hFig.add_subplot(111)
    hSubPlot.loglog(np.array(lNanoSleepArgs), np.array(lErrRel), 'r-',
                    linewidth=2)
    hSubPlot.grid(True)
    hSubPlot.set_xlabel('nanosleep argument [ns]')
    hSubPlot.set_title("nanosleep relative error")

    plt.show(block=True)


if __name__ == "__main__":
    main()
