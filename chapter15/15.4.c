#include<stdio.h>
#define MASK 1

int openorclose(int,int);

int main(void)
{
	int num,pos;
	
	printf("输入测试数值:");
	scanf("%d",&num);
	printf("输入检验位置:");
	scanf("%d",&pos);
	printf("该位的值为%s",openorclose(num,pos)?"开":"关");

	return 0;
}

int openorclose(int num,int pos)
{
	int i=0;

	num>>=pos;

	if(num & MASK ==1)
		return 1;
	else
		return 0;
}