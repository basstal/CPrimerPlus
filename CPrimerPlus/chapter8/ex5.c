#include<stdio.h>
int main(void)
{
  int tc,cc,min,max;
  char c;

  tc=cc=min=max=0;
  printf("Please pick a number:\n");
  printf("Let me guess:\n");
  cc=50;printf("%d?\n",cc);
  printf("you want bigger or smaller(B/S):\n");
  do{
    if((c=getchar())=='B')
      {do{
      min=cc;
      max=cc+50;
      cc=(min+max)/2;
      printf("%d?(0)You want B or S(R for right):\n",cc);
      if((c=getchar())=='B')
	continue;
      if(c=='S')
	tc=1;
      if(c=='R')
	tc=2;
      }while(tc==0);
      if(tc==2)break;
      tc=0;
      max=cc;
      cc=(min+max)/2;
      do{
      printf("%d(1)You want B or S(R for right):\n",cc);
      if((c=getchar())=='B')
	{min=cc;
	cc=(min+max)/2;}
      else if(c=='S')
	{max=cc;
	cc=(min+max)/2;}
      else if(c=='R')
	tc=2;
      }while(tc==0);break;}
    if((c=getchar())=='S')
      {do{
      max=cc;
      min=cc-50;
      cc=(max+min)/2;
      printf("%d(3)you want B or S(R for right):\n",cc);
      if((c=getchar())=='S')
	continue;
      if(c=='B')
	tc=1;
      if(c=='R')
	tc=2;
      }while(tc==0);
      if(tc==2)break;
      tc=0;
      do{
      max=cc;
      cc=(min+max)/2;
      printf("%d(4)you want B or S or R:\n",cc);
      if((c=getchar())=='S')
	{min=cc;
	cc=(min+max)/2;}
      if(c=='B')
	{max=cc;
	cc=(min+max)/2;}
      if(c=='R')
	tc=2;
      }while(tc==0);break;}
    }while(tc!=2);
  printf("%d,Am i right?\n",cc);
  return 0;
}




