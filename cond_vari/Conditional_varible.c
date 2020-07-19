#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<time.h>

#define BUFFER_SIZE 2

struct prodcons
{
  int buffer[BUFFER_SIZE];
  pthread_mutex_t lock;
  int readpos,writepos;
  pthread_cond_t notempty;
  pthread_cond_t notefull;
};

void init(struct prodcons *prod)
{
  pthread_mutex_init(&prod->lock,NULL);
  pthread_cond_init(&prod->notefull,NULL);
   pthread_cond_init(&prod->notefull,NULL);
   prod->readpos = 0;
   prod->writepos = 0;
}

void put(struct prodcons *prod,int data)
{
  pthread_mutex_lock(&prod->lock);
  while((prod->writepos+1)%BUFFER_SIZE == prod->readpos){
  printf("producer wait for not full");
  pthread_cond_wait(&prod->notefull,&prod->lock);
  }
  prod->buffer[prod->writepos] = data;
  prod->writepos++;
  if(prod->writepos >= BUFFER_SIZE)
  {
    prod->writepos = 0;
  }
  pthread_cond_signal(&prod->notempty);
  pthread_mutex_unlock(&prod->lock);
}

int get()



int main()
{





  return 0;
}
