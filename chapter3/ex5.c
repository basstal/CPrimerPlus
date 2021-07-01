/**
exercise 5:
一年约有3.156e7s。编写一个程序，要求输入您的年龄，然后显示该年龄合多少秒。
*/
#include	<stdio.h>

int main()
{
	int age;

	printf("Please input your age:\n");
	if(scanf("%d",&age) < 0)
		return -1;
	printf("Your age equal to %.2e seconds\n",age * 3.156e7);

	return 0;
}
