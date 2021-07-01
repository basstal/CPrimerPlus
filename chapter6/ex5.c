/**
编写一个程序打印一个表，表的每一行都给出一个整数、它的平方以及它的立方。要求用户输入表的上限与下限。使用一个for循环。
*/
#include	<stdio.h>
int main(void)
{
	int lower,upper;

	printf("Please input lower and upper:");
	if(scanf("%d %d",&lower,&upper) < 0)
		return -1;


	printf("%5s %10s %15s\n","Integer","Square","Cube");
	for(; lower <= upper ; ++lower)
		printf("%5d %10d %15d\n",lower, lower * lower , lower * lower * lower);

	return 0;
}