/**
 * @file 13.8.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that takes as command-line arguments a character and zero or more
filenames. If no arguments follow the character, have the program read the standard
input. Otherwise, have it open each file in turn and report how many times the character
appears in each file. The filename and the character itself should be reported along with
the count. Include error-checking to see whether the number of arguments is correct and
whether the files can be opened. If a file can’t be opened, have the program report that
fact and go on to the next file.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

void report_character(FILE *files[10], int character, char *filenames[10])
{
    int index = 0;
    FILE *current = files[index];
    char *filename = filenames[index];
    while (current != NULL)
    {
        int count = 0;
        do
        {
            int ch = fgetc(current);
            fflush(current);
            if (character == ch)
                ++count;
        } while (!feof(current));
        printf("%c occured %d times in %s.\n", character, count, filename);
        if (current != stdin && fclose(current) != 0)
        {
            fprintf(stderr, "Error when close file.\n");
        }
        ++index;
        filename = filenames[index];
        current = files[index];
    }
}

int main(int argc, char *argv[])
{
    FILE *files[10] = {NULL};
    char *filenames[10] = {NULL};

    if (argc < 2)
    {
        printf("Usage:%s character [sourcefile[s]]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc < 3)
    {
        files[0] = stdin;
    }
    else
    {
        for (int i = 2, file_index = 0; i < argc; ++i)
        {
            FILE *fp;
            if ((fp = fopen(argv[i], "rb")) == NULL)
            {
                fprintf(stderr, "Can't open file %s\n", argv[i]);
                continue;
            }
            files[file_index] = fp;
            filenames[file_index] = argv[i];
            ++file_index;
        }
    }
    report_character(files, *argv[1], filenames);
    return 0;
}
