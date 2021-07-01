/**
exercise 6:
编写一个程序，设置一个值为1.0/3.0的double类型变量和一个值为1.0/3.0的float类型变量。每个变量的值显示三次：一次在小数点右侧显示4个数字，一次在小数点右侧显示12个数字，另一次在小数点右侧显示16个数字。同时要让程序包括float.h文件，并显示FLT_DIG和DBL_DIG的值。1.0/3.0的显示值与这些值一致吗？
*/
#include	<stdio.h>
#include	<float.h>
int main(void)
{
	double a = 1.0/3.0;
	float b = 1.0/3.0;

	printf("float values:\n");
	printf("%8.4f %16.12f %20.16f\n",b,b,b);
	printf("FLT_DIG value:%d\n",FLT_DIG);
	printf("*****************\ndouble values:\n");
	printf("%8.4f %16.12f %20.16f\n",a,a,a);
	printf("DBL_DIG values:%d\n",DBL_DIG);

	return 0;
}