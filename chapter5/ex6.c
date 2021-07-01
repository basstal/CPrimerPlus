/**
exercise 6:
修改编程练习5中的程序，使它能够计算整数平方的和。
*/
#include  <stdio.h>

int main()
{
	int upper;
	int sum = 0;

	printf("Please input upper of the sum value:");
	if(scanf("%d",&upper) < 0)
		return -1;
	for(int i = 1 ; i <= upper ; ++i)
		sum += i*i;
	printf("sum = %d\n",sum);

	return 0;
}
