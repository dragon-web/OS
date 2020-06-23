#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int glob = 6;


int main(int argc,char* argv[])
{
  pid_t pid;
  int fd;
  int i = 1;
  int status;
  char* ch1 = "hello";
  char* ch2 = "world";
  char *ch3 = "IN";

}

//父子进程对于局部变量（栈空间）执行复制操作，对于文件描述符的文件表项信息（文件的读写位置）是共享使用的
//vfork()函数创建进程时不复制父进程地址空间，在必要的时候才申请新的存储空间。
