#include <stdio.h>
#include <stdlib.h>
#define N2
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
    plist->end = NULL;
    plist->head = NULL;
}

int ListIsEmpty(const List *plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}

int ListIsFull(const List *plist)
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

int AddItem(Item item, List *plist)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("�洢�ռ�����\n");
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
