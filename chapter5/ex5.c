/**
exercise 5:
改写用来找到前20个整数之和的程序addemup.c。修改该程序，目的时您能交互地告诉程序计算进行到哪里。也就是说，用一个读入的变量来代替20
*/
#include	<stdio.h>

int main()
{
	int upper;
	int sum = 0;

	printf("Please input upper of the sum value:");
	if(scanf("%d",&upper) < 0)
		return -1;
	for(int i = 1 ; i <= upper ; ++i)
		sum += i;
	printf("sum = %d\n" , sum);
	
	return 0;
}
