#include<stdio.h>
double power(double,int);
int main(void)
{
	double a;
	int b;
	printf("Please input a double number and an int:");
	while((scanf("%lf %d",&a,&b))==2)
	{
		a=power(a,b);
		printf("The new number is %g\n",a);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip--bye!\n");
	return 0;
}
double power(double a,int b)
{
	int i;
	double d;
	d=a;
	if(b==0)
		return 1;
	else if(a==0)
		return 0;
	else if(b>0)
	{
		for(i=0;i<b-1;i++)
			a*=d;
		return a;
	}
	else if(b<0)
	{
		for(i=0;i>b-1;i--)
			a*=(1/d);
		return a;
	}
}


