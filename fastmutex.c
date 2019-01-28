#include<stdio.h>
#define __USE_GNU
#include<pthread.h>

pthread_mutex_t countMutex ;
int count =0;
void* incThread(void *);
void* decThread(void *);


int main()
{
	pthread_t idInc, idDec;
	
	pthread_mutex_init(&countMutex,NULL);
	pthread_create(&idInc, NULL, incThread, NULL);
	pthread_create(&idDec, NULL, decThread, NULL);

	pthread_join(idInc, NULL);
	pthread_join(idDec, NULL);
	pthread_mutex_destroy(&countMutex);

	return 0;
}


void* incThread(void *data)
{
	while(1)
	{
	   pthread_mutex_lock(&countMutex);
	   pthread_mutex_lock(&countMutex);		   
	   count++;
	   printf("Incthread: %d\n", count);	   
	   pthread_mutex_unlock(&countMutex);
	   pthread_mutex_unlock(&countMutex);
	}
}

void* decThread(void *data)
{
	while(1)
	{
	   pthread_mutex_lock(&countMutex);
	   pthread_mutex_lock(&countMutex);		   
	   count--;
	   printf("Decthread: %d\n", count);	   
	   pthread_mutex_unlock(&countMutex);
	   pthread_mutex_unlock(&countMutex);
	}
}


