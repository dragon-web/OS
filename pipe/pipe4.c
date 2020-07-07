#include<stdio.h>
#include<memory.h>
#include<unistd.h>

int main(void)
{
  int p[2];
  pipe(p);
  write(p[1],"helloworld",10);
  char buf[128];
  memset(buf,'\0',128);
  read(p[0],buf,128);
  printf("buf = %s\n",buf);
  return 0;
}
