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
        void run(long time, int hour, int minutes, int seconds);
    private:
        static void *clockInterrupter(void *arg);
        static void *clock(void *arg);
        static void unlock(int signum);
};