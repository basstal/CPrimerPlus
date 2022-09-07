/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that converts your age in years to days and displays both values. At this point, don’t worry about fractional years and leap years.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
	int ages;
	printf("How old are you?\n");
	if (scanf("%d", &ages) < 0)
		return -1;
	printf("Your %d age equals to %d days.\n", ages, ages * 365);

	return 0;
}