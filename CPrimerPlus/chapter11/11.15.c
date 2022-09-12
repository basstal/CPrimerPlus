/**
 * @file 11.15.c
 * @author your name (you@domain.com)
 * @brief
 * Use the character classification functions to prepare an implementation of atoi() ; have
this version return the value of 0 if the input string is not a pure number.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int myatoi(char *);

int main(void)
{
    char *test = "01234";
    char *test1 = "012ab";
    char *test2 = "  234";
    printf("myatoi(\"01234\") result to %d, atoi(\"01234\") result to %d\n", myatoi(test), atoi(test));
    printf("myatoi(\"012ab\") result to %d, atoi(\"012ab\") result to %d\n", myatoi(test1), atoi(test1));
    printf("myatoi(\"  234\") result to %d, atoi(\"  234\") result to %d\n", myatoi(test2), atoi(test2));

    return 0;
}

int myatoi(char *str)
{
    int result = 0;
    while (isspace(*str))
        ++str;
    while (isdigit(*str))
    {
        result *= 10;
        result += (*str - '0');
        ++str;
    }
    return result;
}