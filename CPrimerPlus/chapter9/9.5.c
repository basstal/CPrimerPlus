/**
 * @file 9.5.c
 * @author your name (you@domain.com)
 * @brief
 *   Write and test a function called  larger_of()  that replaces the contents of two  double variables with the maximum of the two values. For example,  larger_of(x,y)  would reset both  x  and  y  to the larger of the two.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void larger_of(double *, double *);

int main()
{
    double x, y;
    printf("Please input two double number:");
    while ((scanf("%lf %lf", &x, &y)) == 2)
    {
        larger_of(&x, &y);
        printf("The modified values are %g and %g.\n", x, y);
        printf("Next two values (q to quit):");
    }
    printf("bye!\n");
    return 0;
}

void larger_of(double *x, double *y)
{
    if (*x < *y)
        *x = *y;
    else
        *y = *x;
}
