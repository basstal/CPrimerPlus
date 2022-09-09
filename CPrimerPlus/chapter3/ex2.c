/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that asks you to enter an ASCII code value, such as 66, and then prints the character having that ASCII code.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main()
{
    int code;

    printf("Please input an ASCII code value [0, 127]:");
    if (scanf("%d", &code) < 0)
        return -1;
    printf("your input in ASCII is %c.\n", code);
    return 0;
}