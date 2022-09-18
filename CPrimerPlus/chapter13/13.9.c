/**
 * @file 13.9.c
 * @author your name (you@domain.com)
 * @brief
 * Modify the program in Listing 13.3 so that each word is numbered according to the order
in which it was added to the list, starting with 1. Make sure that, when the program is
run a second time, new word numbering resumes where the previous numbering left off.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
    FILE *fp;
    char words[MAX];
    if ((fp = fopen("wordy", "a+b")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    int number = 0;
    fseek(fp, 0, SEEK_END);
    // find the last line and read the number left off
    long bytes = ftell(fp);
    for (long count = 3L; count <= bytes; ++count)
    {
        fseek(fp, -count, SEEK_END);
        int ch = fgetc(fp);
        if (ch == '\n')
        {
            break;
        }
    }
    fscanf(fp, "%d %s", &number, words);
    fseek(fp, 0, SEEK_END);

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d %s\n", ++number, words);
    puts("File contents:");
    rewind(fp); /* go back to beginning of file */
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}