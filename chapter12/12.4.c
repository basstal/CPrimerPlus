#include<stdio.h>
int test(void);
static int count=0;
int main(void)
{
	int i,num;
	for(i=0;i<10;i++)
		num=test();
	printf("�������ô���Ϊ:%d\n",num);
	return 0;
}
int test(void)
{
	count++;
	return count;
}
