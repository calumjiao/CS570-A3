/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include "main.h"

void run(int sec) {
	int x;
	pid_t proc1, proc2;

	proc1 = fork();
	if(proc1 < 0){
		cerr << "Error\n";
		exit(-1);
	}
	if(proc1 == 0){
		localtime();
	}
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

int timer(int sec){
	for(; sec >= 0; sec--){
		cout << "Remaining Time: " << sec << " seconds\n";
		sleep(1);
	}
	return sec;	
}	

void localtime(){
	time_t ctt;
	while(true){
		ctt = time(0);
		tm * ltm = localtime(&ctt);
		cout << "Current Time:" << ltm -> tm_hour << ":" << 
			ltm-> tm_min << ":" << ltm-> tm_sec << endl;
		sleep(1);
		
	}
}