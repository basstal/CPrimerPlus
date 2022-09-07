#include<stdio.h>
void larger_of(double *,double *);
int main()
{
	double x,y;
	printf("Please input two double number:");
	while((scanf("%lf %lf",&x,&y))==2)
	{
		larger_of(&x,&y);
		printf("The modified values are %g and %g.\n",x,y);
		printf("Next two values(q to quit):");
	}
	printf("bye!\n");
	return 0;
}
void larger_of(double * x,double * y)
{
	if(*x<*y)
		*x=*y;
	else *y=*x;
}
