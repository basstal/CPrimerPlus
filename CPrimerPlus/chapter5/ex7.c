/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests a type  double  number and prints the value of the number cubed. Use a function of your own design to cube the value and print it. The  main() program should pass the entered value to this function.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void cube(float);
int main(void)
{
    float f;

    printf("Please input a float:");
    if (scanf("%f", &f) < 0)
        return -1;
    cube(f);

    return 0;
}

void cube(float f)
{
    printf("The cube of %.2f is %.2f.\n", f, f * f * f);
}