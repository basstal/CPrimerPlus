/**
 * @file 13.3.c
 * @author your name (you@domain.com)
 * @brief
 * Write a file copy program that prompts the user to enter the name of a text file to act as
the source file and the name of an output file. The program should use the toupper()
function from ctype.h to convert all text to uppercase as it’s written to the output file.
Use standard I/O and the text mode.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
    char source[40], target[40];
    FILE *fp_source, *fp_target;

    printf("Please enter the name of a text file to act as the source file:");
    if (scanf("%s", source) != 1)
    {
        printf("Input is not a valid source file");
        exit(EXIT_FAILURE);
    }
    if ((fp_source = fopen(source, "r")) == NULL)
    {
        printf("Can't find %s file to open", source);
        exit(EXIT_FAILURE);
    }
    printf("Please enter the name of an output file:");
    if (scanf("%s", target) != 1)
    {
        printf("Output is not a valid file name");
        exit(EXIT_FAILURE);
    }
    if ((fp_target = fopen(target, "w")) == NULL)
    {
        printf("Can't open output file %s", target);
        exit(EXIT_FAILURE);
    }
    char c;
    while ((c = getc(fp_source)) != EOF)
    {
        putc(toupper(c), fp_target);
    }
    if (fclose(fp_source) != 0)
    {
        printf("Error when close source file.");
        exit(EXIT_FAILURE);
    }
    if (fclose(fp_target) != 0)
    {
        printf("Error when close target file.");
        exit(EXIT_FAILURE);
    }
    return 0;
}
