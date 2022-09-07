#include<stdio.h>
void copy_arr(double [],double [],int);
int main(void)
{
	int i,j;
	double a[3][3]={
		{1.0,5.4,3.7},
		{3.5,7.2,9.5},
		{2.2,3.7,1.5}
	};
	double b[3][3];
	for(i=0;i<3;i++)
		copy_arr(a[i],b[i],3);
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
			printf("b[%d][%d]=%5g%3c",j,i,b[j][i],' ');
		printf("\n");
	}
	return 0;
}
void copy_arr(double a[],double b[],int c)
{
	int i;
	for(i=0;i<c;i++)
		b[i]=a[i];
}