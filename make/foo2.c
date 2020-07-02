#include<stdio.h>
#include<string.h>
void delete_string(char* str,char ch)
{
  size_t sz = strlen(str);
  char *p = str;
  size_t i,j;
  for(i = 0;i < sz;i++)
  {
    if(p[i] == ch)
    {
      for(j = i;j < sz;++j)
      {
        p[j] = p[j+1];
      }
      printf("delete succesefully\n");
    }
  }
 }



