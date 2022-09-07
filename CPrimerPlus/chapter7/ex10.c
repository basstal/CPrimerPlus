/**
1988年United states Federal Tax Schedule是近期最基本的。它分为4类，每类有两个等级。下面是其摘要：美元数为应征税的收入
种类				税金
单身				前17850美元按15%，超出部分按28%
户主				前23900美元按15%，超出部分按28%
已婚，共有		前29750美元按15%，超出部分按28%
已婚，离异		前14875美元按15%，超出部分按28%
编写一个程序，让用户指定税金种类和应征税收入，然后计算税金。使用循环以便用户可以多次输入。
*/
#include	<stdio.h>
#define SINGLE 17850
#define MARRIED 29750
#define DIVORCED 14875
#define HOUSEHOLDER 23900
#define NORMAL_RATE 0.15
#define BEYOND_RATE 0.28
//根据薪金和税收的范围计算税金
double taxfunc(int bound,double salary);

int main(void)
{
	int kind;

	printf("Enter your kind(1-4):");
	while( scanf("%d",&kind) == 1 && kind > 0 && kind < 5)
	{
		double salary;
		printf("Please input your salary:");
		if(scanf("%lf",&salary) < 0)
			return -1;
		switch(kind)
		{
		case 1:
			printf("your tax = %.2f\n",taxfunc(SINGLE,salary));
			break;
		case 2:
			printf("your tax = %.2f\n",taxfunc(HOUSEHOLDER,salary));
			break;
		case 3:
			printf("your tax = %.2f\n",taxfunc(MARRIED,salary));
			break;
		case 4:
			printf("your tax = %.2f\n",taxfunc(DIVORCED,salary));
			break;
		}
		printf("Enter another kind(q to quit):");
	}
	return 0;
}

double taxfunc(int bound,double salary)
{
	if(salary > bound)
		return (salary - bound) * BEYOND_RATE + bound * NORMAL_RATE;
	else
		return salary * NORMAL_RATE;
}