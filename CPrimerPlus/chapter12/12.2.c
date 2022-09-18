/**
 * @file 12.2.c
 * @author your name (you@domain.com)
 * @brief
 * Gasoline consumption commonly is computed in miles per gallon in the U.S. and in
liters per 100 kilometers in Europe. What follows is part of a program that asks the user
to choose a mode (metric or U.S.) and then gathers data and computes fuel consumption:
// pe12-2b.c
// compile with pe12-2a.c
#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}

Here is some sample output:
Enter 0 for metric mode, 1 for US mode: 0
Enter distance traveled in kilometers: 600
Enter fuel consumed in liters: 78.8
Fuel consumption is 13.13 liters per 100 km.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
Enter distance traveled in miles: 434
Enter fuel consumed in gallons: 12.7
Fuel consumption is 34.2 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 3
Invalid mode specified. Mode 1(US) used.
Enter distance traveled in miles: 388
Enter fuel consumed in gallons: 15.3
Fuel consumption is 25.4 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): -1
Done.

If the user enters an incorrect mode, the program comments on that and uses the most
recent mode. Supply a pe12-2a.h header file and a pe12-2a.c source code file to make
this work. The source code file should define three file-scope, internal-linkage variables.
One represents the mode, one represents the distance, and one represents the fuel
consumed. The get_info() function prompts for data according to the mode setting
and stores the responses in the file-scope variables. The show_info() function calculates
and displays the fuel consumption based on the mode setting. You can assume the user
responds with numeric input.
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include "12.2.h"

static int mode;
static int distance;
static double fuel_consumed;

void set_mode(int in_mode)
{
    mode = in_mode;
}
void get_info()
{
    static int recent_mode = 0;
    if (mode == 0)
    {
        recent_mode = 0;
        printf("Enter distance traveled in kilometers:");
        scanf("%d", &distance);
        printf("Enter fuel consumerd in liters:");
        scanf("%lf", &fuel_consumed);
    }
    else if (mode == 1)
    {
        recent_mode = 1;
        printf("Enter distance traveled in miles:");
        scanf("%d", &distance);
        printf("Enter fuel consumerd in gallons:");
        scanf("%lf", &fuel_consumed);
    }
    else
    {
        printf("Invalid mode specified. Mode %d (%s) used.\n", recent_mode, recent_mode == 1 ? "US" : "metric");
        mode = recent_mode;
        get_info();
    }
}
void show_info(void)
{
    if (mode == 0)
        printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel_consumed / (distance / 100));
    else
        printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel_consumed);
}

int main()
{
    int mode = 0;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}