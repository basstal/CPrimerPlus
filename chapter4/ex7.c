/**
exercise 7:
编写一个程序，要求用户输入行驶的英里数和消耗汽油的加仑数。接着应该计算和显示消耗每加仑汽油行驶的英里数，显示方式是在小数点右侧显示一个数字。然后，根据1加仑约等于3.785升，1英里约等于1.609公里的规则，它应该把每加仑英里数转换成每100公里的升数，并显示结果，显示方式是在小数点右侧显示一个数字。用符号常量表示两个转换系数（const或#define）。
*/
#include	<stdio.h>

int main()
{
	const float gl2lt = 3.785,ml2km = 1.609;
	float miles,gallons;

	printf("Please input miles:");
	if(scanf("%f",&miles) < 0)
		return -1;
	printf("Please input gallons:");
	if(scanf("%f",&gallons) < 0)
		return -1;
	printf("1 gallon drive %.1f miles\n", miles / gallons);
	printf("100 kilometers use %.1f litres\n", gallons * gl2lt / miles * ml2km * 100);

	return 0;
}