/**
 * @file 17.3.c
 * @author your name (you@domain.com)
 * @brief
 * Suppose list.h ( Listing 17.3 ) uses the following definition of a list:
#define MAXSIZE 100
typedef struct list
{
Item entries[MAXSIZE];
int items;
} List;
Rewrite the list.c ( Listing 17.5 ) functions to fit this definition and test the resulting
code with the films3.c ( Listing 17.4 ) program.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#define EX17_3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define CloseNode 1

void clear(Item *item);

void InitializeList(List *plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

bool ListIsFull(const List *plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

bool AddItem(Item item, List *plist)
{
    if (ListIsFull(plist))
        return false;
    plist->entries[plist->items] = item;
    plist->items++;
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    int i;

    for (i = 0; i < plist->items; i++)
        pfun(plist->entries[i]);
}

void EmptyTheList(List *plist)
{
    int i;

    for (i = 0; i < plist->items; i++)
        clear(&plist->entries[i]);
    plist->items = 0;
}

void clear(Item *item)
{
    item->rating = -1;
    item->title[0] = '\0';
}

/* films3.c -- using an ADT-style linked list */
/* compile with list.c */
void showmovies(Item item);
char *s_gets(char *st, int n);
int main(void)
{
    List movies;
    Item temp;
    /* initialize */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    /* gather and store */
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    /* display */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    /* clean up */
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}
void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title,
           item.rating);
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