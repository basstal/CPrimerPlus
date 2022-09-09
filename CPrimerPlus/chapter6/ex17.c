/**
 * @file ex17.c
 * @author your name (you@domain.com)
 * @brief
 *   Chuckie Lucky won a million dollars (after taxes), which he places in an account that earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a program that finds out how many years it takes for Chuckie to empty his account.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
    double investment = 1000000;
    int i = 0;
    while (investment > 0)
    {
        investment += investment * 0.08;
        investment -= 100000;
        i++;
    }
    printf("After %d years, Chuckie Lucky's account is empty\n", i);
    return 0;
}