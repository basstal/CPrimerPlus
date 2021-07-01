/**
编写一个程序，要求输入两个浮点数，然后打印出用二者的差值除以二者的乘积所得的结果。在用户键入非数字的输入之前程序循环处理每对输入值。
*/
#include	<stdio.h>
int main(void)
{
	double a,b;


	printf("Please input two double:");

	while( scanf("%lf %lf",&a,&b) == 2)
	{
		printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n",a,b,a,b,(a - b) / (a * b));
		printf("Enter next pair(q to quit):");
	}
	return 0;
}