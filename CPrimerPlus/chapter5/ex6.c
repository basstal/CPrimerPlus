/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *  Now modify the program of Programming Exercise 5 so that it computes the sum of the squares of the integers. (If you prefer, how much money you receive if you get $1 the first day, $4 the second day, $9 the third day, and so on. This looks like a much better deal!) C doesn’t have a squaring function, but you can use the fact that the square of  n  is  n * n .
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    int upper;
    int sum = 0;

    printf("Please input upper of the sum value:");
    if (scanf("%d", &upper) < 0)
        return -1;
    for (int i = 1; i <= upper; ++i)
        sum += i * i;
    printf("sum = %d\n", sum);

    return 0;
}
