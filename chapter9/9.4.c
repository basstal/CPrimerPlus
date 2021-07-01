#include<stdio.h>
double xiejunzhi(double dnum1,double dnum2);
int main(void)
{
	double dnum1,dnum2;
	double result;

	printf("Please input a double number:");
	scanf("%lf",&dnum1);
	printf("Please input another double number:");
	scanf("%lf",&dnum2);
	result=xiejunzhi(dnum1,dnum2);
	printf("The result is %g\n",result);
	return 0;
}
double xiejunzhi(double dnum1,double dnum2)
{
	
	return 1/((1/dnum1+1/dnum2)/2);
}
