#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

void *thread_function(void *arg);
int main(int argc,char *argv[])
{
  int res;
  pthread_t a_thread;
  void *thread_result;
  res = pthread_create(&a_thread,NULL,thread_function,NULL);
  if(res != 0)
  {
    perror("Thread creation failed");
    exit(EXIT_FAILURE);
  }
  sleep(10);
  printf("Cancelling thread... \n");
  res = pthread_cancel(a_thread);
  if(res != 0)
  {
    perror("Thread cancelation failed");
    exit(EXIT_FAILURE);
  }
  printf("Waitting for thread to finish... \n");
  res = pthread_join(a_thread,&thread_result);
  if(res != 0)
  {
    perror("Thread join failed");
    exit(EXIT_FAILURE);
  }

  void *thread_function(void* arg)
  {
    int i ,res,j;
    sleep(1);
    res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    if(res != 0)
    {
      perror("Thread pthread_setcancelstate failed");
      exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
  }
}


