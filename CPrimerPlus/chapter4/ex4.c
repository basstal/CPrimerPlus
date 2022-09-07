/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests your height in inches and your name, and then displays the information in the following form:
  Dabney, you are 6.208 feet tall
 Use type  float , and use  /  for division. If you prefer, request the height in centimeters and display it in meters.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
	float inches;
	char name[40];

	printf("Please input your height in inches and your name:");
	if (scanf("%f %s", &inches, name) < 0)
		return -1;
	printf("%s, you are %.3f feet tall\n", name, inches / 12);

	return 0;
}