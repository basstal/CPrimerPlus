#include<stdio.h>
void readch(char *ch,int n);
int main(void)
{
	char ch[41]={'\0'};
	readch(ch,40);
	printf("%s",ch);
	return 0;
}
void readch(char *ch,int n)
{
	int i=0;
	while(i<n&&((*ch)=getchar())!=' '&&(*ch)!='\t'&&(*ch)!='\n')
	{
		i++;
		ch++;
	}
}