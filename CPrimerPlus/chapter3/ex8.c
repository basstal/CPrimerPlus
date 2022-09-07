/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *   In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons, and teaspoons. Why does a floating-point type make more sense for this application than an integer type?
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    float cups;

    printf("Please input a volume in cups:");
    if (scanf("%f", &cups) == -1)
    {
        return -1;
    }
    printf("a volume in %f cups is equal to %f in pints, %f in ounces, %f in tablespoons, and %f in teaspoons", cups, cups / 2, cups * 8, cups * 16, cups * 48);
    return 0;
}