/**
 * @file 17.1_recursive.c
 * @author your name (you@domain.com)
 * @brief
 * Modify Listing 17.2 so that it displays the movie list both in the original order and in
reverse order. One approach is to modify the linked-list definition so that the list can be
traversed in both directions. Another approach is to use recursion.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
    struct film *previous;
};

void backprint(struct film *);
int traverse_double_linked(struct film *head, struct film *tail);

int main(void)
{
    struct film *head = NULL;
    struct film *tail = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (gets(input) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
            current->previous = NULL;
        }
        else
        {
            prev->next = current;
            current->previous = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title(empty line to stop):");
        prev = current;
    }
    tail = current;

    if (head == NULL)
    {
        printf("No data entered.");
        return 0;
    }
    else
        printf("Here is the movie list :\n");
    while (traverse_double_linked(head, tail) != 4)
        ;

    // ** free
    current = head;
    while (current != NULL)
    {
        struct film *free_current = current;
        current = current->next;
        free(free_current);
    }
    head = tail = NULL;
    printf("Bye!\n");

    return 0;
}

int traverse_double_linked(struct film *head, struct film *tail)
{
    int choice;
    printf("1) traverse from the head.\n2) traverse from the tail.\n3) recursive traverse from the tail.\n4) quit\n");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4)
    {
        printf("Input is not valid, please try again\n");
        while (getchar() != '\n')
            ;
    }
    while (getchar() != '\n')
        ;
    struct film *current;
    switch (choice)
    {
    case 1:
        current = head;
        while (current != NULL)
        {
            printf("Movie %s is rate %d\n", current->title, current->rating);
            current = current->next;
        }
        break;
    case 2:
        current = tail;
        while (current != NULL)
        {
            printf("Movie %s is rate %d\n", current->title, current->rating);
            current = current->previous;
        }
        break;
    case 3:
        backprint(head);
        break;
    }
    return choice;
}

void backprint(struct film *p)
{
    if (p)
    {
        backprint(p->next);
        printf("Movie %s is rate %d\n", p->title, p->rating);
    }
}
