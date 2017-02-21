#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <iomanip>

void usleep1M();
void usleep1K();


long unsigned int time_between_timestamps(timeval stTSStart, timeval stTSStop)
{
/*
 *  Compute time between timestamps in us
 */
    // The number of us in a second
    const uint64_t iSecus = 1000000;

    // Get start timestamp [in us]
    uint iTSsec = (uint)stTSStart.tv_sec;   // timestamp in seconds
    uint iTSus = (uint)stTSStart.tv_usec;   // timestamp in useconds
    long unsigned int tStart = (long unsigned int)(iTSsec*iSecus+iTSus);

    // Get stop timestamp [in us]
    iTSsec = (uint)stTSStop.tv_sec;    // timestamp in seconds
    iTSus = (uint)stTSStop.tv_usec;    // timestamp in useconds
    long unsigned int tStop = (long unsigned int)(iTSsec*iSecus+iTSus);

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
    usleep1M();

    // Get the timestamp of stop
    gettimeofday(&stTSStop, NULL);

    // Print out finish message
    printf("         finish! (Was it a second?)\n");

    // ** Compute the time taken by 1million usleeps ** 
    unsigned long int tElapsed = time_between_timestamps(stTSStart, stTSStop);
    printf("It was %.3f seconds. \n", (double)tElapsed / 1000000);
    return 0;
}

inline void usleep1K()
{
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

void usleep1M()
{
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
    usleep1K(); usleep1K(); usleep1K(); usleep1K(); usleep1K(); 
}
