#include<stdio.h>
#define LEN 10
char *readch(char *,int );

int main(void)
{
	char input[LEN];
	char *chk;

	chk=readch(input,LEN-1);
	if(chk==NULL)
		puts("Input failed.");
	else 
		puts(input);
	puts("done.\n");

	return 0;
}

char *readch(char *str,int n)
{
	int i;

	for(i=0;i<n;i++){
		str[i]=getchar();
		if(str[i]==EOF)
			break;
	}
	if(i==0)
		return NULL;
	else
	{
		str[i]='\0';
		return str;
	}
}	
