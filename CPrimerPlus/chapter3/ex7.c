/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *   There are 2.54 centimeters to the inch. Write a program that asks you to enter your height in inches and then displays your height in centimeters. Or, if you prefer, ask for the height in centimeters and convert that to inches.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main()
{
    float hight;

    printf("Please input your height in centimeters:");
    if (scanf("%f", &hight) < 0)
        return -1;
    printf("Your height is %.2f centimeters, and %.2f inches.\n", hight, hight / 2.54);

    return 0;
}