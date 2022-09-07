/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that produces the following output:
  Brazil, Russia, India, China
  India, China,
  Brazil, Russia
 Have the program use two user-defined functions in addition to  main() : one named  br()  that prints “Brazil, Russia” once, and one named  ic()  that prints “India, China” once. Let  main()  take care of any additional printing tasks.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

void br()
{
	printf("Brazil, Russia");
}

void ic()
{
	printf("India, China");
}

int main()
{
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf(",\n");
	br();
	printf("\n");
	return 0;
}