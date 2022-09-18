/**
 * @file 13.7.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that opens two files. You can obtain the filenames either by using
command-line arguments or by soliciting the user to enter them.
a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
first file, line 2 of the second file, and so on, until the last line of the longer file (in
terms of lines) is printed.
b. Modify the program so that lines with the same line number are printed on the
same line.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 4096
void print_each_lines(FILE *file1, FILE *file2)
{
    printf("print_each_lines:\n");
    char file1_cache[BUFFERSIZE], file2_cache[BUFFERSIZE];
    char *file1_content = fgets(file1_cache, BUFFERSIZE - 1, file1);
    char *file2_content = fgets(file2_cache, BUFFERSIZE - 1, file2);
    while (file1_content != NULL || file2_content != NULL)
    {
        if (file1_content)
        {
            fputs(file1_cache, stdout);
            file1_content = fgets(file1_cache, BUFFERSIZE - 1, file1);
        }
        if (file2_content)
        {
            fputs(file2_cache, stdout);
            file2_content = fgets(file2_cache, BUFFERSIZE - 1, file2);
        }
    }
}

void print_merge_lines(FILE *file1, FILE *file2)
{
    printf("print_merge_lines:\n");
    char file1_cache[BUFFERSIZE], file2_cache[BUFFERSIZE];
    char *file1_content = fgets(file1_cache, BUFFERSIZE - 1, file1);
    char *file2_content = fgets(file2_cache, BUFFERSIZE - 1, file2);
    while (file1_content || file2_content)
    {
        if (file1_content)
        {
            char *find = strchr(file1_cache, '\n');
            if (find)
            {
                *find = '\0';
                // windows line-ending
                if (*(find - 1) == '\r')
                {
                    *(find - 1) = '\0';
                }
            }
            fputs(file1_cache, stdout);
            file1_content = fgets(file1_cache, BUFFERSIZE - 1, file1);
        }
        if (file2_content)
        {
            fputs(file2_cache, stdout);
            file2_content = fgets(file2_cache, BUFFERSIZE - 1, file2);
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *file1;
    FILE *file2;

    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((file1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("Could not open file %s for input\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("Could not open file %s for input\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    print_each_lines(file1, file2);
    rewind(file1);
    rewind(file2);
    print_merge_lines(file1, file2);
    if (fclose(file1) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(file2) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
