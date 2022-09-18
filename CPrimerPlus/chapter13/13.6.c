/**
 * @file 13.6.c
 * @author your name (you@domain.com)
 * @brief
 * Programs using command-line arguments rely on the user’s memory of how to use them
correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line
arguments, it prompts the user for the required information.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(void)
{
    FILE *in, *out;
    int ch;
    char name[LEN];

    printf("Please enter the filename to this program: ");
    scanf("%s", &name);
    if ((in = fopen(name, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open the file \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    strcat(name, ".red");
    if ((out = fopen(name, "wb")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    return 0;
}