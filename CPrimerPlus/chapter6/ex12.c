/**
 * @file ex12.c
 * @author your name (you@domain.com)
 * @brief
 *   Consider these two infinite series:
  1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
  1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
   Write a program that evaluates running totals of these two series up to some limit of number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself an even number of times is 1. Have the user enter the limit interactively; let a zero or negative value terminate input. Look at the running totals after 100 terms, 1000 terms, 10,000 terms. Does either series appear to be converging to some value?
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main(void)
{
	int times;
	printf("Please input the times (zero or negative value to quit):");
	while (scanf("%d", &times) > 0 && times > 0)
	{
		double sqa = 0;
		double sqb = 0;

		for (int i = 1; i <= times; ++i)
		{
			sqa += 1.0 / i;
			if (i % 2 == 0)
				sqb -= 1.0 / i;
			else
				sqb += 1.0 / i;
		}
		printf("squence 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... in %d times valued %.2g\n", times, sqa);
		printf("squence 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... in %d times valued %.2g\n", times, sqb);
		printf("Please input the times (zero or negative value to quit):");
	}

	return 0;
}