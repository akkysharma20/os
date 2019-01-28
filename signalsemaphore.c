#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t signalT1T2, signalT2T1;
int count =0;
int a, b, add;
void* input(void *);
void* sum(void *);


int main()
{
	pthread_t idi, ins;
	
	sem_init(&signalT1T2,0,0);
	sem_init(&signalT2T1,0,1);
	pthread_create(&idi, NULL, input, NULL);
	pthread_create(&ins, NULL, sum, NULL);

	pthread_join(idi, NULL);
	pthread_join(ins, NULL);
	
	return 0;
}

void* input(void *data)
{
	while(1)
	{
	   sem_wait(&signalT2T1);
	   scanf("%d", &a);
	   scanf("%d", &b);
	   sem_post(&signalT1T2);
	}
}

void* sum(void *data)
{
	while(1)
	{
	   sem_wait(&signalT1T2);
	   add = a + b;	
	   printf("Addition: %d\n", add);
	   sem_post(&signalT2T1);
	}
}

 
