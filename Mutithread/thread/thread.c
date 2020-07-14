#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* thread_run(void* arg)
{
  char* msg = (char*)arg;
  while(1)
  {
    printf("new thread ...%s\n",msg);
    sleep(2);
  }

}


int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,thread_run,(void*)"thread one");

  pthread_create(&tid,NULL,thread_run,(void*)"thread one");
 while(1)
  {
    printf("main thread ...\n");
    sleep(3);
  }

  return 0;
}
