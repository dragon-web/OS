#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int glob = 6;

int main()
{
  int var;
  pid_t pid;
  var = 88;
  printf("in beginning :\t glob = %d\t var = %d \n",glob,var);
  if((pid = vfork())<0)
  {
    perror("vfork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0)
  {
    printf("in child,modify the var:global++,var++\n");
    glob++;
    var++;
    printf("in child:\tglob%d\t var = %d",glob,var);
    _exit(0);
  }
  else{
    printf("in parent:\t glob = %d\tvar = %d\n",glob,var);
    return 0;
  }




}
