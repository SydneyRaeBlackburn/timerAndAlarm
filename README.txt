Troy Ricks: cssc1101
Sydney Blackburn: cssc1112

Class: CS570, Professor Leonard, Summer 2017
Due: June 26, 2017
Project: Assignment #3, aClock
File: README

** cssc1112 edoras account will be available for testing **

File Manifest:
	aclock.c
	aclock.h
	Makefile
	README

Compile Instructions:
	To compile our program, just enter the command "make" which will run
	our Makefile bash script, creating an executable named "aclock".
	Otherwise enter "gcc -pthread aclock.c" to compile it manually with an
	"a.out" as your executable.

Operating Instructions:
	To operate our program, use the Makefile provided and run the created
	"aclock" executable. It will need to be followed by either no arguments
	(where it will automatically run with a runtime of 30 seconds and have
	no clock to time to compare to) or be followed by 4 arguments (runtime
	and an hour, minute and second to compare with). 
	Example: "aclock <runtime> <hour> <minute> <second>"

Novel/Significant Design Decisions:
	We decided to use "pthread_cancel()" instead of "pthread_kill()" to
	terminate our first thread because it was easier to implement.

Extra Features/Algorithms/Functions:
	No extra features added. Does what was required via the prompt.

All Known Deficiencies Or Bugs:
	No known deficiencies or bugs.

Lessons Learned:
	We learned how get local time and how to kill a process from another 
	process.
