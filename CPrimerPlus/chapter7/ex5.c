/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   Redo exercise 4 using a  switch .
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
        switch (i % 2)
        {
        case 0:
            ++even;
            evensum += i;
            break;
        case 1:
            ++odd;
            oddsum += i;
            break;
        }
    }
    printf("total number of odd integers = %d , total number of even integers = %d\n", odd, even);
    printf("odd avg = %.2f , even avg = %.2f\n", oddsum / odd, evensum / even);

    return 0;
}