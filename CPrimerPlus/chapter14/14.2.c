/**
 * @file 14.2.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that prompts the user to enter the day, month, and year. The month
can be a month number, a month name, or a month abbreviation. The program then
should return the total number of days in the year up through the given day. (Do take
leap years into account.)
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MonthDef.h"

int main(void)
{
    int day, year;
    char month[40];

    printf("Please enter the day :");
    scanf("%d", &day);
    while (getchar() != '\n')
        ;
    printf("Please enter the month (number or month name or month abbreviation) : ");
    gets(month);
    printf("Please enter the year :");
    scanf("%d", &year);

    int target_month = 0;

    while (strcmp(monthTemplates[target_month].spell, month) != 0 &&
           strcmp(monthTemplates[target_month].abbreviation, month) != 0 &&
           monthTemplates[target_month].digit != atoi(month) &&
           target_month++ < 12)
        ;
    if (target_month >= 12)
    {
        printf("The month of %s not found.", month);
        exit(EXIT_FAILURE);
    }
    int result = year % 4 == 0 && target_month > 1 ? day + 1 : day;
    for (int j = 0; j < target_month; j++)
        result += monthTemplates[j].dayOfMonth;
    printf("There have been %d from %d-01-01 to %d-%s-%d.\n", result, year, year, month, day);
    return 0;
}
