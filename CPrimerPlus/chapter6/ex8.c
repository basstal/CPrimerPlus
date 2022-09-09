/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests two floating-point numbers and prints the value of their difference divided by their product. Have the program loop through pairs of input values until the user enters nonnumeric input.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main(void)
{
    double a, b;

    printf("Please input two floating-point numbers (nonnumeric input to quit):");

    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", a, b, a, b, (a - b) / (a * b));
        printf("Enter next pair (q to quit):");
    }
    return 0;
}
