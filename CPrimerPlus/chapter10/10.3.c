/**
 * @file 10.3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a function that returns the largest value stored in an array-of-int . Test the function in a simple program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int find_largest(int *, int);
int main(void)
{
    int source[5] = {5, 6, -2, 3, 11};
    printf("The largest number of source {5, 6, -2, 3, 11} is %d\n", find_largest(source, sizeof(source) / sizeof(int)));
    return 0;
}

int find_largest(int *source, int length)
{
    if (length < 1)
    {
        printf("Error with source array-of-int length is less than 1\n");
        return -1;
    }
    int max = source[length - 1];
    for (int i = 0; i < length - 1; i++)
        if (max < source[i])
            max = source[i];
    return max;
}
