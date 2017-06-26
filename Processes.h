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




class Processes{
    public:
        void run(int sec);
    private:
        void *clockInterrupter(void *arg);
        void *clock(void *arg);
};