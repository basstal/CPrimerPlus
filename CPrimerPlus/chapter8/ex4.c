#include<stdio.h>
#include<ctype.h>
int main(void)
{
  char c,last;
  int a,b,i;

  a=b=0;
  printf("Please input:\n");
  for(i=0,last=' ';(c=getchar())!=EOF;i++)
  {
    if(last==' '||c==' ')
	{
		last=c;
		if(c!=' ')
		{
			b++;
			continue;
		}
	}
	else
		a++;
  }
  printf("There are %d characters,averagenum=%d.\n",b,(a+b)/b);
  return 0;
}

