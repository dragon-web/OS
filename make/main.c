#include<stdio.h>

int main(void)
{
  char c;
  char str[20];
  enter_String(str);
  printf("the delete string is:\n");
  scanf("%c",&c);
  delete_string(str,c);
  print_string(str);
  return 0;
}
