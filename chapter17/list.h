#ifndef LIST_H_
#define LIST_H_

#define TSIZE 45
#define MAXSIZE 100
#define N3 1

enum {false,true};

struct film{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

#ifdef N2//17.2
typedef struct node{
	Item item;
	struct node *next;
}Node;

typedef struct{
	Node * head;
	Node * end;
}List;
#endif


#ifdef N3//17.3
typedef struct {
	Item entries[MAXSIZE];
	int items;
}List;
#endif

void InitializeList(List *plist);

int ListIsEmpty(const List *plist);

int ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

int AddItem(Item item,List *plist);

void Traverse(const List *plist,void (*pfun)(Item item));

void EmptyTheList(List *plist);

#endif

