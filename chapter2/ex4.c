/**
exercise 4:
编写一个能够产生下面输出的程序：
For he's a jolly good fellow!
For he's a jolly good fellow!
For he's a jolly good fellow!
Which nobody can deny!
程序中除了main()函数以外，要使用两个用户定义的函数：一个用于把上面的夸奖消息输出一次；另一个用于把最后一行输出一次。
*/
#include	<stdio.h>

//declare
void print1();
void print2();

int main(void)
{
	print1();
	print1();
	print1();
	print2();

	return 0;
}

void print1()
{
	printf("For he's a jolly good fellow!\n");
}

void print2()
{
	printf("Which nobody can deny!\n");
}
