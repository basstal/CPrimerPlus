/**
exercise 4:
编写一个程序，读入一个浮点数，并分别以小数形式和指数形式打印。输出应如同下面格式:
The input is 21.290000 or 2.129000e+001
*/

#include	<stdio.h>
int main(void)
{
	double a;

	printf("Enter a double value:\n");
	if(scanf("%lf",&a) < 0)
		return -1;
	printf("The input is %8.6f or %7.6e\n",a,a);

	return 0;
}