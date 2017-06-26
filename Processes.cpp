/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include "Processes.h"
#include <thread> 
#include <signal.h>
#include <semaphore.h>
#include <csignal>
#include <sstream>
using namespace std;

sig_atomic_t threadLock = 0;
pthread_t processes[2];

void Processes::unlock(int signum){
	threadLock = 1;
}

// After n seconds, unlock the thread to stop infinite loop in process #1
void *Processes::clockInterrupter(void *arg){
    long time = (long) arg;
	signal(SIGINT, unlock); 
	for(int i = 0; i < time; i++)
		sleep(1);
	raise(SIGINT);
	pthread_exit(NULL);
}

// Print the time forever until it is interrupted by process #2
void *Processes::clock(void *arg){
	time_t theTime;
	theTime = time(0); // get the time now
	struct tm * now = localtime(&theTime);
	int hour;
	int minutes;
	int seconds;
	long alarm = (long) arg;

	// Will loop forever untill the clockInterrupter changes the threadLock with signal.
	while(threadLock == 0){
		// Get the time
		hour = now -> tm_hour;
		minutes = now -> tm_min;
		seconds = now -> tm_sec;
		// Print time in human readable format
		cout << "The time: " << hour << ":"
			<< minutes << ":" << seconds << endl; 

		// If the alarm has been set then check if it should go off
		if(alarm > 0){
			// convert the time to a single long to compare to alarm
			ostringstream currTime;
			currTime << hour << minutes << seconds;
			istringstream iss(currTime.str());
			long currTimeInt;
			iss >> currTimeInt;		
			if(currTimeInt == alarm) cout << "RING RING RING. Alarm going off" << endl;
		}	
		sleep(1);	
	}
	pthread_exit(NULL);
}



void Processes::run(long time, int hour, int minutes, int seconds){
	// Make sure the thread is locked
	threadLock = 0;
	long alarmInt;

	// If alarm time is provided, convert the alarm time to a single long so that it can be 
	// passed to the thread as a param
	if(hour + minutes + seconds > 0){
		ostringstream alarm;
		alarm << hour << minutes << seconds;
		istringstream iss(alarm.str());
		iss >> alarmInt;
	} else alarmInt = -1;
	
	// Create threads
	int errorOne = pthread_create(&processes[0], NULL,  &clock, (void*)alarmInt);
	int errorTwo = pthread_create(&processes[1], NULL,  &clockInterrupter, (void*)time);

	// Check for errors when creating the threads
	if(errorOne != 0 || errorTwo != 0){
		cout << "An error occured while creating a thread" << endl;
        exit(EXIT_FAILURE);
	}
	
	// Wait for the threads to finsih before moving on
	pthread_join(processes[1], NULL);
    pthread_join(processes[2], NULL);
	
	// Destroy semaphore and end program
    cout << "The program has finished running" << endl;
    pthread_exit(NULL);
}

