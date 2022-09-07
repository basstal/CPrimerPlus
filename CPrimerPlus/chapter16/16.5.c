#include"normal.h"
#include<time.h>

#define SIZE 10

void pick(const int [],int,int);
void Delete(int [],int,int);

int main(void)
{

	int source[SIZE];
	int i;
	int choice;

	for(i=0;i<SIZE;i++)
		source[i]=i;
	printf("请选择指定数量元素<%d:",SIZE);
	while(scanf("%d",&choice)!=1){
		printf("请重新输入数字:\n");
		while(getchar()!='\n');
	}
	pick(source,SIZE,choice);

	return 0;
}

void Delete(int ar[],int size,int search)
{
	int i;
	for(i=search;i<size-1;i++)
		ar[i]=ar[i+1];
	ar[size-1]=0;
}

void pick(const int ar[],int size,int n)
{
	int i=0;
	int target[SIZE];
	int search;

	if(n>SIZE){
		fprintf(stderr,"调用函数时数组大小错误\n");
		exit(1);
	}
	memmove(target,ar,SIZE*sizeof(int));
	while(i<n){
		search=rand()%(size-i);
		printf("随机选择的元素为%d\n",target[search]);
		Delete(target,size-i,search);
		i++;
	}
}