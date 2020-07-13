#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

int main(int argc,char* argv[])
{
  if(argc != 3) 
  {
    printf("Usage:%s pid signid");
    return 1;
  }
  printf("%d\n",argc);
}
