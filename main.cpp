/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include <iostream>
#include "Processes.h"
using namespace std;

int main(int argc, char *argv[]){
	long time;
	long hour;
	long minute;
	long seconds;
	Processes *process = new Processes;
	
	// Get the input provided by the user 
	if(argc == 1) time = 30; 
	else if (argc == 2) time = atol(argv[1]);
	else if (argc == 5){
		time = atol(argv[1]);
		hour = atol(argv[2]);
		minute = atol(argv[3]);
		seconds = atol(argv[4]);
	}
	else { 
		cout << "Error. Please try ./aclock, or ./aclock <time>, or ./aclock <time> <hour> <minute> <seconds>" << endl;
		exit(-1);
	}

	// Call the run fuction to start the clock
	if(time > 0){
		if(argc == 2) process -> run(time, -1, -1 , -1);
		else if(argc == 5) process -> run(time, hour, minute, seconds);
	} 
	else cout << "Time must be greater than 0" << endl;
	return 0;
}    
    
