/**
编写一个程序。该程序读取整数，直到输入0.输入终止后，程序应该报告输入的偶数（不包括0）总个数、偶数的平均值，输入的奇数总个数以及奇数的平均值。
*/
#include	<stdio.h>

int main(void)
{
	int i;
	int odd,even;
	double oddsum,evensum;

	odd = even = oddsum = evensum = 0;

	printf("Enter integer (0 to quit):");
	while( scanf("%d", &i) > 0 && i != 0)
	{
		if(i % 2 == 0)
		{
			++even;
			evensum += i;
		}
		else
		{
			++odd;
			oddsum += i;
		}
	}
	printf("odd numbers = %d , even numbers = %d\n",odd , even);
	printf("odd avg = %.2f , even avg = %.2f\n",oddsum / odd , evensum / even);

	return 0;
}
