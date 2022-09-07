/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads in a floating-point number and prints it first in decimal-point notation and then in exponential notation. Have the output use the following formats (the number of digits shown in the exponent may be different for your system):
a.	   The input is  21.3  or  2.1e+001 .
b.	   The input is  +21.290  or  2.129E+001 .
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
	float a;

	printf("Please input a float number:");
	if (scanf("%f", &a) < 0)
		return -1;
	printf("The input is %.1f or %.1e\n", a, a);
	printf("The input is %+.3f or %.3E\n", a, a);

	return 0;
}