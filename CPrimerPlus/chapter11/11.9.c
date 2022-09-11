/**
 * @file 11.9.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that replaces the contents of a string with the string reversed. Test the
function in a complete program that uses a loop to provide input values for feeding to
the function.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#define LIMIT 100
void reverse_self(char *str);

int main(void)
{
    char str[LIMIT];
    printf("Please enter a string for reverse:\n");
    while (gets(str) && str[0] != '\0')
    {
        reverse_self(str);
        puts(str);
        printf("Please enter another string for reverse (empty to quit):\n");
    }
    return 0;
}
void reverse_self(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i)
    {
        char tmp = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = tmp;
    }
}
