#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  int pd[2];
  pid_t pid;

  pipe();
  if(pipe(pd)<0)
  {
    perror("pipe()");
    exit(1);

  }

  pid = folk();


  return 0;
}
