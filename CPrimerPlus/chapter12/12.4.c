#include<stdio.h>
int test(void);
static int count=0;
int main(void)
{
	int i,num;
	for(i=0;i<10;i++)
		num=test();
	printf("函数调用次数为:%d\n",num);
	return 0;
}
int test(void)
{
	count++;
	return count;
}
