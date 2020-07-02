#include<stdio.h>
#include<unistd.h>
#include<memory.h>

int main()
{
  int p[2];
  pipe(p);
  write(p[1],"helloworld",10);
  char buf[128];
  memset(buf,'\0',128);
  int ret = -1;
  read(p[0],buf,128);
  printf("buf = %s\n",buf);
  return 0;
}
