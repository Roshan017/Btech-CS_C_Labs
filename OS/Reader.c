#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

int count = 0;
#define R 3
#define W 1

sem_t W_mutex,R_mutex,Resource_mutex;


void *readers(void *arg){

    int r_id = *(int *)arg;

    while(1)
    {
            sem_wait(&R_mutex);
            count++;

            if(count == 1)
            {
               sem_wait(&W_mutex);
            }

            sem_post(&R_mutex);
            printf("Reader %d is reading\n",r_id);
           // sleep(1);
            sem_wait(&R_mutex);
            count--;

            if(count == 0)
            {
                sem_post(&W_mutex);

            }

            sem_post(&R_mutex);
            sleep(2);
    }
}

void *writers( void *arg)
{
    int w_id = *(int *)arg;

    while(1)
    {
        sem_wait(&W_mutex);
        sem_wait(&Resource_mutex);

        printf("Writer %d is writing \n",w_id+1);
        sleep(1);

        sem_post(&Resource_mutex);
        sem_post(&W_mutex);
        sleep(2);

    }
}

int main(){

    int i;

    pthread_t reader[R];
    pthread_t writer[W];

    sem_init(&(Resource_mutex),0,1);
    sem_init(&(R_mutex),0,1);
    sem_init(&(W_mutex),0,1);
    for(i=0;i<R;i++)
    {
        int* r_id = malloc(sizeof(*r_id));
        *r_id = i;
        pthread_create(&reader[i],NULL,readers,r_id);
    }   

    for(i=0;i<W;i++)
    {
        int* w_id = malloc(sizeof(*w_id));
        *w_id = i;
        pthread_create(&writer[i],NULL,writers,w_id);
    }   

    for(i=0;i<R;i++)
    {
        pthread_join(reader[i],NULL);
    }
    for(i=0;i<W;i++)
    {
        pthread_join(writer[i],NULL);
    }

    sem_destroy(&R_mutex);
    sem_destroy(&W_mutex);
    sem_destroy(&Resource_mutex);
    return 0;
}
