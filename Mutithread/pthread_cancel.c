#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>

void cleanup()
{
  printf("cleanup\n");
}

void* test_cancel(void)
{
  pthread_cleanup_push(cleanup,NULL);
  printf("test_cancel");
  while(1)
  {
  printf("test message");
  sleep(1);
  }
  pthread_cleanup_pop(1);
}


int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,(void*)test_cancel,NULL);
  sleep(2);
  pthread_cancel(tid);
  pthread_join(tid,NULL);
}
