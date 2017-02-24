/*
 * us_test.c [version 1.0]
 *
 * This is test of usleep(1) call. (Mac / C version)
 * This test measures time of 1 million usleep(1) calls.
 *
 * read more on: www.orange-engineer.com
 *
 * (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
 * license: BSD-2-Clause.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// Declaration of one thousand and one million calls to usleep(1).
// Definitions are at the end of the file.
void usleep_1M();
void usleep_1K();

long unsigned int time_between_timestamps(struct timeval stTSStart,
                                          struct timeval stTSStop)
{
/*
 *  Compute time between timestamps in us.
 *
 *
 *  Parameters:
 *    stTSStart:  [timeval structure]  start timestamp
 *    stTSStop:   [timeval structure]  stop timestamp
 *
 *  Returns:
 *    tElapsed:  [long uint]  time between timestamps [us]
 *
 */
    unsigned int iTSsec, iTSus;
    long unsigned int tStart, tStop, tElapsed;

    // The number of us in a second
    const uint64_t iSecus = 1000000;

    // Get start timestamp [in us]
    iTSsec = (unsigned int)stTSStart.tv_sec;   // timestamp in seconds
    iTSus = (unsigned int)stTSStart.tv_usec;   // timestamp in useconds
    tStart = (long unsigned int)(iTSsec*iSecus+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (unsigned int)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (unsigned int)stTSStop.tv_usec;    // timestamp in useconds
    tStop = (long unsigned int)(iTSsec*iSecus+iTSus);

    // Compute the elapsed timestamp
    tElapsed = tStop - tStart;
    return tElapsed;
}


int main()
{
    // Declare timestamp of start and stop
    struct timeval stTSStart, stTSStop;
    unsigned long int tElapsed;

    // Start message
    printf("Start:...\n");

    // Get the start timestamp
    gettimeofday(&stTSStart, NULL);
    usleep_1M();

    // Get the timestamp of stop
    gettimeofday(&stTSStop, NULL);

    // Print out finish message
    printf("         finish! (Was it a second?)\n");

    // ** Compute the time taken by 1million usleeps **
    tElapsed = time_between_timestamps(stTSStart, stTSStop);
    printf("It was %.3f seconds. \n", (double)tElapsed / 1000000);
    return 0;
}

inline void usleep_1K()
{
/*
 * This function calls usleep(1) one thousand times;
 */
    // There is a thousand calls to usleep below.
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
    usleep(1); usleep(1); usleep(1); usleep(1); usleep(1);
}

void usleep_1M()
{
/*
 * This function calls usleep(1) 1 million times
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
