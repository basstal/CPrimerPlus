/**
 * @file 11.6.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function called is_within() that takes a character and a string pointer as its two
function parameters. Have the function return a nonzero value (true) if the character is
in the string and zero (false) otherwise. Test the function in a complete program that uses
a loop to provide input values for feeding to the function.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define LIMIT 40

int is_within(char ch, const char *str)
{
    while (*str != '\0' && *str != ch)
    {
        str++;
    }
    return *str != '\0';
}

int main()
{
    printf("Please enter a string:\n");
    char str[LIMIT];
    while (gets(str) && str[0] != '\0')
    {
        char character;
        printf("Enter a character to search:");
        scanf("%c", &character);
        while (getchar() != '\n')
            ;
        printf("Function is_within('%c', \"%s\") result to %d\n", character, str, is_within(character, str));
        printf("Please enter a string (empty to quit):\n");
    }
    printf("bye!");
    return 0;
}