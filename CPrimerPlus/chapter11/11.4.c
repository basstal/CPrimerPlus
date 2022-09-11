/**
 * @file 11.4.c
 * @author your name (you@domain.com)
 * @brief
 * Design and test a function like that described in Programming Exercise 3 except that it
accepts a second parameter specifying the maximum number of characters that can be
read.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#define LIMIT 5

void read_word(char *str, int maximum_characters);

int main(void)
{
    char input[LIMIT];
    printf("Please input some characters for function read_word\nThe read_word will skip over leading whitespace and discards rest of the line, and the maximum number of characters is %d.\n", LIMIT - 1);
    read_word(input, LIMIT - 1);
    printf("read_word result to %s\n", input);
    puts("Done.\n");

    return 0;
}

void read_word(char *str, int maximum_characters)
{
    char ch;
    int status = 0;

    while ((ch = getchar()) != EOF)
    {
        // skip over leading whitespace
        if (status == 0 && isspace(ch))
        {
            continue;
        }
        status = status == 0 ? 1 : status;
        if (isspace(ch))
        {
            // discards rest of the line
            status = 2;
            if (ch == '\n')
            {
                break;
            }
        }
        if (status != 2)
        {
            *str++ = ch;
            if (--maximum_characters == 0)
            {
                status = 2;
            }
        }
    }
    *str = '\0';
}
