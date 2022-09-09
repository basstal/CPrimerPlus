/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads a single word into a character array and then prints the word backward. Hint: Use  strlen()  ( Chapter   4   ) to compute the index of the last character in the array.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[40];

    printf("Please input single word:");
    if (scanf("%s", word) < 0)
        return -1;

    for (int i = strlen(word) - 1; i >= 0; --i)
        printf("%c", word[i]);
    printf("\n");

    return 0;
}
