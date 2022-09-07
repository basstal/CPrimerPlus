/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that asks for your first name, your last name, and then prints the names in the format  last, first .
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
	char first_name[40];
	char last_name[40];

	printf("Please input your first name than your last name (each name less than 40 letters):");
	if (scanf("%s %s", first_name, last_name) < 0)
		return -1;
	printf("Hello! %s %s.\n", last_name, first_name);

	return 0;
}