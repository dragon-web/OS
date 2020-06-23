#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void test(void)
{
  pid_t pid;
  pid = vfork();
  if(pid == -1)
  {
    perror("vfork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0)
  {
    printf("1:chaild pid = %d,ppid = %d\n",getpid(),getppid());
    return;
  }
  else{
    printf("2:parent pid = %d,ppid = %d\n",getpid(),getppid());
  }
}
void fun(void)
{
  int i;
  int buf[100];
  for(i = 0;i < 100;++i)
  {
    buf[i] = 0;
    printf("3:child pid = %d,ppid = %d",getpid(),getppid());
  }
}

int main()
{
  pid_t pid;
  test();
  fun();
  return 0;
}
