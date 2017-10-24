/*Troy Ricks: cssc1101
*Sydney Blackburn: cssc1112
*
*Class: CS570, Professor Leonard, Summer 2017
*Due: June 26, 2017
*Project: Assignment #3, Clock
*File: aclock.h
*/

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void create_threads();
void join_threads();
void *firstThread();
void *secondThread();