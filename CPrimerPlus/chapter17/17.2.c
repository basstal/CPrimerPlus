/**
 * @file 17.2.c
 * @author your name (you@domain.com)
 * @brief
 * Suppose list.h ( Listing 17.3 ) uses the following definition of a list:
typedef struct list
{
Node * head;
Node * end;
} List;
Rewrite the list.c ( Listing 17.5 ) functions to fit this definition and test the resulting
code with the films3.c ( Listing 17.4 ) program.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#define EX17_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
    plist->end = NULL;
    plist->head = NULL;
}

bool ListIsEmpty(const List *plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List *plist)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
        return true;
    else
        return false;
}

unsigned int ListItemCount(const List *plist)
{
    Node *temp = plist->head;
    int count = 1;

    if (temp == NULL)
        return 0;
    while (temp != plist->end)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

bool AddItem(Item item, List *plist)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        return false;
    }
    CopyToNode(item, newnode);
    if (ListIsEmpty(plist))
        plist->head = plist->end = newnode;
    else
    {
        plist->end->next = newnode;
        plist->end = newnode;
    }
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *temp = plist->head;
    while (temp != NULL)
    {
        pfun(temp->item);
        temp = temp->next;
    }
}

void EmptyTheList(List *plist)
{
    Node *temp = plist->head;
    while (plist->head != NULL)
    {
        plist->head = plist->head->next;
        free(temp);
        temp = plist->head;
    }
    plist->end = NULL;
}

static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
    pnode->next = NULL;
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