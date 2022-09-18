/**
 * @file 14.1.c
 * @author your name (you@domain.com)
 * @brief
 * Redo Review Question 5, but make the argument the spelled-out name of the month
instead of the month number. (Don’t forget about strcmp() .) Test the function in a
simple program.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "MonthDef.h"


int total_days(char *);

int main(void)
{
    char input[20];
    printf("Enter the name of a month: ");
    while (gets(input) != NULL && input[0] != '\0')
    {
        int total = total_days(input);
        if (total >= 0)
            printf("There are %d days from January to %s.\n", total, input);
        else
            printf("%s is not valid input.\n", input);
        printf("Next month (empty line to quit):");
    }
    puts("bye");

    return 0;
}

int total_days(char *month_spell)
{
    if (month_spell[0] == '\0')
        return -1;
    int total_days = 0;
    month_spell[0] = toupper(month_spell[0]);
    for (int i = 1; month_spell[i] != '\0'; i++)
        month_spell[i] = tolower(month_spell[i]);
    for (int i = 0; i < MONTHES; i++)
    {
        total_days += monthTemplates[i].dayOfMonth;
        if (strcmp(month_spell, monthTemplates[i].spell) == 0)
        {
            return total_days;
        }
    }
    return -1;
}
