/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that produces the following output:
  For he's a jolly good fellow!
  For he's a jolly good fellow!
  For he's a jolly good fellow!
  Which nobody can deny!
 Have the program use two user-defined functions in addition to  main() : one named  jolly()  that prints the “jolly good” message once, and one named  deny()  that prints the final line once.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// declare
void print1();
void print2();

int main(void)
{
	print1();
	print1();
	print1();
	print2();

	return 0;
}

void print1()
{
	printf("For he's a jolly good fellow!\n");
}

void print2()
{
	printf("Which nobody can deny!\n");
}
