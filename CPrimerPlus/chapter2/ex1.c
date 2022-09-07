/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that uses one  printf()  call to print your first name and last name on one line, uses a second  printf()  call to print your first and last names on two separate lines, and uses a pair of  printf()  calls to print your first and last names on one line. The output should look like this (but using your name):
 *   Gustav Mahler <- First print statement
 *   Gustav        <- Second print statement
 *   Mahler        <- Still the second print statement
 *   Gustav Mahler <- Third and fourth print statement
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
	printf("Stephen Prata\n");
	printf("Stephen\nPrata\n");
	printf("Stephen");
	printf("Prata\n");

	return 0;
}