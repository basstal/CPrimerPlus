/**
exercise 3:
编写一个程序，读取一个浮点数，并且首先以小数点记数法，然后以指数记数法打印之。输出使用下列形式：
a.The input is 21.3 or 2.1e+001
b.The input is +21.290 or 2.129E+001
*/
#include	<stdio.h>

int main()
{
	float a;

	printf("Please input a float number:");
	if(scanf("%f",&a) < 0)
		return -1;
	printf("The input is %.1f or %.1e\n",a,a);
	printf("The input is %+.3f or %.3E\n",a,a);

	return 0;
}