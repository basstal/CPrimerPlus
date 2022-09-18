/**
 * @file 14.7.c
 * @author your name (you@domain.com)
 * @brief
 * Modify Listing 14.14 so that as each record is read from the file and shown to you, you
are given the chance to delete the record or to modify its contents. If you delete the
record, use the vacated array position for the next record to be read. To allow changing
the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and
you’ll have to pay more attention to positioning the file pointer so that appended records
don’t overwrite existing records. It’s simplest to make all changes in the data stored in
program memory and then write the final set of information to the file. One approach to
keeping track is to add a member to the book structure that indicates whether it is to be
deleted.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */
char *s_gets(char *st, int n);

struct book
{ /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int deleted;
};

int menu();

int main(void)
{
    struct book library[MAXBKS]; /* array of structures */
    int count = 0;
    FILE *pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "r+b")) != NULL)
    {
        rewind(pbooks); /* go to start of file */
        while (count < MAXBKS && fread(&library[count], size,
                                       1, pbooks) == 1)
        {
            if (count == 0)
                puts("Current contents of book.dat:");
            printf("%s by %s: $%.2f\n", library[count].title,
                   library[count].author, library[count].value);
            count++;
        }
        fclose(pbooks);
    }
    printf("\n\n");
    while (menu(&count, library) != 3)
        ;
    printf("\n\n");
    if (count > 0)
    {
        puts("Here is the list of your books:");
        if ((pbooks = fopen("book.dat", "w+b")) == NULL)
        {
            fputs("Can't open book.dat file\n", stderr);
            exit(1);
        }
        for (int index = 0; index < count; ++index)
        {
            if (library[index].deleted != 1)
            {
                printf("%s by %s: $%.2f\n", library[index].title,
                       library[index].author, library[index].value);
                fwrite(&library[index], size, 1,
                       pbooks);
            }
        }
        fclose(pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    return 0;
}

int menu(int *count, struct book library[])
{
    int selection;
    printf("1. delete record by index.\n");
    printf("2. add new book.\n");
    printf("3. quit.\n");
    printf("Please make your selection:\n");
    while (scanf("%d", &selection) != 1)
    {
        fprintf(stderr, "Input should be a number value, please try again.\n");
        while (getchar() != '\n')
            ;
    }
    switch (selection)
    {
    case 1:
        if (*count <= 0)
        {
            puts("There are no book for deletion.");
        }
        else
        {
            printf("Please enter the index of book you want to delete [0, %d] : ", *count - 1);
            int index_to_delete;
            scanf("%d", &index_to_delete);
            while (getchar() != '\n')
                ;
            if (index_to_delete >= 0 && index_to_delete < *count)
            {
                if (library[index_to_delete].deleted == 1)
                {
                    printf("%s by %s: $%.2f have already deleted.\n", library[index_to_delete].title,
                           library[index_to_delete].author, library[index_to_delete].value);
                }
                else
                {
                    printf("The book you want to delete is %s by %s: $%.2f (yes / no) ?", library[index_to_delete].title,
                           library[index_to_delete].author, library[index_to_delete].value);
                    char confirm[20];
                    s_gets(confirm, 20);
                    if (strcmp(confirm, "yes") == 0)
                    {
                        library[index_to_delete].deleted = 1;
                        printf("This book has been deleted.\n");
                    }
                }
            }
            else
            {
                printf("index %d is not valid.\n", index_to_delete);
            }
        }
        break;
    case 2:
        if (*count == MAXBKS)
        {
            fprintf(stderr, "Library is full with %d books", MAXBKS);
            return 3;
        }
        while (getchar() != '\n')
            ;
        puts("Please enter the new book titles.");
        // puts("Press [enter] at the start of a line to stop.");
        if (s_gets(library[*count].title, MAXTITL) != NULL && library[*count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[*count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &library[*count].value);
            library[*count].deleted = 0;
            *count = *count + 1;
            while (getchar() != '\n')
                continue; /* clear input line */
        }
        else
        {
            puts("Add new book failed with illegal title.\n");
        }
        break;
    case 3:
        break;
    }
    return selection;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}