/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *   Modify the  get_first()  function of  Listing   8.8    so that it returns the first non-whitespace character encountered. Test it in a simple program.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
char get_first(void);
int main(void)
{
    char c;
    printf("Please enter some characters:");
    c = get_first();
    printf("The first non-whitespace character is %c\n", c);
    return 0;
}
char get_first(void)
{
    char ch;
    ch = getchar();
    while (ch < 0 || ch > 255 || isspace(ch))
        ch = getchar();
    return ch;
}
