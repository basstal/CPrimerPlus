#include<stdio.h>
void duzimu(char);
void clean(void);
int main(void)
{
	char c;
	printf("Please input:\n");
	while((c=getchar())!=EOF)
	    duzimu(c);
	return 0;
}
void duzimu(char c)
{
	if(('A'<=c&&c<='Z')||('a'<=c&&c<='z'))
		if(c<95)
			printf("%c in %d\n",c,c);
		else 
			printf("%c in %d\n",c,c);
		else
			printf("It's not a character.\n");
}

void clean(void)
{
	while(getchar()!='\n')continue;
}
