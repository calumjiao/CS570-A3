
# CLASS NAME: CS 570
# ASSIGNMENT: LAB #3
# NAMES: Neda Heydari, Ole Larsen
# USERNAMES: CSSC1147, CSSC1140


all:
	g++ main.cpp Processes.h Processes.cpp -pthread -std=c++11 -o aclock

clean:
	rm all main.cpp processes.cpp
