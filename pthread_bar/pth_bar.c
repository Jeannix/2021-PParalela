#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "timer.h"

pthread_barrier_t mybarrier;
int thread_count;

void Usage(char* prog_name);
void* threadFn(void *id_ptr) {
	int thread_id = *(int*)id_ptr;
	int wait_sec = 1 + rand() % 5;
	printf("thread %d: Wait for %d seconds.\n", thread_id, wait_sec);
	sleep(wait_sec);
	printf("thread %d: I'm ready...\n", thread_id);
	
	pthread_barrier_wait(&mybarrier);
	
	printf("thread %d: going!\n", thread_id);
	return NULL;
}


int main(int argc, char* argv[]) {

		if (argc != 2)
    Usage(argv[0]);
  thread_count = strtol(argv[1], NULL, 10);

	int i;
	pthread_t ids[thread_count];
	int short_ids[thread_count];
	double start, finish;
		
	srand(time(NULL));
	pthread_barrier_init(&mybarrier, NULL, thread_count + 1);
	
	for (i=0; i < thread_count; i++) {
		short_ids[i] = i;
		pthread_create(&ids[i], NULL, threadFn, &short_ids[i]);
	}
	
	printf("main() is ready.\n");
	
	pthread_barrier_wait(&mybarrier);
	
	printf("main() is going!\n");
	GET_TIME(start);
	for (i=0; i < thread_count; i++) {
		pthread_join(ids[i], NULL);
	}
	GET_TIME(finish);
	pthread_barrier_destroy(&mybarrier);
	printf("Elapsed time = %e seconds\n", finish - start);
	return 0;
}

void Usage(char* prog_name) {

   fprintf(stderr, "usage: %s <number of threads>\n", prog_name);
   exit(0);
}  /* Usage */
