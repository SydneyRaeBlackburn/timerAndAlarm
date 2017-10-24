#Troy Ricks: cssc1101
#Sydney Blackburn: cssc1112

#Class: CS570, Professor Leonard, Summer 2017
#Due: June 26, 2017
#Project: Assignment #3, aClock
#File: Makefile

CC = gcc -pthread
CFLAGS = -c
TARGET = aclock

all: $(TARGET)

$(TARGET): aclock.o
	$(CC) aclock.o -o $(TARGET)
aclock.o: aclock.c
	$(CC) $(CFLAGS) aclock.c
clean:
	rm -f core *.o $(TARGET)