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
	printf("��ѡ��ָ������Ԫ��<%d:",SIZE);
	while(scanf("%d",&choice)!=1){
		printf("��������������:\n");
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
		fprintf(stderr,"���ú���ʱ�����С����\n");
		exit(1);
	}
	memmove(target,ar,SIZE*sizeof(int));
	while(i<n){
		search=rand()%(size-i);
		printf("���ѡ���Ԫ��Ϊ%d\n",target[search]);
		Delete(target,size-i,search);
		i++;
	}
}