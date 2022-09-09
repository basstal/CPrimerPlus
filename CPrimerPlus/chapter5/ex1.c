/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that converts time in minutes to time in hours and minutes. Use
 #define  or  const  to create a symbolic constant for 60. Use a  while  loop to allow the user to enter values repeatedly and terminate the loop if a value for the time of 0 or less is entered.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    const int hour2min = 60;
    int minutes;

    printf("Please input minutes( less than 0 means quit ):");
    while (scanf("%d", &minutes) > 0 && minutes > 0)
    {
        printf("%d minutes equal to %d hours and %d minutes.\n", minutes, minutes / hour2min, minutes % hour2min);
        printf("Please input minutes( less than 0 means quit ):");
    }
    printf("bye!\n");

    return 0;
}
