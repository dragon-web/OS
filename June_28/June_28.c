#include<stdio.h>
#include<string.h>
#include<signal.h>

void handler(int sig)
{
  if(SIGPIPE == sig)
  {
    printf("recv SIGPIPE\n");
  }
}

int main(void)
{
  int p[2];
  signal(SIGPIPE,handler);
  pipe(p);
  close(p[0]);
  int ret = 0;
  ret = write(p[1],"helloworld",10);
  printf("ret = %d\n",ret);
}
