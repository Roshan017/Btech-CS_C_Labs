#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdbool.h>


struct data{
    int buffer[10];
    sem_t mutex,empty,full;
    int index;
}*d;

void main(){

    int x,item=0;
    int fd = shm_open("/buffer",O_RDWR|O_CREAT,0777);
    ftruncate(fd,sizeof(struct data));
    d = mmap(NULL,sizeof(struct data),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    sem_init(&(d->mutex),10,1);
    sem_init(&(d->full),10,0);
    sem_init(&(d->empty),10,5);

   do{
        sleep(1);
        sem_getvalue(&(d->full),&x);

        if(x==5)
        {
            printf("Buffer is full\n");
        }
        else{

                item = item + rand();
                
                sem_wait(&(d->empty));
                sem_wait(&(d->mutex));

                d->buffer[d->index] = item;

                d->index = (d->index+1)%5;
                printf("\n the item produced:%d",item);
                sem_post(&(d->full));
                sem_post(&(d->mutex));
        }
   }while(true);
}
