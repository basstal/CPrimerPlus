/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that reads in a floating-point number and prints it first in decimal-point notation, then in exponential notation, and then, if your system supports it, p notation. Have the output use the following format (the actual number of digits displayed for the exponent depends on the system):
  Enter a floating-point value:  64.25
  fixed-point notation: 64.250000
  exponential notation: 6.425000e+01
  p notation: 0x1.01p+
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
	double a;

	printf("Enter a floating-point value:  ");
	if (scanf("%lf", &a) < 0)
		return -1;
	printf("fixed-point notation: %8.6f\n", a);
	printf("exponential notation: %7.6e\n", a);
	// Address Printing: %p ??
	// printf("p notation: %p\n", (void*)(&a));

	return 0;
}