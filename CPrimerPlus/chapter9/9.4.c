/**
 * @file 9.4.c
 * @author your name (you@domain.com)
 * @brief
 *   The harmonic mean of two numbers is obtained by taking the inverses of the two numbers, averaging them, and taking the inverse of the result. Write a function that takes two  double  arguments and returns the harmonic mean of the two numbers.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
double harmonic_mean(double num0, double num1);
int main(void)
{
    double num0, num1;
    double result;

    printf("Please input a double number:");
    scanf("%lf", &num0);
    printf("Please input another double number:");
    scanf("%lf", &num1);
    result = harmonic_mean(num0, num1);
    printf("The harmonic mean of %lf and %lf is %g\n", num0, num1, result);
    return 0;
}

double harmonic_mean(double num0, double num1)
{
    return 1 / ((1 / num0 + 1 / num1) / 2);
}
