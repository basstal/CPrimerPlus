#include<stdio.h>
#define MASK 1

int openorclose(int,int);

int main(void)
{
	int num,pos;
	
	printf("���������ֵ:");
	scanf("%d",&num);
	printf("�������λ��:");
	scanf("%d",&pos);
	printf("��λ��ֵΪ%s",openorclose(num,pos)?"��":"��");

	return 0;
}

int openorclose(int num,int pos)
{
	int i=0;

	num>>=pos;

	if(num & MASK ==1)
		return 1;
	else
		return 0;
}