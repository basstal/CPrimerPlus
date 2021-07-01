/**
exercise 1:
编写一个程序，要求输入名字和姓氏，然后以"名字，姓氏"的格式打印
*/
#include	<stdio.h>

int main()
{
	char firstnm[40];
	char lastnm[40];

	printf("Please input your first name:");
	if(scanf("%s",firstnm) < 0)
		return -1;
	printf("Please input your last name:");
	if(scanf("%s",lastnm) < 0)
		return -1;
	printf("Hello!%s,%s\n",firstnm,lastnm);

	return 0;
}