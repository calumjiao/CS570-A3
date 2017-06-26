Class information: CS 570, Summer 2017

Assignment #3

Class account: Heydari: cssc1147, Larsen: cssc1140

RedID: Heydari: 816651063, Larsen: 818249361

The assignment is located in Ole’s account on Edoras cssc1140

FILE MANIFEST:
1. main.cpp
2. README.md
3. Makefile
4. Processes.cpp
5. Processes.h

COMPILE INSTRUCTIONS: 
To compile the main.cpp you need to type "make". This will link the files together and create the aclock file. To run the program you type "./aclock" on the command line. However, there's multiple ways to run the program. If only "aclock" is provided, then the program runs with a default countdown of 30 seconds. If "aclock" and a number is provided, the program will run with the user specified countdown (in seconds). If "aclock", a countdown, and an alarm time is provided, such as "aclock 5 11 26 42" then the program will run with the user-provided countdown (in this case, 5 seconds), and will print an alarm message if the clock time matches the provided alarm time (in this case, 11:26 AM, 42 seconds).

DESIGN DECISIONS: 
For this assignment, we were to implement two child processes, a clock that prints the time every second, and a countdown timer that tells the other process when to terminate and then terminates itself. Therefore, we created a Processes class that has a run function which creates the two threads, checks for errors, and then ends the program with a friendly message. We made a clockInterrupter function, which acts as a countdown timer for the time provided by the user, and after counting down, sends the interrupt signal to process 1. Our clock process continuously prints the time forever until it is interrupted by the clockInterrupter process. We also made an alarm that only prints if it matches the user-provided alarm time.

We also used GitHub for version control and code collaboration, as well as Discord for communication when not meeting up in person.

LESSONS LEARNED: 
We have gained more experience working with threads, and also ways to communicate between different threads. We have gained more practice and a better understanding the of C++ programming language.

