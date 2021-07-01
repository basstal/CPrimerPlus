#include<stdio.h>
void save_dat(int size,int n, double ar[n][size]);
double ccl_each_set(int n, double ar[n]);
double ccl_all_set(int size,int n, double ar[n][size]);
double maxnum(int size,int n, double ar[n][size]);
void print(int size,int n, double ar[n][size]);
int main(void)
{
	int size = 5,n = 3;
	double arr[n][size];
	double av1,av2,av3,avall;
	double max;

	save_dat(size,n,arr);
	av1=ccl_each_set(size,arr[0]);
	av2=ccl_each_set(size,arr[1]);
	av3=ccl_each_set(size,arr[2]);
	avall=ccl_all_set(size,n,arr);
	max=maxnum(size,n,arr);
	print(size,n,arr);
	printf("The max number is %g\n",max);
	printf("%10s%10s%10s%15s\n","average1","average2","average3","averageall");
	printf("%10g%10g%10g%15g\n",av1,av2,av3,avall);
	
	return 0;
}

void save_dat(int size,int n, double ar[n][size])
{
	int i,j;
	printf("Enter %d double number into %d number-sets:\n",size,n);
	for(i=0;i<n;i++)
	{
		printf("Please enter number-set #%d:\n",i+1);
		for(j=0;j<size;j++)
		{
			printf("value #%d:",j+1);
			scanf("%lf",&ar[i][j]);
		}
	}
}
double ccl_each_set(int n,double ar[n])
{
	int i;
	double total=0;
	for(i=0;i<n;ar++,i++)
		total+=*ar;
	return(total/n);
}
double ccl_all_set(int size,int n,double ar[n][size])
{
	int i;
	double total=0;
	for(i=0;i<n;i++)
		total+=ccl_each_set(size,ar[i]);
	return(total/n);
}
double maxnum(int size,int n,double ar[n][size])
{
	int i,j;
	double max;

	for(i=0;i<n;i++)
		for(j=0;j<size;j++)
			max=max>ar[i][j]?max:ar[i][j];
	return(max);
}

void print(int size,int n,double ar[n][size])
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<size;j++)
			printf("ar[%d][%d]=%3g%3c",i,j,ar[i][j],' ');
		printf("\n");
	}
}






