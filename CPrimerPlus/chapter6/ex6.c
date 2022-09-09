/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that prints a table with each line giving an integer, its square, and its cube. Ask the user to input the lower and upper limits for the table. Use a  for  loop.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main(void)
{
    int lower, upper;

    printf("Please input the lower and upper limits for the table:");
    if (scanf("%d %d", &lower, &upper) < 0)
        return -1;

    printf("%s\t%s\t%s\n", "Integer", "Square", "Cube");
    for (; lower <= upper; ++lower)
        printf("%7d\t%6d\t%4d\n", lower, lower * lower, lower * lower * lower);

    return 0;
}
