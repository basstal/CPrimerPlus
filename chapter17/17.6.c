#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define T1 1
typedef enum{FALSE,TRUE} Bool;

int comp(const void *p1,const void *p2);
Bool srch(int num[],int count,int n);

int main(void)
{
	int num[SIZE];
	int n;
	int size;
	int i;

	printf("������������ɵ��������:");
	scanf("%d",&size);
	for(i=0;i<SIZE;i++)
		num[i]=rand()%size;
	for(i=0;i<SIZE;i++)
		printf("%d ",num[i]);
	putchar('\n');
	while(1)
	{
	printf("������Ҫ���ҵ�����:");
	scanf("%d",&n);
	qsort(num,SIZE,sizeof(int),comp);
	for(i=0;i<SIZE;i++)
		printf("%d ",num[i]);
	putchar('\n');
	if(srch(num,SIZE,n))
		printf("��������������!\n");
	else
		printf("����������������!\n");
	}
	return 0;
}

int comp(const void *p1,const void *p2)
{
	int *a,*b;

	a=(int *)p1;
	b=(int *)p2;

	if(*a<*b)
		return -1;
	else if(*a==*b)
		return 0;
	else
		return 1;

}

Bool srch(int num[],int count,int n)
{
	int temp=comp(&num[count/2],&n);
	
	if(temp==0)
		return TRUE;
	else if(temp<0)
		return srch(&num[count/2+1],count/2-1,n);
	else{
		if(count==0)
			return FALSE;
		return srch(num,count/2,n);
	}
}


