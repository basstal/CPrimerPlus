/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that asks for an integer and then prints all the integers from (and including) that value up to (and including) a value larger by 10. (That is, if the input is 5, the output runs from 5 to 15.) Be sure to separate each output value by a space or tab or newline.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main()
{
	int i;

	printf("Enter an integer value:");
	if (scanf("%d", &i) < 0)
		return -1;
	for (int ed = i + 10; i <= ed; ++i)
		printf("%d\t", i);
	printf("\n");

	return 0;
}