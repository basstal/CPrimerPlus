/**
exercise 4:
编写一个程序让用户按厘米输入一个高度值，然后，程序按照厘米和英尺英寸显示这个高度值。允许厘米和英寸的值出现小数部分。出现允许用户继续输入，直到用户输入一个非正的数值。出现运行的示例如下所示：
Enter a height in centimeters: 182
182.0 cm = 5 feet, 11.7 inches
Enter a height in centimeters(<=0 to quit) : 168
168.0 cm = 5 feet, 6.1 inches
Enter a height in centimeters(<=0 to quit) : 0
bye
*/
#include  <stdio.h>

int main()
{
	float height;

	printf("Enter a height in centimeters:");
	while( scanf("%f",&height) > 0 && height > 0)
	{
		int foot = height / 2.54 / 12;
		printf("%.1f cm = %d feet, %.1f inches\n", height , foot , height / 2.54 - foot * 12 );
		printf("Enter a height in centimeters(<=0 to quit):");
	}
	printf("bye\n");

	return 0;
}