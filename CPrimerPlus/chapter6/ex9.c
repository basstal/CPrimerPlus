/**
 * @file ex9.c
 * @author your name (you@domain.com)
 * @brief
 *   Modify exercise 8 so that it uses a function to return the value of the calculation
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

double func(double, double);

int main(void)
{
    double a, b;

    printf("Please input two floating-point numbers:");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", a, b, a, b, func(a, b));
        printf("Enter next pair(q to quit):");
    }
    return 0;
}

double func(double a, double b)
{
    return (a - b) / (a * b);
}