/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads integers until 0 is entered. After input terminates, the program should report the total number of even integers (excluding the 0) entered, the average value of the even integers, the total number of odd integers entered, and the average value of the odd integers.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    int i;
    int odd, even;
    double oddsum, evensum;

    odd = even = oddsum = evensum = 0;

    printf("Please enter some integers (0 to quit):");
    while (scanf("%d", &i) > 0 && i != 0)
    {
        if (i % 2 == 0)
        {
            ++even;
            evensum += i;
        }
        else
        {
            ++odd;
            oddsum += i;
        }
    }
    printf("total number of odd integers = %d , total number of even integers = %d\n", odd, even);
    printf("odd avg = %.2f , even avg = %.2f\n", oddsum / odd, evensum / even);

    return 0;
}
