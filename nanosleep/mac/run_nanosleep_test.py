#
# run_nanosleep_test.py [version 1.0]
#
# This script tests nanoslepp() (c/c++ function) for a number of time settings
# arguments and store the results in nanosleep_test.dat.
# To view the test results run:
#  $ python3 view_nanosleep_test.py
#
# read more on: www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.
#
import nanoxTest
import time
import numpy as np
import matplotlib.pyplot as plt
import pickle


def nanosleep_test(iSleepArg):
    """
    Run a single nanosleep() test.

    Arguments:
        iSleepArg:  [number]  time settings for nanosleep() function

    Return:
        tAvg_us:  [number]   the average time of a single nanosleep() call
        iErrRel:  [number]   the relative error between requested sleep time
                             and real sleep time
    """

    # Measure the average time of a single nanosleep() call
    tAvg_us = nanoxTest.run_test(int(iSleepArg))
    tAvg_ns = tAvg_us * 1000

    # Compute the relative error between real sleep time
    # and requested sleep time
    iErrRel = abs(tAvg_ns - iSleepArg) / iSleepArg

    return (tAvg_ns, iErrRel)


def plot_results(lNanoSleepArgs, ltAvg, lErrRel):
    """
    Plot results of the test. The function plots two figures:
        1. requested and real sleep times for nanosleep() function
        2. relative errors between requested sleep time and real sleep time

    Arguments:
        lNanoSleepArgs:  [list]  time settings for nanosleep() function
        ltAvg:        [list]  the average time of nanosleep() calls
        lErrRel:      [list]  the relative errors between requested sleep time
                              and real sleep time
    Return:
        none
    """

    # Plot the results: requested and real sleep times for nanosleep() function
    hFig = plt.figure(1)
    hSubPlot = hFig.add_subplot(111)
    hSubPlot.loglog(np.array(lNanoSleepArgs), np.array(ltAvg),
                    'g-', linewidth=2, label="real")
    hSubPlot.loglog(np.array(lNanoSleepArgs), np.array(lNanoSleepArgs), 'b-',
                    linewidth=2, label="requested")
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
    hSubPlot.set_title("relative error")

    plt.show(block=True)


def main():

    # SETTINGS: Arguments for nanosleep function
    lNanoSleepArgs = [1, 2, 3, 4, 5, 6, 7, 8, 9,                    # <  10 ns
                      1e1, 2e1, 3e1, 4e1, 5e1, 6e1, 7e1, 8e1, 9e1,  # < 100 ns
                      1e2, 2e2, 3e2, 4e2, 5e2, 6e2, 7e2, 8e2, 9e2,  # <   1 us
                      1e3, 2e3, 3e3, 4e3, 5e3, 6e3, 7e3, 8e3, 9e3,  # <  10 us
                      1e4, 2e4, 3e4, 4e4, 5e4, 6e4, 7e4, 8e4, 9e4,  # < 100 us
                      1e5, 2e5, 3e5, 4e5, 5e5, 6e5, 7e5, 8e5, 9e5,  # <   1 ms
                      1e6, 2e6, 3e6, 4e6, 5e6, 6e6, 7e6, 8e6, 9e6,  # <  10 ms
                      1e7, 2e7, 3e7, 4e7, 5e7, 6e7, 7e7, 8e7, 9e7   # < 100 ms
                     ]

    # SETTINGS: Plot after the tests are finished?
    bPlot = 1

    # Meaure total time of all tests - start the stopwatch
    tStart = time.time()

    # Measure average execution time for all the nanosleep arguments
    ltAvg = []    # List: average sleep times
    lErrRel = []  # List: relative errors between real and requested sleep time
    for iSleepArg in lNanoSleepArgs:  # Loop over all arguments for nanosleep()
        print("testing nanosleep with sleep time setting = %d [ns]" % iSleepArg)
        (tAvg, iErrRel) = nanosleep_test(iSleepArg)
        ltAvg.append(tAvg)
        lErrRel.append(iErrRel)

    # Measure the total time of test - stop the stopwatch
    tEnd = time.time() - tStart
    print("Tests were finished in %.1f seconds" % tEnd)

    # Dump the results to a file
    dResults = {}
    dResults['lNanoSleepArgs'] = lNanoSleepArgs
    dResults['ltAvg'] = ltAvg
    dResults['lErrRel'] = lErrRel
    f = open('nanosleep_test.dat', 'wb')
    pickle.dump(dResults, f)
    f.close()

    # Plot the measured average execution time and requested execution time
    if (bPlot == 1):
        plot_results(lNanoSleepArgs, ltAvg, lErrRel)

if __name__ == "__main__":
    main()
