/*
 * usx_test_py.cpp [version 1.0]
 *
 * This is Python interface to usleep() test (Mac version).
 * This test measures time of one hundred usleep() calls with a number of
 * arguments.
 *
 * The usleep() is called with the following arguments:
 * 1us, 2us, 3us, 4us, 5us, 6us, 7us, 8us, 9us,
 * 10us, 20 us, 30us, 40us, 50us,
 * 100us, 200us, 300us, 400us, 500us,
 * 1ms, 5ms,
 * 10ms, 20ms, 30ms, 40ms, 50ms,  60ms, 70ms, 80ms, 90ms
 * 100ms, 200ms, 300ms, 400ms, 500ms
 *
 *
 * read more on: www.orange-engineer.com
 *
 * (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
 * license: BSD-2-Clause.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <iomanip>
#include <Python.h>

// Declare the engine of the test - one hundred usleep calls
// (Definition is at the end of file)
void usleeps_100(unsigned int);


long unsigned int time_between_timestamps(timeval stTSStart, timeval stTSStop)
{
/*
 *  Compute time between timestamps in us.
 *
 *  Parameters:
 *    stTSStart:  [timeval structure]  start timestamp
 *    stTSStop:   [timeval structure]  stop timestamp
 *
 *  Returns:
 *    tElapsed:  [long uint]  time between timestamps [us]
 *
 */
    // The number of us in a second
    const uint64_t iSECUS = 1000000;

    // Get start timestamp [in us]
    unsigned int iTSsec = (unsigned int)stTSStart.tv_sec;   // timestamp in s
    unsigned int iTSus = (unsigned int)stTSStart.tv_usec;   // timestamp in us
    long unsigned int tStart_us = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (unsigned int)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (unsigned int)stTSStop.tv_usec;    // timestamp in useconds
    long unsigned int tStop_us = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Compute the elapsed timestamp
    long unsigned int tElapsed_us = tStop_us - tStart_us;
    return tElapsed_us;
}


double test_usleep(unsigned int iUs)
{
/*
 * This function tests execution time of usleep(iUs) function with
 * a given argument iUs.
 *
 *  Parameters:
 *    iUs:  [uint]  argument for usleep function
 *
 *  Returns:
 *    tAvg_us:  [double]  the average sleep time of a single usleep [us]
 *
 */

    // Timestamps of start and stop
    timeval stTSStart, stTSStop;

    // The number of usleep calls
    unsigned int nUsleep = 100;

    // Call usleep one hundred times
    gettimeofday(&stTSStart, NULL);
    usleeps_100(iUs);
    gettimeofday(&stTSStop, NULL);

    // ** Compute the sleep time of one hundred usleeps **
    unsigned int tSleep_us = time_between_timestamps(stTSStart, stTSStop);

    // Compute the average sleep time of a single usleep
    double tAvg_us = (double)tSleep_us / nUsleep;    // [us]

    return tAvg_us;
}

// Run the usleep test - python interface
static PyObject*
run_test_usleep_py(PyObject *self, PyObject *args)
{
/*
 * This is the Python interface to 'test_usleep'.
 *
 *  Parameters:
 *    Python tuple with:
 *      iUs:  [uint]  argument for usleep function
 *
 *  Returns:
 *    Python tuple with:
 *      tElapsed_ms:  [double]   elapsed time [ms]
 *
 */

    // Var declarations
    unsigned int iUs;                 // Argument of usleep function

    // Get the iUs argument of usleep function from the Python side
    if (!PyArg_ParseTuple(args, "i", &iUs))
        return NULL;

    // Run the test
    double tAvg_us = test_usleep(iUs);

    // Return the average sleep time of a single usleep(iUs) function
    return Py_BuildValue("d", tAvg_us);
}


static PyMethodDef usxTestMethods[] = {
/*
 *   Python methods definition
 */
    {"run_test",  run_test_usleep_py, METH_VARARGS,
    "Test uscall"},
    {NULL, NULL, 0, NULL}        // Protector
};


static struct PyModuleDef stUsxTestModule = {
/*
 *   Python module parameters
 */
   PyModuleDef_HEAD_INIT,
   "usxTest",     // name of module
   NULL,          // module documentation
   -1,            // size of per-interpreter state of the module,
                  // or -1 if the module keeps state in global variables.
   usxTestMethods
};


PyMODINIT_FUNC
PyInit_usxTest(void)
{
/*
 *   Python module definition
 */
   return PyModule_Create(&stUsxTestModule);
}

void usleeps_100(unsigned int iUs)
{
/*
 *  This is the engine of the test  - one hundred calls to usleep.
 *
 *  Parameters:
 *    iUs:  [unsigned int]  Argument for usleep
 *
 */
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
    usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs); usleep(iUs);
}

