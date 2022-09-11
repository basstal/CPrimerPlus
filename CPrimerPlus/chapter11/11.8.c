/**
 * @file 11.8.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function called string_in() that takes two string pointers as arguments. If
the second string is contained in the first string, have the function return the address
at which the contained string begins. For instance, string_in("hats", "at") would
return the address of the a in hats . Otherwise, have the function return the null pointer.
Test the function in a complete program that uses a loop to provide input values for
feeding to the function.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define LIMIT 255
char *string_in(char *, char *);

int main(void)
{
    char source[LIMIT], substr[LIMIT];
    printf("Please enter source string:\n");
    while (gets(source) && source[0] != '\0')
    {
        printf("Please enter the substr to find:\n");
        gets(substr);
        printf("Let's find out!\n");
        char *result = string_in(source, substr);
        if (result == NULL)
            printf("%s not found in %s\n", substr, source);
        else
            printf("The return address is %p and the remain str is \"%s\"\n", result, result);
        printf("Please enter another source string (empty to quit):\n");
    }
    printf("bye!\n");
    return 0;
}

char *string_in(char *source, char *substr)
{
    int from = 0;

    while (*(source + from) != '\0')
    {
        int j = from, i = 0;
        while (*(substr + i) != '\0' && *(substr + i) == *(source + j))
        {
            ++i;
            ++j;
        }
        if (*(substr + i) == '\0')
        {
            return source + j - i;
        }
        ++from;
    }
    return NULL;
}