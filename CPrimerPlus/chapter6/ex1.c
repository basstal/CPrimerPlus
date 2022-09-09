/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that creates an array with 26 elements and stores the 26 lowercase letters in it. Also have it show the array contents.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    char lcase[26];

    for (int i = 0; i < 26; i++)
    {
        lcase[i] = 'a' + i;
        printf("%c\t", lcase[i]);
    }
    printf("\n");

    return 0;
}
