/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input as a stream of characters until encountering  EOF . Have the program print each input character and its ASCII decimal value. Note that characters preceding the space character in the ASCII sequence are nonprinting characters.
Treat them specially. If the nonprinting character is a newline or tab, print  \n  or  \t , respectively. Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A, which can be displayed as  ^A . Note that the ASCII value for  A  is the value for Ctrl+A plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per line, except  start a fresh line each time a newline character is encountered. (Note: The operating system may have special interpretations for some control characters and keep them from reaching the program.)
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
    char ch;
    int i = 0;
    printf("Please input some characters (EOF to quit):\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch < ' ')
        {
            if (ch == '\n')
            {
                printf("%3s(%3d)", "\\n", (int)ch);
                i = 9;
            }
            else if (ch == '\t')
            {
                printf("%3s(%3d)", "\\t", (int)ch);
            }
            else
            {
                printf(" ^%c(%3d)", ch + 'A', (int)ch);
            }
        }
        else
        {
            printf("  %c(%3d)", ch, (int)ch);
        }
        if (++i % 10 == 0)
        {
            i = 0;
            printf("\n");
        }
    }
    return 0;
}