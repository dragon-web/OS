#define LL_INSERT (item,list) do{
   item->prev = NULL;
   list->next = list;
   list->prev = item;
   list = item;

}while(0)

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


typedef struct NWORKER
{
  pthread_t thread;
  
  struct NWORKER *prev;
  struct NWORKER *next;
}NWORKER;


typedef struct EJOB
{ 
    void (*job_func)(struct NJOB* job);
    void *user_data;
    
    struct EJOB* prev;
    struct EJOB* next;

}EJOB;

typedef struct NTHREADPOOL
{
  struct NWORKER *workers;
  struct NJOB *jobs;
  pthread_mutex_t mutex;

}NTHREADPOOL;



int main(int argc,char* argv[])
{


  return 0;
}
