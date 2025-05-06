#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>

struct data 
{
    int buffer[10];
    sem_t empty,mutex,full;
    int index;
}*d;

void main()
{
    int x,item;
    int fd = shm_open("/buffer",O_CREAT|O_RDWR,0777);
    d = mmap(NULL,sizeof(struct data),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    sem_init(&(d->mutex),10,1);
    sem_init(&(d->full),10,0);
    sem_init(&(d->empty),10,5);
    do{
        sleep(1);
        sem_getvalue(&(d->empty),&x);
        if(x==5)
        {
            printf("Buffer is empty/n");

        }

        else{

            sem_wait(&(d->mutex));
            sem_wait(&(d->full));

            item = d->buffer[d->index];
            d->index = (d->index+1)%5;
            printt("Item consumed is %d",item);

            sem_post(&(d->mutex));
            sem_post(&(d->full));
            }
        }while(true);
}
