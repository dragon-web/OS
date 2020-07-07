#include<stdio.h>
#include<unistd.h>
#include<memory.h>

int main(void)
{
  int p[2];
  pipe(p);
  char buf[128];
  close(p[1]);
  memset(buf,'\0',128);
  read(p[0],buf,128);
  printf("buf = %s\n",buf);
  return 0;
}
