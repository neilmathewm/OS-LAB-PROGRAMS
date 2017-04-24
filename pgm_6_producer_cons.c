#include <pthread.h>
#include <stdio.h>
#include<semaphore.h>
#include<stdlib.h>
pthread_mutex_t mutex;
pthread_t prod[20],cons[20];
sem_t full,empty;
int buffer[20];
int size=10;
int counter=0,i;
int num[11]={0,1,2,3,4,5,6,7,8,9,10};
void * producer (void * x)
{
	while(1){	
	int waittime,item;
	int *i=x;	
	//item=rand()%5;
	//waittime=rand()%5;
	sem_wait(&empty);  
	pthread_mutex_lock(&mutex);
	
	printf("\nProducer %d has produced an item ",*i);
	
	buffer[counter++]=1;	//item
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	sleep(1);	
	}
}

void * consumer (void * y)
{
	while(1){

	int waittime,item;
	int *i=y;
	//waittime=rand()%5;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	//item=read();
	counter--;
	printf("\nConsumer %d has consumed an item",*i);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	sleep(1);	
	}
}
void main()
{
int n,m;
pthread_mutex_init(&mutex,NULL);
sem_init(&full,1,0);
sem_init(&empty,1,size);

printf("Enter the no of producers: ");
scanf("%d",&n);

printf("Enter the no of consumers: ");
scanf("%d",&m);

for(i=0;i<n;i++)
	pthread_create(&prod[i],NULL,producer,&num[i]);

for(i=0;i<m;i++)
	pthread_create(&cons[i],NULL,consumer,&num[i]);

for(i=0;i<n;i++)
	pthread_join(prod[i],NULL);
for(i=0;i<m;i++)
	pthread_join(cons[i],NULL);
}

