/**
 * @file 15.1.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that converts a binary string to a numeric value. That is, if you have
char * pbin = "01001001";
you can pass pbin as an argument to the function and have the function return an int
value of 73 .
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int transform(char[]);

int main(void)
{
    char str[40];
    printf("Please input a binary string to transform to a numeric value (e.g. 01001001 to 73):");
    gets(str);
    printf("transform(\"%s\") result to %d.\n", str, transform(str));

    return 0;
}

int transform(char inStr[])
{
    int i = 0, result = 0;

    while (inStr[i])
    {
        result |= inStr[i] == '0' ? 0 : 1;
        if (inStr[i + 1])
        {
            result <<= 1;
        }
        i++;
    }

    return result;
}