/**
 * @file 11.5.c
 * @author your name (you@domain.com)
 * @brief
 * Design and test a function that searches the string specified by the first function
parameter for the first occurrence of a character specified by the second function
parameter. Have the function return a pointer to the character if successful, and a null
if the character is not found in the string. (This duplicates the way that the library
strchr() function works.) Test the function in a complete program that uses a loop to
provide input values for feeding to the function.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define LIMIT 41

char *search_occurrence(char *, char);

int main(void)
{
    char str[LIMIT] = {'\0'};

    printf("Please enter a string:\n");
    while (gets(str) && str[0] != '\0')
    {
        char find_char;
        printf("Enter the char you want to search:");
        scanf("%c", &find_char);
        while (getchar() != '\n')
            ;
        char *occurrence = search_occurrence(str, find_char);
        if (occurrence == NULL)
            printf("Sorry,we didn't found %c in string.\n", find_char);
        else
            printf("See!We found %c in string.\n", *occurrence);
        printf("Please enter another string (empty input to quit):\n");
    }
    printf("bye!");
    return 0;
}

char *search_occurrence(char *source, char find_char)
{
    while (*source != find_char && *source != '\0')
        source++;
    if (*source == '\0')
    {
        return NULL;
    }
    return source;
}
