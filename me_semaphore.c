#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t countSem;
int count =0;
void* incThread(void *);
void* decThread(void *);


int main()
{
	pthread_t idInc, idDec;
	
	sem_init(&countSem,0,1);
	pthread_create(&idInc, NULL, incThread, NULL);
	pthread_create(&idDec, NULL, decThread, NULL);

	pthread_join(idInc, NULL);
	pthread_join(idDec, NULL);
	sem_destroy(&countSem);

	return 0;
}


void* incThread(void *data)
{
	//while(1)
	{
	   sem_wait(&countSem);
	   count++;
	   printf("Incthread: %d\n", count);
	   sem_post(&countSem);
	}
}

void* decThread(void *data)
{
	//while(1)
	{
	   sem_wait(&countSem);
	   count--;
	   printf("Decthread: %d\n", count);
	   sem_post(&countSem);
	}
}


