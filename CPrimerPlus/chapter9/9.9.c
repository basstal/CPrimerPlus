/**
 * @file 9.9.c
 * @author your name (you@domain.com)
 * @brief
 *   Redo Programming Exercise 8, but this time use a recursive function
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

double calc_power(double, int);
int main(void)
{
    double base;
    int power;
    printf("Please input a double number and an int for the power calculation (q to quit):");
    while ((scanf("%lf %d", &base, &power)) == 2)
    {
        printf("The result of %lf ^ %d is %g\n", base, power, calc_power(base, power));
        printf("Enter next pair of numbers (q to quit):");
    }
    printf("Hope you enjoyed this power trip--bye!\n");
    return 0;
}
double calc_power(double base, int power)
{
    if (base == 0)
    {
        if (power == 0)
        {
            printf("0 to the 0 power is undefined, using a value of 1.\n");
            return 1;
        }
        return 0;
    }
    else
    {
        if (power > 0)
            return calc_power(base, power - 1) * base;
        else if (power == 0)
            return 1;
        else
            return calc_power(base, power + 1) * (1 / base);
    }
}
