#include<stdio.h>
double hanshu(double *,int);
int main(void)
{	
	double a[5]={1.1,2.2,3.3,4.4,5.5};
	printf("max-min=%g\n",hanshu(a,5));
	return 0;
}
double hanshu(double * a,int n)
{
	int i;
	double max,min;
	max=min=*a;
	for(i=0;i<n;a++,i++)
	{
		if(*a>max)
			max=*a;
		else if(*a<min)
			min=*a;
	}
	return(max-min);
}