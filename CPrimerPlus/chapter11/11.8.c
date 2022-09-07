#include<stdio.h>
void exchange(char *str);
int main(void)
{
	char *pstr;
	char str[100];

	printf("Enter a string:\n");
	while(gets(str)&&str[0]!='\0')
	{	
		exchange(str);
		puts(str);
		printf("Enter a string:\n");
	}
	return 0;
}
void exchange(char *str)
{
	int i=0,num=0;
	char temp;
    char *begin;

	begin=str;
	while(*str++)
		num++;
	//printf("%d\n",num);
	str=begin;
	for(i=0;i<(num/2);i++)
	{
		temp = *(str+i);
		*(str+i) = *(str+num-1-i);
		*(str+num-1-i) = temp;
	}
}




