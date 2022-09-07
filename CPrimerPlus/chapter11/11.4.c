#include<stdio.h>
#define SIZE 41
char * strch(char *pch,char ch);
int main(void)
{
	char *pch,*pc;
	char ch;
	char str[SIZE];

	pch=str;
	printf("Enter a string:\n");
	while(gets(str))
	{
		printf("Enter the char you want to search:");
		scanf("%c",&ch);
		while(getchar()!='\n');
		pc=strch(pch,ch);
		if(pc==NULL)
			printf("Sorry,%c didn't found in string.\n",ch);
		else
			printf("The address is %p.\n",pc);
		printf("Enter a string:\n");
	}
	return 0;
}



char * strch(char *pch,char ch)
{
	while(*pch)
	{
		if(*pch!=ch)
		{
			pch++;
			continue;
		}
		else
			return pch;
	}
	return NULL;
}
