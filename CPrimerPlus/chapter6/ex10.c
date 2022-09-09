/**
 * @file ex10.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests lower and upper integer limits, calculates the sum of all the integer squares from the square of the lower limit to the square of the upper limit, and displays the answer. The program should then continue to prompt for limits and display answers until the user enters an upper limit that is equal to or less than the lower limit. A sample run should look something like this:
  Enter lower and upper integer limits:  5 9
  The sums of the squares from 25 to 81 is 255
  Enter next set of limits:  3 25
  The sums of the squares from 9 to 625 is 5520
  Enter next set of limits:  5 5
  Done
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

    printf("Enter lower and upper integer limits (enter an upper limit that is equal to or less than the lower limit to quit):");
    while (scanf("%d %d", &lower, &upper) == 2 && lower < upper)
    {
        int sum = 0;
        for (int l = lower; l <= upper; ++l)
            sum += l * l;

        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter next set of limits (enter an upper limit that is equal to or less than the lower limit to quit):");
    }
    printf("Done\n");

    return 0;
}