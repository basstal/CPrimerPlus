/**
 * @file 13.11.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that takes two command-line arguments. The first is a string; the
second is the name of a file. The program should then search the file, printing all lines
containing the string. Because this task is line oriented rather than character oriented,
use fgets() instead of getc() . Use the standard C library function strstr() (briefly
described in exercise 7 of Chapter 11 ) to search each line for the string. Assume no lines
are longer than 255 characters.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFERSIZE 256
int main(int argc, char *argv[])
{
    FILE *fp;
    char line[BUFFERSIZE];
    if (argc < 3)
    {
        printf("Usage: %s search_string filename", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUFFERSIZE, fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
            printf("%s", line);
    }

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error when close file.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
