/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input until encountering  # . Have the program print each input character and its ASCII decimal code. Print eight character-code pairs per line. Suggestion: Use a character count and the modulus operator ( % ) to print a newline character for every eight cycles of the loop.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char ch;
    int countl = 0;
    printf("Please input characters (enter # to quit):\n");
    while ((ch = getchar()) != '#')
    {
        printf("%c(%d) ", ch, (int)ch);
        ++countl;
        if (countl % 8 == 0)
        {
            countl = 0;
            printf("\n");
        }
    }

    return 0;
}