/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input as a stream of characters until encountering  EOF .
Have it report the number of uppercase letters, the number of lowercase letters, and the number of other characters in the input. You may assume that the numeric values for the lowercase letters are sequential and assume the same for uppercase. Or, more portably, you can use appropriate classification functions from the  ctype.h  library.
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
    int upper, lower;

    upper = lower = 0;
    printf("Please input some characters (EOF to quit):\n");
    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
            upper++;
        else if (c >= 'a' && c <= 'z')
            lower++;
    }
    printf("numbers of uppercase letter are %d, numbers of lowercase letters are %d.\n", upper, lower);
    return 0;
}