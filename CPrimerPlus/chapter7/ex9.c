/**
 * @file ex9.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that accepts a positive integer as input and then displays all the prime numbers smaller than or equal to that number.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int upper;
    printf("Please input a positive integer (enter q to quit):");
    while (scanf("%d", &upper) == 1 && upper > 0)
    {
        for (int n = 2; n < upper; ++n)
        {
            int is_prime = 1;
            for (int div = 2; (div * div) <= n; ++div)
                if (n % div == 0)
                    is_prime = 0;
            if (is_prime == 1)
                printf("%d is is_prime.\n", n);
        }
        printf("Please input another positive integer (enter q to quit):");
    }

    return 0;
}
