/**
 * @file 12.3.c
 * @author your name (you@domain.com)
 * @brief
 * Redesign the program described in Programming Exercise 2 so that it uses only automatic
variables. Have the program offer the same user interface that is, it should prompt the user to enter a mode, and so on. You’ll have to come up with a different set of function
calls, however.
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void get_info(int mode);
void show_info(int mode, int distance, double fuel_consumed);

int main(void)
{
    int mode;

    printf("Enter 0 for metric mode,1 for US mode:");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        get_info(mode);
        printf("Enter 0 for metric mode,1 for US mode");
        printf("(-1 to quit):");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
void get_info(int mode)
{
    int distance;
    double fuel_consumed;
    static recent_mode = 0;
    if (mode == 0)
    {
        recent_mode = 0;
        printf("Enter distance traveled in kilometers:");
        scanf("%d", &distance);
        printf("Enter fuel consumerd in liters:");
        scanf("%lf", &fuel_consumed);
        show_info(mode, distance, fuel_consumed);
    }
    else if (mode == 1)
    {
        recent_mode = 1;
        printf("Enter distance traveled in miles:");
        scanf("%d", &distance);
        printf("Enter fuel consumerd in gallons:");
        scanf("%lf", &fuel_consumed);
        show_info(mode, distance, fuel_consumed);
    }
    else
    {
        printf("Invalid mode specified. Mode %d (%s) used.\n", recent_mode, recent_mode == 1 ? "US" : "metric");
        get_info(recent_mode);
    }
}
void show_info(int mode, int distance, double fuel_consumed)
{
    if (mode == 0)
        printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel_consumed / (distance / 100));
    else
        printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel_consumed);
}