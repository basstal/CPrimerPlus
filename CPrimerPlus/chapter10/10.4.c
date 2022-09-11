/**
 * @file 10.4.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that returns the index of the largest value stored in an array-of-double .
Test the function in a simple program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int find_index_of_largest(double *, int);
int main(void)
{
    double source[10] = {
        1.1,
        2.2,
        3.3,
        10.10,
        4.4,
        5.5,
        6.6,
        7.7,
        8.8,
        9.9,
    };
    printf("the index of the largest value in {1.1, 2.2, 3.3, 10.10, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9} is %d\n", find_index_of_largest(source, sizeof(source) / sizeof(double)));
    return 0;
}

int find_index_of_largest(double *source, int length)
{
    int result = 0;
    double max = source[0];
    for (int i = 1; i < length; i++)
    {
        if (source[i] > max)
        {
            max = source[i];
            result = i;
        }
    }

    return result;
}