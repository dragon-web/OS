#define N 100//定义这个缓冲区100为满
int count = 0;

void producer(void)
{
  int item;
  while(1)
  {
    item = produce_item();//生产数据
    if(count == N)//如果满了
    {
      sleep();//进入休眠状态
    }
    else{
    insert_item(item);//没有就把新产生的数据放入缓冲区
    count = count +1;
    if(count == 1)  
    {
      wakeup(consumer);
    }
  }
}





