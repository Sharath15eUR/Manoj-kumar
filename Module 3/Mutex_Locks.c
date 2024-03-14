#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
pthread_t threads[3]; 
int counter; 
pthread_mutex_t lock; 

void* lockFunction(void* arg) 
{ 
	pthread_mutex_lock(&lock); 
	unsigned long i = 0; 
	counter += 1; 
	printf("\n Job %d has started\n", counter); 
	for (i = 0; i < 100; i++); 
	printf("\n Job %d has finished\n", counter); 
	pthread_mutex_unlock(&lock); 
	return NULL; 
} 

int main(void) 
{ 
	int i = 0; 
	int error; 
	if (pthread_mutex_init(&lock, NULL) != 0) { 
		printf("mutex init has failed"); 
		return 1; 
	} 
	while (i < 3) { 
		error = pthread_create(&(threads[i]), NULL, &lockFunction, NULL); 
		i++; 
	} 
	pthread_join(threads[0], NULL); 
	pthread_join(threads[1], NULL); 
	pthread_join(threads[2], NULL); 
	pthread_mutex_destroy(&lock); 
	return 0; 
} 

