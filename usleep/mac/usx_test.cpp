/*
 * usx_test.cpp [version 1.0]
 *
 * This is test of usleep calls (Mac version).
 * This test measures time of 1 hundred usleep() calls with a number of
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

// Declare the engine of the test - 100 usleep calls
// Definition is at the end of the file
void usleeps_100(uint);

long unsigned int time_between_timestamps(timeval stTSStart, timeval stTSStop)
{
/*
 *  Compute time between timestamps in us.
 *
 *
 *  Input:
 *    stTSStart:  [timeval structure]  start timestamp
 *    stTSStop:   [timeval structure]  stop timestamp
 *
 *  Output:
 *    tElapsed [long uint] : time between timestamps [us]
 *
 */
    // The number of us in a second
    const uint64_t iSECUS = 1000000;

    // Get start timestamp [in us]
    unsigned int iTSsec = (unsigned int)stTSStart.tv_sec;   // timestamp in s
    unsigned int iTSus = (unsigned int)stTSStart.tv_usec;   // timestamp in us
    long unsigned int tStart_us = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (unsigned int)stTSStop.tv_sec;    // timestamp in s
    iTSus = (unsigned int)stTSStop.tv_usec;    // timestamp in us
    long unsigned int tStop_us = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Compute the elapsed timestamp
    long unsigned int tElapsed_us = tStop_us - tStart_us;
    return tElapsed_us;
}


double test_usleep(uint iUs)
{
/*
 * This function tests execution time of usleep(iUs) function with
 * a given argument iUs.
 * It prints out the expected and real elapsed time.
 *
 *  Input:
 *    iUs:  [uint]  argument for usleep function
 *
 *  Output:
 *    tElapsed_ms:  [double]  elapsed time [ms]
 *
 */

    // Timestamps of start and stop
    timeval stTSStart, stTSStop;

    // The number of usleep calls
    unsigned int nUsleep = 100;

    // The expected time (in miliseconds)
    unsigned int tExpected_us = nUsleep * iUs;
    unsigned int tExpected_ms = tExpected_us / 1000;

    // Start message
    if (tExpected_ms > 2000)
    {
        // Print in seconds
        double tExpected_s = tExpected_ms / 1000;
        printf("Start: [A hundred usleep(%d) calls] Exp. time: %.3f s\n",
               iUs, tExpected_s);
    }
    else
    {
        // Print in muiliseconds
        printf("Start: [A hundred usleep(%d) calls] Exp. time: %d ms\n",
               iUs, tExpected_ms);
    }
    // Call usleep one hundred times
    gettimeofday(&stTSStart, NULL);
    usleeps_100(iUs);
    gettimeofday(&stTSStop, NULL);

    // Print out finish message
    printf("....................................finish!\n");

    // ** Compute the execution time of one hundred usleeps **
    uint tElapsed_us = time_between_timestamps(stTSStart, stTSStop);  // [us]
    double tElapsed_ms = (double)tElapsed_us / 1000;                  // [ms]

    // Compute the average execution time of a single usleep
    double tAvg_us = (double)tElapsed_us / nUsleep;    // [us]

    // Compute the error
    double dErr = (tAvg_us - iUs) / iUs;

    // Print out the real time
    if (tElapsed_ms > 2000)
    {
        // Print in seconds
        double tElapsed_s = tElapsed_ms / 1000;
        printf("It was %.3f s (avg: %.3f us p.call error: %.3f) \n\n",
                tElapsed_s, tAvg_us, dErr);
    }
    else
    {
        // Print time in miliseconds
        printf("It was %.3f ms (avg: %.3f us p.call error: %.3f) \n\n",
                tElapsed_ms, tAvg_us, dErr);
    }
    return tElapsed_ms;
}

int main()
{
        // Run all the tests below:
        test_usleep(1);         // 1 usleep call = 1 us
        test_usleep(2);
        test_usleep(3);
        test_usleep(4);
        test_usleep(5);         // 1 usleep call = 5 us
        test_usleep(6);
        test_usleep(7);
        test_usleep(8);
        test_usleep(9);
        test_usleep(10);        // 1 usleep call = 10us
        test_usleep(20);
        test_usleep(30);
        test_usleep(40);
        test_usleep(50);
        test_usleep(100);       // 1 usleep call = 100 us
        test_usleep(200);
        test_usleep(300);
        test_usleep(400);
        test_usleep(500);       // 1 usleep call = 500 us
        test_usleep(1000);      // 1 usleep call = 1 ms
        test_usleep(5000);
        test_usleep(10000);     // 1 usleep call = 10 ms
        test_usleep(20000);
        test_usleep(30000);
        test_usleep(40000);
        test_usleep(50000);     // 1 usleep call = 50 ms
        test_usleep(60000);
        test_usleep(70000);
        test_usleep(80000);
        test_usleep(90000);
        test_usleep(100000);    // 1 usleep call = 100 ms
        test_usleep(200000);
        test_usleep(300000);
        test_usleep(400000);
        test_usleep(500000);    // 1 usleep call = 500 ms
        test_usleep(1000000);   // 1 usleep call = 1 s
}


void usleeps_100(unsigned int iUs)
{
/*
 *  This is the engine of the test  - one hundred calls to usleep.
 *
 *  Input:
 *    iUs:  [unsigned int]  Argument for usleep
 *
 */

    // There is one hundred calls to usleep below.
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
