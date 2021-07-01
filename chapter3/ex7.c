/**
exercise 7:
1英寸等于2.54cm。编写一个程序，要求输入您的身高（以英寸为单位），然后显示该身高值等于多少厘米。如果您愿意，也可以要求以厘米为单位输入身高，然后以英寸为单位进行显示。
*/

#include	<stdio.h>

int main()
{
	float hight;

	printf("Please input your height in centimeters:\n");
	if(scanf("%f",&hight) < 0)
		return -1;
	printf("Your height is %.2f centimeters, and %.2f inches\n",hight, hight / 2.54);

	return 0;
}