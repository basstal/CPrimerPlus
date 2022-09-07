#include<stdio.h>
#include<ctype.h>
char get_first(void);
int main(void)
{
  char c;
  c=get_first();
  printf("The first char is %c\n",c);
  return 0;
}
char get_first(void)
{
  char ch;
  ch=getchar();
  while(isspace(ch))
	  ch=getchar();
  return ch;
}
