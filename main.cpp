/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    
	int time;
  if(argc == 1) time = 30; 
	else if (argc == 2 && time > 0) time = atoi(argv[1]);
  else { 
		cout << "Error. Please try ./aclock or ./aclock <time>  \n";
		exit(-1);
	}

	run(time);
	return 0;
}    
    
