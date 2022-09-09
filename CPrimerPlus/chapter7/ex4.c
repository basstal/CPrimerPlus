/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *   Using  if else  statements, write a program that reads input up to  # , replaces each period with an exclamation mark, replaces each exclamation mark initially present with two exclamation marks, and reports at the end the number of substitutions it has made.
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
    int ct1 = 0;
    int ct2 = 0;

    printf("Please input some characters that contains '.' or '!' and ends with #:\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '.':
            putchar('!');
            ++ct1;
            break;
        case '!':
            putchar('!');
            putchar('!');
            ++ct2;
            break;
        default:
            putchar(ch);
        }
    }
    printf("%d replacements of . with !\n", ct1);
    printf("%d replacements of ! with !!\n", ct2);

    return 0;
}