#include<stdio.h>
double hanshu(double *,int);
int main(void)
{
	double a[10]={1.1,2.2,3.3,10.10,4.4,5.5,6.6,7.7,8.8,9.9,};
	printf("max=%g\n",hanshu(a,10)+1);
	return 0;
}

double hanshu(double * a,int n)
{
	int i,re;
	double max;
	for(i=0;i<n;a++,i++)
		if(*a>max)
		{
			max=*a;
			re=i;
		}

	return re;
}