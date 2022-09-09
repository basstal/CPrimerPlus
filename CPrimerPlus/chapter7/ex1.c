/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input until encountering the  #  character and then reports the number of spaces read, the number of newline characters read, and the number of all other characters read.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
    char c;
    int space, newln, other;
    space = newln = other = 0;
    printf("Please input some characters (# to quit):\n");
    while ((c = getchar()) != '#')
    {
        if (c == ' ')
            ++space;
        else if (c == '\n')
            ++newln;
        else
            ++other;
    }
    printf("space = %d, newline = %d, others = %d\n", space, newln, other);

    return 0;
}
