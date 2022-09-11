/**
 * @file 11.3.c
 * @author your name (you@domain.com)
 * @brief
 * Design and test a function that reads the first word from a line of input into an array and
discards the rest of the line. It should skip over leading whitespace. Define a word as a
sequence of characters with no blanks, tabs, or newlines in it. Use getchar() , not
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#define LIMIT 80

void read_word(char *str);

int main(void)
{
    char input[LIMIT];
    printf("Please input some characters for function read_word, read_word will skip over leading whitespace and discards rest of the line.\n");
    read_word(input);
    printf("read_word result to %s\n", input);
    puts("Done.\n");

    return 0;
}

void read_word(char *str)
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
        }
    }
    *str = '\0';
}