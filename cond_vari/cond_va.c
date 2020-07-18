#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

struct message
{
 int i;
 int j;
};
void *test1(int i,int j)
{
  pthread_lock();
  i++;
  j--;
  pthread_unlock();
}

void* test2(int i,int j)
{
  pthread_lock();
  if(i == j)
  {
    printf("i = j\n");
  }
  pthread_unlock();
}
int main()
{
  pthread_mutex_t work_mutex;
  int i = 3;
  int j = 7;
   



  return 0;
}
