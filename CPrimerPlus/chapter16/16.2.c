/**
 * @file 16.2.c
 * @author your name (you@domain.com)
 * @brief
 * The harmonic mean of two numbers is obtained by taking the inverses of the two
numbers, averaging them, and taking the inverse of the result. Use a #define directive
to define a macro “function” that performs this operation. Write a simple program that
tests the macro.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Common.h"

#define HARMONIC_MEAN_CALC(X, Y) (1 / (((1 / (X)) + (1 / (Y))) / 2))

int main(void)
{
    double x, y;
    printf("Please enter two values to calculate the harmonic mean : ");
    scanf("%lf %lf", &x, &y);
    printf("The harmonic mean is %lf\n", HARMONIC_MEAN_CALC(x, y));

    return 0;
}
