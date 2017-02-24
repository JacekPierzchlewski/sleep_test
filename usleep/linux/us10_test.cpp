/*
 * us10_test.cpp [version 1.0]
 *
 * This is test of usleep(10) call. (Linux / C++ version)
 * This test measures time of 1 million usleep(10) calls.
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
#include <inttypes.h>
#include <stdlib.h>

// Declaration of one thousands and one million calls to usleep(10).
// Definitions are at the end of the file.
void usleep_1M();
void usleep_1K();

long unsigned int time_between_timestamps(timeval stTSStart, timeval stTSStop)
{
/*
 *  Compute time between timestamps in us.
 *
 *
 *  Parameters:
 *    stTSStart [timeval structure] : start timestamp
 *    stTSStop  [timeval structure] : stop timestamp
 *
 *  Returns:
 *.   tElapsed [long uint] : time between timestamps [us]
 *
 */
    // The number of us in a second
    const uint64_t iSECUS = 1000000;

    // Get start timestamp [in us]
    uint iTSsec = (uint)stTSStart.tv_sec;   // timestamp in seconds
    uint iTSus = (uint)stTSStart.tv_usec;   // timestamp in useconds
    long unsigned int tStart = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (uint)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (uint)stTSStop.tv_usec;    // timestamp in useconds
    long unsigned int tStop = (long unsigned int)(iTSsec*iSECUS+iTSus);

    // Compute the elapsed timestamp
    long unsigned int tElapsed = tStop - tStart;
    return tElapsed;
}


int main()
{
    // Start message
    printf("Start:...\n");

    // Declare timestamp of start and stop and get the start timestamp
    timeval stTSStart, stTSStop;
    gettimeofday(&stTSStart, NULL);
    usleep_1M();

    // Get the timestamp of stop
    gettimeofday(&stTSStop, NULL);

    // Print out finish message
    printf("         finish! (Was it ten seconds?)\n");

    // ** Compute the time taken by 1million usleeps(10) **
    unsigned long int tElapsed = time_between_timestamps(stTSStart, stTSStop);
    printf("It was %.3f seconds. \n", (double)tElapsed / 1000000);
    return 0;
}

inline void usleep_1K()
{
/*
 * This function calls usleep(10) one thousand times;
 */
    // There is a thousand calls to usleep below.
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
    usleep(10); usleep(10); usleep(10); usleep(10); usleep(10);
}

void usleep_1M()
{
/*
 * This function calls usleep(10) 1 million times
 * by calling usleep_1K() a thousand times.
 */
    // There is a thousand calls to usleep_1K below.
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
    usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K(); usleep_1K();
}
