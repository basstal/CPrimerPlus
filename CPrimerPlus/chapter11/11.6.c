#include<stdio.h>
#include<string.h>
char *copych(char *,char *,int);
int main(void)
{
	char *rst;
	int num;
	char ch1[255];
	char ch2[255];


	printf("Enter string for copy:\n");
	while(gets(ch2)&&ch2[0]!='\0')
	{
		printf("输入复制字符数:");
		scanf("%d",&num);
		while(getchar()!='\n');
		rst=copych(ch1,ch2,num);
		printf("The return address is %p\n",rst);
		puts(ch1);
		printf("Enter string for copy:\n");
	}
	return 0;
}	

char *copych(char *target,char *source,int n)
{
	int i=0;
	for(;*(source+i)&&i<n;i++)
		*(target+i)=*(source+i);
	if(*(source+i)=='\0')
		*(target+i)='\0';
	return target;
}


	

