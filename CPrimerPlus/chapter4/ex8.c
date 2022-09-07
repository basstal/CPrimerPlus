/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that asks the user to enter the number of miles traveled and the number of gallons of gasoline consumed. It should then calculate and display the miles-per-gallon value, showing one place to the right of the decimal. Next, using the fact that one gallon is about 3.785 liters and one mile is about 1.609 kilometers, it should convert the mile-per-gallon value to a liters-per-100-km value, the usual European way of expressing fuel consumption, and display the result, showing one place to the right of the decimal. Note that the U.S. scheme measures the distance traveled per  amount of fuel (higher is better), whereas the European scheme measures the amount of fuel per distance (lower is better). Use symbolic constants (using  const  or  #define ) for the two conversion factors.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    const float gl2lt = 3.785f, ml2km = 1.609f;
    float miles, gallons;

    printf("Please input miles:");
    if (scanf("%f", &miles) < 0)
        return -1;
    printf("Please input gallons:");
    if (scanf("%f", &gallons) < 0)
        return -1;
    printf("1 gallon drive %.1f miles\n", miles / gallons);
    printf("100 kilometers use %.1f litres\n", gallons * gl2lt / miles * ml2km * 100);

    return 0;
}