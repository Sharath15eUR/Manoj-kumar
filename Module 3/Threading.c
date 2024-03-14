#include<stdio.h> 
#include<pthread.h> 

void* helloFunction(void* arg) 
{ 
    printf("Hello ");   
    return NULL; 
} 
  
void* worldFunction(void* arg) 
{ 
    printf("World"); 
    return NULL; 
} 
  
int main() 
{ 
    pthread_t hello_thread; 
    pthread_create(&hello_thread, NULL, helloFunction, NULL); 
    
	pthread_t world_thread; 
    pthread_create(&world_thread, NULL, worldFunction, NULL); 
	
	pthread_join(hello_thread, NULL); 
    pthread_join(world_thread, NULL); 
  
    return 0; 
}
