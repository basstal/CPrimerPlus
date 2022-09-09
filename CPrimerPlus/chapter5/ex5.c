/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   Change the program  addemup.c  ( Listing   5.13   ), which found the sum of the first 20 integers. (If you prefer, you can think of  addemup.c  as a program that calculates how much money you get in 20 days if you receive $1 the first day, $2 the second day, $3 the third day, and so on.) Modify the program so that you can tell it interactively how far the calculation should proceed. That is, replace the  20  with a variable that is read in.
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
        sum += i;
    printf("sum = %d\n", sum);

    return 0;
}
