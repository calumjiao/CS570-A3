/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include "Processes.h"
#include "signal.h"
sem_t FLAG;
int threadLock = 0;


int clock(int time){
	while(true){

	}
}


int timer(int sec){
	while(sec >= 0){
		cout << "Remaining Time: " << sec << " seconds\n";
		sleep(1);
		sec--;	
	}
	return sec;	
}	


// After n seconds, send interrupt signal to process #1
void *Processes::clockInterrupter(void *arg){
    long time = (long) arg;
	time_t theTime;
	for(int i = 0; i < theTime; i++)
		sleep(1);

}

// Print the time forever until it is interrupted by process #2
void *Processes::clock(void *arg){
	dup2(pipeEnds1[1], STDOUT_FILENO);

    long time = (long) arg;
	time_t theTime;
	while(true){
		if(threadLock != 0) pthread_exit(NULL);
		else{
			theTime = time(0); // get the time now
			struct tm * now = localtime(&theTime);
			// Print the time in human format
			cout << "The time: " << now -> tm_hour << ":"
				<< now -> tm_min << ":" << now -> tm_sec << endl; 
			sleep(1);
		}
	}
}


void run(int time){
	// Create threads
	sem_init(&FLAG, 0, 2);
	pthread_t processes[2];
	int errorOne = pthread_create(&processes[0], NULL,  &clock, (void*)time);
	int errorTwo = pthread_create(&processes[1], NULL,  &runBot, (void*)id);

	// Set up pipes
	
	

	
	// Check for errors when creating the threads
	if(errorOne == 0 || errorTwo == 0){
		cout << "An error occured while creating a thread" << endl;
        exit(EXIT_FAILURE);
	}
	
	// Wait for the threads to finsih before moving on
	pthread_join(processes[1], NULL);
    pthread_join(processes[2], NULL);
	
	// Destroy semaphore and end program
	sem_destroy(&FLAG);
    cout << "The program has finished running" << endl;
    pthread_exit(NULL);
}

