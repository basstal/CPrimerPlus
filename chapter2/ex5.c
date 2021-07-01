/**
exercise 5:
编写一个程序，创建一个名为toes的整数变量。让程序把toes设置为10.再让程序计算两个toes的和以及toes的平方。程序应该输出所有的3个值，并分别标识它们
*/
#include	<stdio.h>


int main(void)
{
	int toes = 10;

	printf("toes = %d,toes + toes = %d,toes * toes = %d\n",toes,toes+toes,toes*toes);

	return 0;
}