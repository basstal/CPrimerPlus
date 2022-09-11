/**
 * @file 10.5.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that returns the difference between the largest and smallest elements of
an array-of- double . Test the function in a simple program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
double find_largest_to_smallest_diff(double *, int);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    printf("difference between the largest and smallest elements of {1.1, 2.2, 3.3, 4.4, 5.5} is %lf\n", find_largest_to_smallest_diff(source, sizeof(source) / sizeof(double)));
    return 0;
}

double find_largest_to_smallest_diff(double *source, int length)
{
    double max, min;
    max = min = *source;
    for (int i = 0; i < length; source++, i++)
    {
        if (*source > max)
            max = *source;
        else if (*source < min)
            min = *source;
    }
    return max - min;
}