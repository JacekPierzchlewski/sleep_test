/*
 * nanox_test_py.cpp [version 1.0]
 *
 * This is Python module which tests nanosleep() function (Linux version).
 *
 * read more on: www.orange-engineer.com
 *
 * (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
 * license: BSD-2-Clause.
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <iomanip>
#include <Python.h>

/* Declare the engine of the test - one thousand nanosleep calls
 * (Definition is at the end of file)
 */
void nanosleeps_1000(struct timespec);

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
    const uint64_t nSECUS = 1000000;

    // Get start timestamp [in us]
    unsigned int iTSsec = (unsigned int)stTSStart.tv_sec;   // timestamp in s
    unsigned int iTSus = (unsigned int)stTSStart.tv_usec;   // timestamp in us
    long unsigned int tStart_us = (long unsigned int)(iTSsec*nSECUS+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (unsigned int)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (unsigned int)stTSStop.tv_usec;    // timestamp in useconds
    long unsigned int tStop_us = (long unsigned int)(iTSsec*nSECUS+iTSus);

    // Compute the elapsed time
    long unsigned int tElapsed_us = tStop_us - tStart_us;
    return tElapsed_us;
}


double test_nanosleep(unsigned int ins)
{
/*
 * This function tests sleep time of a thousand nanosleep() functions
 * with a given argument time setting [in ns].
 *
 *  Parameters:
 *    ins:  [uint]  time setting for nanosleep function
 *
 *  Returns:
 *    tAvg_us:  [double]  the average sleep time of a single nanosleep [us]
 *
 */

    // Timestamps of start and stop
    timeval stTSStart, stTSStop;

    // The number of nanosleep calls
    const unsigned int nNANOSLEEP = 1000;

    // Create a timespec configuration structure
    struct timespec stT;
    stT.tv_sec = 0;
    stT.tv_nsec = (long unsigned int)ins;

    // Call nanosleep 1 thousand times
    gettimeofday(&stTSStart, NULL);
    nanosleeps_1000(stT);
    gettimeofday(&stTSStop, NULL);

    // ** Compute the sleep time of 1 thousand nanosleeps **
    uint tElapsed_us = time_between_timestamps(stTSStart, stTSStop);  // [us]

    // Compute the average sleep time of a single nanosleep
    double tAvg_us = (double)tElapsed_us / nNANOSLEEP;     // [us]

    return tAvg_us;
}


// Run the nanosleep test - python interface
static PyObject* run_test_nanosleep_py(PyObject *self, PyObject *args)
{
/*
 * This is the Python interface to 'test_nanosleep'.
 *
 *  Parameters:
 *    Python tuple with:
 *      ins:  [uint]  time setting  for nanosleep function
 *
 *  Returns:
 *    Python tuple with:
 *      tAvg_us:  [double]  the average sleep time of a single nanosleep [us]
 *
 */

    // Var declarations
    unsigned int ins;     // Time setting for nanosleep function

    // Get the ins time setting for nanosleep function
    if (!PyArg_ParseTuple(args, "i", &ins))
        return NULL;

    // Run the test
    double tAvg_us = test_nanosleep(ins);

    // Return the average sleep time of a single nanosleep() function
    return Py_BuildValue("d", tAvg_us);
}


static PyMethodDef nanoxTestMethods[] = {
/*
 *   Python methods definition
 */
    {"run_test",  run_test_nanosleep_py, METH_VARARGS,
    "Test nanosleepcall"},
    {NULL, NULL, 0, NULL}        // Protector
};


static struct PyModuleDef stNanoxTestModule = {
/*
 *   Python module parameters
 */
   PyModuleDef_HEAD_INIT,
   "nanoxTest",     // name of module
   NULL,            // module documentation, may be NULL
   -1,              // size of per-interpreter state of the module,
                    // or -1 if the module keeps state in global variables.
   nanoxTestMethods
};


PyMODINIT_FUNC
PyInit_nanoxTest(void)
{
/*
 *   Python module definition
 */
   return PyModule_Create(&stNanoxTestModule);
}


void nanosleeps_1000(struct timespec stT)
{
/*
 *  This is the engine of the test  - one thousand calls to nanosleep.
 *
 *  Parameters:
 *    stT: [timespec structure]  the time configuration structure for nanosleep
 */

    // There is one thousand calls to nanosleep below.
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
    nanosleep(&stT, NULL); nanosleep(&stT, NULL);
}
