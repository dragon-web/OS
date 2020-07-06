
#define N 10
typedef int semaphore; //这里信号量本质还是int 只不过是取了个别名
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

void producer(void)
{
  int item;
  while(1)
  {
    item = produce_item();
    down(&empty);//空槽数减一
    down(&mutex);//进入临界区
    insert_item(&item);//放入缓冲区
    up(&mutex);//离开临界区
    up(&full);//满槽数目加一
  }
}

void consumer(void)
{
  int item;
  while(1)
  {
    down(&full);//满槽数目减一
    down(&mutex);//进入临界区
    item = remove_item();
    up(&mutex);//离开临界区
    up(&empty);//空槽数目加一
    consume_item(item);
  }
}
