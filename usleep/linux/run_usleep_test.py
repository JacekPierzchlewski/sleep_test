#
# run_usleep_test.py [version 1.0]
#
# This script tests usleep() (c/c++ function) for a number of
# arguments and store the results in usleep_test.dat.
# To view the test results run:
#  $ view_usleep_test.py
#
# read more on: www.orange-engineer.com
#
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.
#
import usxTest
import time
import numpy as np
import matplotlib.pyplot as plt
import pickle


def usleep_test(iSleepArg):
    """
    Run a single usleep() test.

    Arguments:
        iSleepArg:  [number] argument for usleep() function

    Return:
        tAvg_us:  [number]  the average time of a single usleep() call
        iErrRel:  [number]  the relative error between requested sleep time
                            and real sleep time
    """

    # Measure the average time of a single usleep() call
    tAvg_us = usxTest.run_test(int(iSleepArg))

    # Compute the relative error between real sleep time
    # and requested sleep time
    iErrRel = abs(tAvg_us - iSleepArg) / iSleepArg

    return (tAvg_us, iErrRel)


def plot_results(lUSleepArgs, ltAvg, lErrRel):
    """
    Plot results of the test. The function plots two figures:
        1. requested and real sleep times for usleep() function
        2. relative errors between requested sleep time and real sleep time

    Arguments:
        lUSleepArgs:  [list]  arguments for usleep() function
        ltAvg:        [list]  the average time of usleep() calls
        lErrRel:      [list]  the relative errors between requested sleep time
                              and real sleep time

    Return:
        none
    """

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
    hSubPlot.set_title("usleep relative error")

    plt.show(block=True)


def main():

    # SETTINGS: Arguments for usleep function
    lUSleepArgs = [1, 2, 3, 4, 5, 6, 7, 8, 9,
                   1e1, 2e1, 3e1, 4e1, 5e1, 6e1, 7e1, 8e1, 9e1,  # <   100 us
                   1e2, 2e2, 3e2, 4e2, 5e2, 6e2, 7e2, 8e2, 9e2,  # <  1000 us
                   1e3, 2e3, 3e3, 4e3, 5e3, 6e3, 7e3, 8e3, 9e3,  # <    10 ms
                   1e4, 2e4, 3e4, 4e4, 5e4, 6e4, 7e4, 8e4, 9e4,  # <   100 ms
                   1e5, 2e5, 3e5, 4e5, 5e5, 6e5, 7e5, 8e5, 9e5]  # <     1 s

    # SETTINGS: Plot after the tests are finished?
    bPlot = 1

    # Meaure total time of all tests - start the stopwatch
    tStart = time.time()

    # Measure average execution time for all the usleep arguments
    ltAvg = []    # List: average sleep times
    lErrRel = []  # List: relative errors between real and requested sleep time
    for iSleepArg in lUSleepArgs:    # Loop over all arguments for usleep()
        print("testing usleep(%d)" % iSleepArg)
        (tAvg, iErrRel) = usleep_test(iSleepArg)
        ltAvg.append(tAvg)
        lErrRel.append(iErrRel)

    # Measure the total time of test - stop the stopwatch
    tEnd = time.time() - tStart
    print("Tests were finished in %.1f seconds" % tEnd)

    # Dump the results to a file
    dResults = {}
    dResults['lUSleepArgs'] = lUSleepArgs
    dResults['ltAvg'] = ltAvg
    dResults['lErrRel'] = lErrRel
    f = open('usleep_test.dat', 'wb')
    pickle.dump(dResults, f)
    f.close()

    # Plot the measured average execution time and requested execution time
    if (bPlot == 1):
        plot_results(lUSleepArgs, ltAvg, lErrRel)

if __name__ == "__main__":
    main()
