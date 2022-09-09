/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that asks the user to enter the number of days and then converts that value to weeks and days. For example, it would convert 18 days to 2 weeks, 4 days. Display results in the following format:
  18 days are 2 weeks, 4 days.
 Use a  while  loop to allow the user to repeatedly enter day values; terminate the loop when the user enters a nonpositive value, such as  0  or  -20 .
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    int days;

    printf("Please enter the number of days (nonpositive value to quit):");
    while (scanf("%d", &days) > 0 && days > 0)
    {
        printf("%d days are %d weeks, %d days.\n", days, days / 7, days % 7);
        printf("Please input days (nonpositive value to quit):");
    }

    return 0;
}