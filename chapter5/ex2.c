/**
exercise 2:
编写一个程序，此程序要求输入一个整数，然后打印出从输入的值到比输入的值大10的所有整数值。要求在各个输出值之间用空格。制表符或换行符分开。
*/

#include	<stdio.h>

int main()
{
	int i;

	printf("Enter an Int value:");
	if(scanf("%d",&i) < 0)
		return -1; 
	for(int ed = i + 10 ; i <= ed ; ++i)
		printf(" %d",i);
	printf("\n");
	
	return 0;
}