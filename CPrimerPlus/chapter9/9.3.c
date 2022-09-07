#include<stdio.h>
void hanshu(char,int,int);
int main()
{
	char a;
	int c,d;

	printf("Enter a character(# to quit):");
	while((a=getchar())!='#')
	{
		if(a=='\n')
			continue;
		printf("Enter number of columns and number of rows:");
		if((scanf("%d %d",&c,&d))!=2)
			break;
		hanshu(a,c,d);
		printf("Enter next character (# to quit):");
	}
	printf("Bye!\n");
	return 0;
}
void hanshu(char c,int a,int b)
{
	int i,j;
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
			putchar(c);
		printf("\n");
	}
}
