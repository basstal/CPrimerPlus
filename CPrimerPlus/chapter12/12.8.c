#include<stdio.h>
int *make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements:");
	scanf("%d",&size);
	while(size>0)
	{
		printf("Enter the initialization value:");
		scanf("%d",&value);
		pa=make_array(size,value);
		if(pa!=NULL)
		{
			show_array(pa,size);
			free(pa);
		}
		putchar('\n');
		printf("Enter the number of elements(<1 to quit):");
		scanf("%d",&size);
	}
	printf("Done.\n");
	return 0;
}
int *make_array(int elem,int val)
{
	int *pi;
	int *begin;
	int i;

	pi=(int *)malloc(elem * sizeof(int));

    begin=pi;
	for(i=0;i<elem;pi++,i++)
		*pi=val;

	return begin;
}
void show_array(const int ar[],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		if((i+1)%8==0)
		{
			printf("%d ",ar[i]);
			printf("\n");
		}
		else 
			printf("%d ",ar[i]);
	}
}
