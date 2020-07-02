#include<stdio.h>
#include<unistd.h>
#include<memory.h>

int main()
{
  int p[2];
  pipe(p);
  write(p[1],"helloworld",10);
  close(p[1]);//断开当前进程与管道写端联系
  char buf[128];
  memset(buf,'\0',128);
  int ret = -1;
  ret = read(p[0],buf,3);
  printf("first ,ret = %d,buf = %s\n",ret,buf);
  ret = read(p[0],buf,15);
  printf("second,ret = %d,buf = %s\n",ret,buf);
  return 0;
}
