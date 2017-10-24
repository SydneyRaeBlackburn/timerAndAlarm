/*Troy Ricks: cssc1101
*Sydney Blackburn: cssc1112
*
*Class: CS570, Professor Leonard, Summer 2017
*Due: June 26, 2017
*Project: Assignment #3, Clock
*File: aclock.c
*/

#include "aclock.h"

#define Num_Threads 2
pthread_t threads[Num_Threads];
int runTime, hour, min, sec;

int main(int argc, char *argv[]){
	if (argv[1] == NULL) runTime = 30;
	else runTime = atoi(argv[1]);
	hour = atoi(argv[2]);
	min = atoi(argv[3]);
	sec = atoi(argv[4]);
	create_threads(); /* Create 2 threads */
	join_threads(); /* Wait for threads to finish before continuing */
	printf("Finished\n");
	exit(0);
}

void create_threads() {
	int statusOne, statusTwo;
	statusOne = pthread_create (&threads[0], NULL, (void *) &firstThread, NULL);
	if(statusOne != 0) { /* Check that thread created successfully */
		printf("pthread_create returned error code %d0", statusOne);
		exit(-1);
	}
	statusTwo = pthread_create (&threads[1], NULL, (void *) &secondThread, NULL);
	if(statusTwo != 0) { /* Check that thread created successfully */
		printf("pthread_create returned error code %d0", statusTwo);
		exit(-1);
	}
}

void join_threads() {
	int j;
	for (j=0; j<Num_Threads; j++) {
		pthread_join(threads[j],NULL);
	}
}

void *firstThread() {
	time_t t;
	struct tm *clock; /* To get local time */
	for(;;) {
		sleep(1);
		time(&t);
		clock = localtime(&t);
		printf("Hour: %d Minute: %d Second: %d\n",clock->tm_hour,clock->tm_min,clock->tm_sec);
		if(clock->tm_hour==hour && clock->tm_min==min && clock->tm_sec==sec) {
			printf("Alarm: Reached input time of Hour: %d, Minutes: %d, Seconds: %d\n", clock->tm_hour, clock->tm_min, clock->tm_sec);
		}
	}
}

void *secondThread() {
	while(runTime != 0) { /* Timer */
		sleep(1);
		runTime--;
		/*printf("%d\n",runTime);*/
	}
	pthread_cancel(threads[0]); /* Kill first thread */
	pthread_exit(NULL); /* Kill self */
}
