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
	int time;
	if(argc == 1) time = 30; 
	else if (argc == 2) time = atoi(argv[1]);
	else { 
		cout << "Error. Please try ./aclock or ./aclock <time>" << endl;
		exit(-1);
	}
	Processes *process = new Processes;
	if(time > 0) process -> run(time);
	else cout << "Time must be greater than 0" << endl;
	return 0;
}    
    
