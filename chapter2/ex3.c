/**
exercise 3:

编写一个程序，把您的年龄转换成天数并显示二者的值，不考虑平年和闰年的问题
*/
#include	<stdio.h>

int main(void)
{
	int ages;
	printf("How old are you?\n");
	if(scanf("%d",&ages) < 0)
		return -1;
	printf("Your age equals to %d days.\n",ages*365);

	return 0;
}