#
# view_usleep_test.py [version 1.0]
#
# This script plots the results of usleep() testing.
# (usleep(): c/c++ function)
#
# It reads the results from usleep_test.dat.
# Run:
#  $ ./run_usleep_test.py
# to generate usleep_test.dat
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
    f = open("usleep_test.dat", "rb")
    dResults = pickle.load(f)
    f.close()
    lUSleepArgs = dResults['lUSleepArgs']
    ltAvg = dResults['ltAvg']
    lErrRel = dResults['lErrRel']

    # Plot the results: requested and real sleep times for usleep() function
    hFig = plt.figure(1)
    hSubPlot = hFig.add_subplot(111)
    hSubPlot.loglog(np.array(lUSleepArgs), np.array(ltAvg),
                    'g-', linewidth=2, label="real")
    hSubPlot.loglog(np.array(lUSleepArgs), np.array(lUSleepArgs),
                    'b-', linewidth=2, label="requested")
    hSubPlot.grid(True)  # Grid on
    hSubPlot.set_xlabel('usleep argument [us]')
    hSubPlot.set_ylabel('time [us]')
    strTitle = "the measured average sleep time and requested sleep time"
    hSubPlot.set_title(strTitle)
    hSubPlot.legend(loc="best")

    # Plot the results: relative errors
    hFig = plt.figure(2)
    hSubPlot = hFig.add_subplot(111)
    hSubPlot.loglog(np.array(lUSleepArgs), np.array(lErrRel), 'r-', linewidth=2)

    hSubPlot.grid(True)
    hSubPlot.set_xlabel('usleep argument [us]')
    hSubPlot.set_title("relative error")

    plt.show(block=True)


if __name__ == "__main__":
    main()
