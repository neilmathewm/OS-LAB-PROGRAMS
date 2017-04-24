#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_no+4)%N
#define RIGHT (ph_no+1)%N
  
sem_t mutex;
sem_t phil[10] ;
int N=5,state[10];
int phil_no[10]={0,1,2,3,4};
void check(int ph_no)
{
    if (state[ph_no] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[ph_no] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n",ph_no+1,LEFT+1,ph_no+1);
        printf("Philosopher %d is Eating\n",ph_no+1);
        sem_post(&phil[ph_no]);
    }
}

void acquire(int ph_no)
{
    sem_wait(&mutex);
    state[ph_no] = HUNGRY;
    printf("\nPhilosopher %d is Hungry\n",ph_no+1);
    check(ph_no);
    sem_post(&mutex);
    sem_wait(&phil[ph_no]);
    sleep(1);
}
  
  
void release(int ph_no)
{
    sem_wait(&mutex);
    state[ph_no] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n",ph_no+1,LEFT+1,ph_no+1);
    printf("Philosopher %d is thinking\n",ph_no+1);
    check(LEFT);
    check(RIGHT);
    sem_post(&mutex);
}

void *philo(void *num)
{
    while(1)
    {
        int *i = num;
        sleep(1);
        acquire(*i);
        sleep(0);
        release(*i);
    }
} 
void main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    for(i=0;i<N;i++)
        sem_init(&phil[i],0,0);
    for(i=0;i<N;i++){
        pthread_create(&thread_id[i],NULL,philo,&phil_no[i]);
        printf("\nPhilosopher %d is thinking",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);
}
  

  

