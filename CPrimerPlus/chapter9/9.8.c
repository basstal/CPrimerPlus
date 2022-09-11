/**
 * @file 9.8.c
 * @author your name (you@domain.com)
 * @brief
 *    Chapter   6   , “C Control Statements: Looping,” ( Listing   6.20   ) shows a  power()  function that returned the result of raising a type  double  number to a positive integer value. Improve the function so that it correctly handles negative powers. Also, build into the function that 0 to any power other than 0 is 0 and that any number to the 0 power is 1.(It should report that 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop. Test the function in a program.
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
    if (power == 0)
    {
        if (base == 0)
        {
            printf("0 to the 0 power is undefined, using a value of 1.\n");
            return 1;
        }
        return 1;
    }
    else if (base == 0)
    {
        return 0;
    }
    else
    {
        double result = 1;
        for (int i = 0; i < power; i++)
            result *= base;
        if (power > 0)
        {
            return result;
        }
        else
        {
            return 1 / result;
        }
    }
}
