/**
对练习7进行修改，让它使用一个函数来返回计算值。
*/
#include	<stdio.h>

double func(double,double);

int main(void)
{
	double a,b;

	printf("Please input two double:");
	while( scanf("%lf %lf",&a,&b) == 2)
	{
		printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n",a,b,a,b,func(a,b));
		printf("Enter next pair(q to quit):");
	}
	return 0;
}

double func(double a, double b)
{
	return (a - b) / (a * b);
}