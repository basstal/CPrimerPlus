/**
 * @file 9.1.c
 * @author your name (you@domain.com)
 * @brief
 *   Devise a function called  min(x,y)  that returns the smaller of two  double  values. Test the function with a simple driver.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
double min(double, double);
int main()
{
    double x, y;
    printf("Please input two double number:");
    while ((scanf("%lf %lf", &x, &y)) == 2)
    {
        printf("%.2lf is smaller.\n", min(x, y));
        printf("Next two values(q to quit):");
    }
    printf("bye!\n");

    return 0;
}
double min(double x, double y)
{
    return x < y ? x : y;
}