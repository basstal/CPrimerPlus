/**
 * @file 11.14.c
 * @author your name (you@domain.com)
 * @brief
 * Write a power-law program that works on a command-line basis. The first command-line
argument should be the type double number to be raised to a certain power, and the
second argument should be the integer power.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, void *argv[])
{

    if (argc != 3)
        printf("Command-line arguments not valid, Usage : %s 11.2 2\n", (char *)argv[0]);
    else
    {
        double num = atof(argv[1]);
        int exp = atoi(argv[2]);
        printf("%g ^ %d = %g\n", num, exp, pow(num, exp));
    }

    return 0;
}
