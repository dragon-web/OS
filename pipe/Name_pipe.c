#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void handler(int sig)
{
  printf("sig = %d",sig);
}
int main(void)
{
  int j;
  signal(SIGPIPE,handler);
  unlink("FIFO");
  mkfifo("FIFO",0644);
  pid_t pid;
  pid = fork();
  if(pid ==0)
  {
   int fd;
   fd = open("FIFO",O_RDONLY);
   close(fd);
  }
  else{
    int fd;
     fd = open("FIFO",O_WRONLY);
     int ret;
     sleep(1);
     ret = write(fd,"helloworld",10);
     printf("ret = %d\n",ret);
  }
  return 0;
}
