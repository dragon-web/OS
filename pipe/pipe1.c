#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<memory.h>
int main(void)
{
  int p[2];
  pipe(p);
  close( p[1]);//关闭写端
  char buf[128];
  memset(buf,'\0',128);
  int ret = -1;
  ret = read(p[0],buf,128);
  printf("buf = %s\n",buf);
  return 0;
}
