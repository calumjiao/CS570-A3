/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include "Processes.h"
sem_t FLAG;

void *BotManager::runBot(void *arg){
    long id = (long) arg;
    int i;
    int time;
    string quote;
    if(id % 2 == 0){
        time = 2;
        quote = even;
    }
    else{
        time = 3;
        quote = odd;
    }
    
    for(i = 0; i < 7; i++){
        sem_wait(&FLAG);
        ofstream outputStream;
        outputStream.open("QUOTE.txt", fstream::app);
        outputStream << std::this_thread::get_id() << quote << endl;
        cout << "Thread " << this_thread::get_id() << " is running" << endl;
        outputStream.close();
        sem_post(&FLAG);
        sleep(time);
    }

    pthread_exit(NULL);
}


void run(int sec){

	// Create threads
	sem_init(&FLAG, 0, 2);
	pthread_t processes[1];
	int errorOne = pthread_create(&processes[0], NULL,  &runBot, (void*)id);
	int errorTwo = pthread_create(&processes[1], NULL,  &runBot, (void*)id);
	
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



void run(int sec) {
	int x;
	pid_t proc1, proc2;
	proc1 = fork(); 

	if(proc1 < 0){
		cerr << "Error" << endl;
		exit(-1);
	}
	if(proc1 == 0) localtime();
	
	else{
		proc2 = fork();
		if(proc2 < 0){
			cerr << "Error\n";
			exit(-1);
		} else if(proc2 == 0){
			timer(sec);
			kill(proc1,SIGKILL);
		} else{
			waitpid(proc2,&x,0);
			cout << "Child processes have been terminated." << endl;
		}
	}
}


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

void startTimer(){
	time_t theTime;
	while(true){
		theTime = time(0); // get the time now
		struct tm * now = localtime(&theTime);
		cout << "The time: " << now -> tm_hour << ":";
		cout << now -> tm_min << ":" << now -> tm_sec << endl; 
		sleep(1);
	}
}