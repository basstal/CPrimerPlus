/**
 * @file 13.1.c
 * @author your name (you@domain.com)
 * @brief
 * Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user’s
response instead of using command-line arguments.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
int main(int argc, char *argv[])
{
    int ch;   // place to store each character as read
    FILE *fp; // "file pointer"
    unsigned long count = 0;
    char filename[255];
    printf("Please enter the filename:");
    if (scanf("%s", filename) != 1)
    {
        printf("entered filename is not valid.");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);
    return 0;
}