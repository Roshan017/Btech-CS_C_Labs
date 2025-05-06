#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/wait.h>


pthread_t P[5];
sem_t chop[5];
sem_t mutex;

void *phil( void *arg){

    int i = *(int*)arg;

    while(1)
    {
        printf("  Philosopher %d has started thinking\n",i);
        sleep(1);
        printf("  Philosopher %d is hungry\n",i);
        sem_wait(&(mutex));
        sem_wait(&(chop[i%5]));
        sem_wait(&(chop[(i+1)%5]));
        sem_post(&(mutex));
        printf("  Philosopher %d has started eating\n",i);
        sleep(1);
        sem_post(&(chop[i%5]));
        sem_post(&(chop[(i+1)%5]));
    }
}

int main(){

    int i ;

    for(i=0;i<5;i++)
    {
       sem_init(&(chop[i]),0,1);
    }
    sem_init(&(mutex),0,1);

    for ( i = 0; i < 5; i++)
    {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&P[i],NULL,phil,arg);
        wait(NULL);
    }
    for ( i = 0; i < 5 ;i++)
    {
       pthread_join(P[i],NULL);
    }
    
    
}
