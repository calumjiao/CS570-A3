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
using namespace std;

sem_t FLAG;
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
void *Processes::clock1(void *arg){
	time_t theTime;
	while(threadLock == 0){
		theTime = time(0); // get the time now
		struct tm * now = localtime(&theTime);
		// Print the time in human format
		cout << "The time: " << now -> tm_hour << ":"
			<< now -> tm_min << ":" << now -> tm_sec << endl; 
		sleep(1);	
	}
	pthread_exit(NULL);
}



void Processes::run(long time){
	// Create threads
	long seconds = time;
	long alarm = 123;
	sem_init(&FLAG, 0, 2);
	int errorTwo = pthread_create(&processes[1], NULL,  &clockInterrupter, (void*)time);
	int errorOne = pthread_create(&processes[0], NULL,  &clock1, (void*)alarm);
	
	
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

