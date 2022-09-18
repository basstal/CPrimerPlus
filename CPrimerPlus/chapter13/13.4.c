/**
 * @file 13.4.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that sequentially displays onscreen all the files listed in the command
line. Use argc to control a loop.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage:%s filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int index = 1; index < argc; index++)
    {
        FILE *source;
        if ((source = fopen(argv[index], "r")) == NULL)
        {
            printf("Can't open file %s for input\n", argv[index]);
            continue;
        }
        char byte;
        while ((byte = getc(source)) != EOF)
            putchar(byte);
        if (fclose(source) != 0)
        {
            printf("Can't close file %s\n", argv[index]);
        }
    }
    return 0;
}