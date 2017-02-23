/*
 * nanox_test_py.cpp [version 1.0]
 *
 * This is Python module which tests nanosleep() function (Mac version).
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
void nanosleeps1000(struct timespec);

long unsigned int time_between_timestamps(timeval stTSStart, timeval stTSStop)
{
/*
 *  Compute time between timestamps in us.
 *
 *  Input:
 *    stTSStart [timeval structure] : start timestamp
 *    stTSStop  [timeval structure] : stop timestamp
 *
 *  Output:
 *    tElapsed [long uint] : time between timestamps [us]
 *
 */
    // The number of us in a second
    const uint64_t iSecus = 1000000;

    // Get start timestamp [in us]
    unsigned int iTSsec = (unsigned int)stTSStart.tv_sec;   // timestamp in s
    unsigned int iTSus = (unsigned int)stTSStart.tv_usec;   // timestamp in us
    long unsigned int tStart_us = (long unsigned int)(iTSsec*iSecus+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (unsigned int)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (unsigned int)stTSStop.tv_usec;    // timestamp in useconds
    long unsigned int tStop_us = (long unsigned int)(iTSsec*iSecus+iTSus);

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
 *  Input:
 *    ins [uint] : time setting for nanosleep function
 *
 *  Output:
 *    tAvg_us [double] : the average sleep time of a single nanosleep [us]
 *
 */

    // Timestamps of start and stop
    timeval stTSStart, stTSStop;

    // The number of nanosleep calls
    unsigned int nNanosleep = 1000;

    // Create a timespec configuration structure
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (long unsigned int)ins;

    // Call nanosleep 1 thousand times
    gettimeofday(&stTSStart, NULL);
    nanosleeps1000(t);
    gettimeofday(&stTSStop, NULL);

    // ** Compute the sleep time of 1 thousand nanosleeps **
    unsigned int tElapsed_us = time_between_timestamps(stTSStart, stTSStop);

    // Compute the average sleep time of a single nanosleep
    double tAvg_us = (double)tElapsed_us / nNanosleep;     // [us]

    return tAvg_us;
}


// Run the nanosleep test - python interface
static PyObject* run_test_nanosleep_py(PyObject *self, PyObject *args)
{
/*
 * This is the Python interface to 'test_nanosleep'.
 *
 *  Input:
 *    Python tuple with:
 *      ins [uint] : time setting  for nanosleep function
 *
 *  Output:
 *    Python tuple with:
 *      tAvg_us [double] : the average sleep time of a single nanosleep [us]
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


static PyMethodDef nanoxTest_Methods[] = {
/*
 *   Python methods definition
 */
    {"run_test",  run_test_nanosleep_py, METH_VARARGS,
    "Test nanosleepcall"},
    {NULL, NULL, 0, NULL}        // Protector
};


static struct PyModuleDef nanoxTest_Module = {
/*
 *   Python module parameters
 */
   PyModuleDef_HEAD_INIT,
   "nanoxTest",     /* name of module */
   NULL,          /* module documentation, may be NULL */
   -1,            /* size of per-interpreter state of the module,
                     or -1 if the module keeps state in global variables. */
   nanoxTest_Methods
};


PyMODINIT_FUNC
PyInit_nanoxTest(void)
{
/*
 *   Python module definition
 */
   return PyModule_Create(&nanoxTest_Module);
}


void nanosleeps1000(struct timespec t)
{
/*
 *  This is the engine of the test  - one thousand calls to nanosleep.
 *
 *  Input:
 *    t [timespec structure] : The time configuration structure for nanosleep
 */

    // There is one thousand calls to nanosleep below.
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
    nanosleep(&t, NULL); nanosleep(&t, NULL);
}
