#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_run(void *arg)
{
  int i = 1;
  int sum = 0;
  for(;i<=100;++i)
  {
    sum+=i;
  }
  sleep(5);
  return (void*)sum;
}

int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,thread_run,(void*)"thread1");
  void *code;
  pthread_join(tid,&code);
  printf("result is :%d\n",(long long)code);
  return 0;
}
