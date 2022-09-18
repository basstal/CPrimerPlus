/**
 * @file 13.5.c
 * @author your name (you@domain.com)
 * @brief
 * Modify the program in Listing 13.5 so that it uses a command-line interface instead of an
interactive interface.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    int files = 0;

    if (argc < 3)
    {
        printf("Usage:%s appendfile sourcefile[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "a+b")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    for (int index = 2; index < argc; index++)
    {
        if (strcmp(argv[index], argv[1]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[index], "rb")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[index]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create output buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[index]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
            fclose(fs);
            files++;
            printf("FIle %s appended.\n", argv[index]);
        }
    }
    printf("Done. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    char ch;
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}
