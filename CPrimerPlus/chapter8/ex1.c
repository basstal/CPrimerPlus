/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 * Devise a program that counts the number of characters in its input up to the end of file
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
    int i = 0;
    char c;

    printf("Please input some characters (EOF to quit):\n");
    while ((c = getchar()) != EOF)
    {
        i++;
    }
    printf("There are %d characters.\n", i);

    return 0;
}