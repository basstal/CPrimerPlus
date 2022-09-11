/**
 * @file 11.10.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that takes a string as an argument and removes the spaces from the
string. Test it in a program that uses a loop to read lines until you enter an empty line.
The program should apply the function to each input string and display the result.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LIMIT 81
void remove_space(char *s);
int main(void)
{
    char orig[LIMIT];

    printf("Please enter a string for testing remove_space function:\n");
    while (gets(orig) && orig[0] != '\0')
    {
        remove_space(orig);
        puts(orig);
        printf("Please enter a string for testing remove_space function (empty to quit):\n");
    }
    puts("Bye!");
    return 0;
}
void remove_space(char *s)
{
    int from = 0;
    while (*(s + from) != '\0')
    {
        if (isspace(*(s + from)))
        {
            for (int i = from; i < strlen(s); ++i)
            {
                *(s + i) = *(s + i + 1);
            }
        }
        else
        {
            ++from;
        }
    }
}