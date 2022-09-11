/**
 * @file 9.7.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads characters from the standard input to end-of-file. For each character, have the program report whether it is a letter. If it is a letter, also report
its numerical location in the alphabet. For example,  c  and  C  would both be letter 3. Incorporate a function that takes a character as an argument and returns the numerical location if the character is a letter and that returns  –1  otherwise.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void character_to_numerical_location(char);

int main(void)
{
    char c;
    printf("Please input some characters (EOF to quit):");
    while ((c = getchar()) != EOF)
        character_to_numerical_location(c);
    return 0;
}
void character_to_numerical_location(char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        if (c < 95)
            printf("The '%c' numerical location in the alphabet is %d\n", c, c - 'A');
        else
            printf("The '%c' numerical location in the alphabet is %d\n", c, c - 'a');
    else
        printf("It's not a character.\n");
}