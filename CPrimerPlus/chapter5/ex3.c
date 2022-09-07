/**
exercise 3:
编写一个程序，该程序要求用户输入天数，然后讲该值转换为周数和天数。例如，此程序将把18天转换为2周4天。用下面的格式显示结果：
18 days are 2 weeks, 4 days.
使用一个while循环让用户重复输入天数；当用户输入一个非正数时，程序将终止循环。
*/
#include	<stdio.h>

int main()
{
	int days;

	printf("Please input days:");
	while(scanf("%d",&days) > 0 && days > 0)
	{
		printf("%d days are %d weeks, %d days.\n", days, days / 7, days % 7);
		printf("Please input days( <= 0 to quit):");
	}

	return 0;
}