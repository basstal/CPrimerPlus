/**
 * @file 9.6.c
 * @author your name (you@domain.com)
 * @brief
 *   Write and test a function that takes the addresses of three  double  variables as arguments and that moves the value of the smallest variable into the first variable, the middle value to the second variable, and the largest value into the third variable.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

void switch_numbers(double *first, double *second, double *third)
{
    double smallest = ((*first < *second) && (*first < *third)) ? *first : (((*second < *third) && (*second < *first)) ? *second : *third);
    double largest = ((*first > *second) && (*first > *third)) ? *first : (((*second > *third) && (*second > *first)) ? *second : *third);
    if (smallest == *first)
    {
        *second = largest == *second ? *third : *second;
    }
    else if (smallest == *second)
    {
        *second = largest == *first ? *third : *first;
    }
    else
    {
        *second = largest == *first ? *second : *first;
    }
    *first = smallest;
    *third = largest;
}

int menu(double *first, double *second, double *third)
{
    printf("Please enter 3 floating-point numbers (q to quit):");
    return scanf("%lf %lf %lf", first, second, third);
}

int main()
{
    double first, second, third;
    while (menu(&first, &second, &third) == 3)
    {
        switch_numbers(&first, &second, &third);
        printf("the smallest variable is %lf, the middle value to the second variable is %lf, the largest value is %lf\n", first, second, third);
    }
    return 0;
}