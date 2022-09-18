/**
 * @file 15.4.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that takes two int arguments: a value and a bit position. Have the
function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
the function in a program.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int open_or_close(int, int);

int main(void)
{
    int num, pos;

    printf("Please input a int number :");
    scanf("%d", &num);
    printf("Please input a test bit position :");
    scanf("%d", &pos);
    printf("The bit position %d of %d is %d", num, pos, open_or_close(num, pos));

    return 0;
}

int open_or_close(int num, int pos)
{
    return (num & (1 << (pos - 1))) != 0;
}