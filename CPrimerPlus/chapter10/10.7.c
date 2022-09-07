#include<stdio.h>
void copy_arr(double [],double [],int);
void copy_ptr(double *,double *,int);
int main(void)
{
	int i;
	double a[7]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
	double b[3];
		copy_arr(a+2,b,3);
	for(i=0;i<3;i++)
		printf("b[%d]=%g\n",i,b[i]);
	getchar();
	return 0;
}
void copy_ptr(double * a,double * b,int c)
{
	int i;
	for(i=0;i<c;i++)
		*(b+i)=*(a+i);
}
void copy_arr(double a[],double b[],int c)
{
	int i;
	for(i=0;i<c;i++)
		b[i]=a[i];
}