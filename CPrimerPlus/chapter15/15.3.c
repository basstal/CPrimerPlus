/**
 * @file 15.3.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that takes an int argument and returns the number of “on” bits in the
argument. Test the function in a program.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int open_bits(int num);

int main(void)
{
    int num;
    printf("Please input a int number :");
    scanf("%d", &num);
    printf("There are %d open bits.\n", open_bits(num));
    return 0;
}

int open_bits(int num)
{
    int count = 0;
    while (num != 0)
    {
        count += (num & 1) == 1 ? 1 : 0;
        num >>= 1;
    }
    return count;
}
