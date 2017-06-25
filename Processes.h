/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #3
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

void localtime();
int timer(int sec);
void run(int sec);
