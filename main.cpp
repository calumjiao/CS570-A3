/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include <iostream>

#include "main.h"

using namespace std;

int main(int argc, char *argv[]){
    
    int sec;

    if(argc == 1){			
		sec = 30;
    } else if (argc == 2){		
		sec = atoi(argv[1]);
    } else {				
		cout << "Error\n";
		exit(-1);
	}

	if(sec > 0)
		run(sec);
	else
		cout << "Error\n";
	return 0;
}    
    
