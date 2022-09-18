/**
 * @file 13.10.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that opens a text file whose name is obtained interactively. Set up a
loop that asks the user to enter a file position. The program then should print the part of
the file starting at that position and proceed to the next newline character. Let negative
or nonnumeric input terminate the user-input loop.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 41
int main(void)
{
    char filename[MAX];
    printf("Please enter the filename : ");
    scanf("%40s", filename);

    FILE *fp;
    if ((fp = fopen(filename, "r+b")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Please give a position of the file content (q to quit) : ");
    int position;
    while (scanf("%d", &position))
    {
        fseek(fp, position, SEEK_SET);
        int ch;
        while ((ch = fgetc(fp)) != EOF)
        {
            putc(ch, stdout);
            if (ch == '\n')
            {
                break;
            }
        }
        printf("Please give a position of the file content (q to quit) : ");
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error when close file.\n");
    }
    return 0;
}
