/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that asks the user to enter a height in centimeters and then displays the height in centimeters and in feet and inches. Fractional centimeters and inches should be allowed, and the program should allow the user to continue entering heights until a nonpositive value is entered. A sample run should look like this:
  Enter a height in centimeters:  182
  182.0 cm = 5 feet, 11.7 inches
  Enter a height in centimeters (<=0 to quit):  168.7
  168.0 cm = 5 feet, 6.4 inches
  Enter a height in centimeters (<=0 to quit):  0
  bye
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
	double height;

	printf("Enter a height in centimeters (nonpositive value to quit):");
	while (scanf("%lf", &height) > 0 && height > 0)
	{
		int foot = height / 30.48;
		printf("%.1f cm = %d feet, %.1f inches\n", height, foot, height / 2.54 - foot * 12);
		printf("Enter a height in centimeters (nonpositive value to quit):");
	}
	printf("bye\n");

	return 0;
}