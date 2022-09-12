/**
 * @file 11.16.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that reads input until end-of-file and echoes it to the display. Have the
program recognize and implement the following command-line arguments:
-p Print input as is
-u Map input to all uppercase
-l Map input to all lowercase
Also, if there are no command-line arguments, let the program behave as if the –p
argument had been used.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <ctype.h>
char argument_parse(int, char *[]);

int main(int argc, char *argv[])
{
    char mode, ch;
    if ((mode = argument_parse(argc, argv)) != 'q')
    {
        while ((ch = getchar()) != EOF)
        {
            switch (mode)
            {
            case 'p':
                putchar(ch);
                break;
            case 'u':
                putchar(toupper(ch));
                break;
            case 'l':
                putchar(tolower(ch));
            }
        }
    }
    return 0;
}

char argument_parse(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Usage:%s [-p | -u | -l]\n", argv[0]);
        return 'q';
    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Usage:%s [-p | -u | -l]\n", argv[0]);
            return 'q';
        }
        else
        {
            switch (argv[1][1])
            {
            case 'p':
            case 'u':
            case 'l':
                return argv[1][1];
                break;
            default:
                printf("%s is an invalid flag;", argv[1]);
                printf("using default flag (-p).\n");
                return 'p';
            }
        }
    }
    return 'p';
}
