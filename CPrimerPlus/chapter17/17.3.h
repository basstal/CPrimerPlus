#include <stdio.h>
#include <stdlib.h>
#define N3
#include "list.h"

#define CloseNode 1

void clear(Item *item);

void InitializeList(List *plist)
{
	plist->items = 0;
}

int ListIsEmpty(const List *plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

int ListIsFull(const List *plist)
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

int AddItem(Item item, List *plist)
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
