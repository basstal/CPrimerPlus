/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   There are approximately 3.156 × (10^7)  seconds in a year. Write a program that requests your age in years and then displays the equivalent number of seconds.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    int age;

    printf("Please input your age in years:");
    if (scanf("%d", &age) < 0)
        return -1;
    printf("Your age equal to %.0lf seconds\n", age * 3.156e7);

    return 0;
}
