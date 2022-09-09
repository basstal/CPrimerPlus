/**
 * @file ex15.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads in a line of input and then prints the line in reverse order. You can store the input in an array of  char ; assume that the line is no longer than 255 characters. Recall that you can use  scanf()  with the  %c  specifier to read a character at a time from input and that the newline character ( \n ) is generated when you press the Enter key.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main(void)
{
    char line[255];
    int i = 0;
    printf("Please enter a line of input:");
    do
    {
        if (scanf("%c", &line[i]) < 0)
            return -1;
    } while (line[i] != '\n' && ++i < 255);

    while (i >= 0)
        printf("%c", line[--i]);
    printf("\n");

    return 0;
}