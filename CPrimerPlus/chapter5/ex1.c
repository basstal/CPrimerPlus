/**
exercise 1:
编写一个擦洗。将用分钟表示的时间转换成以小时和分钟表示的时间。使用#define或者const来创建一个代表60的符号常量。使用while循环来允许用户重复键入值，并且当键入一个小于等于0的时间时终止循环。
*/
#include  <stdio.h>

int main()
{
	const int hour2min = 60;
	int minutes;

	printf("Please input minutes( < 0 quit ):");
	while( scanf("%d",&minutes) > 0 && minutes >= 0)
	{
		printf("%d minutes equal to %d hours and %d minutes.\n",minutes , minutes / hour2min , minutes % hour2min);
		printf("Please input minutes( < 0 quit ):");
	}
	printf("bye!\n");

	return 0;
}
