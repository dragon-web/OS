#define N 100
#define TRUE 1
#include<stdio.h>
#include<unistd.h>

int count = 0;

void producer(void)
{
  int item;
  while(TRUE)
  {
    item = producer_item();
    if(count == N)
    {
      sleep();
    }
    insert_item(item);
    count++;
    if(count == 1)
    {
      wakeup(consumer);
    }
  }
}

void comsumer()
{
  int item;
  while(TRUE)
  {
    if(count == 0)
    {
      sleep();
    }
    item = remove_item();
    count--;
    if(count == N-1)
    {
      wakeup(producer);
      consume_item(item);
    }
  }
}

int main()
{



  return 0;
}
