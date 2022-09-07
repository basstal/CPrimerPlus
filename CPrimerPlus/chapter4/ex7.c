/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that sets a type  double  variable to 1.0/3.0 and a type  float  variabl
 * to 1.0/3.0. Display each result three times -- once showing four digits to the right of the decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits
 * to the right of the decimal. Also have the program include  float.h  and display the values of  FLT_DIG  and  DBL_DIG . Are the displayed values of 1.0/3.0 consistent with these values?
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <float.h>
int main(void)
{
	double a = 1.0 / 3.0;
	float b = 1.0f / 3.0f;

	printf("float values:\n");
	printf("%.4f %.12f %.16f\n", b, b, b);
	printf("FLT_DIG value:%d\n", FLT_DIG);
	printf("*****************\ndouble values:\n");
	printf("%.4f %.12f %.16f\n", a, a, a);
	printf("DBL_DIG values:%d\n", DBL_DIG);

	return 0;
}
