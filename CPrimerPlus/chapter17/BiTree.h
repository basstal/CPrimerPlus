#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORDSIZE 50

#define CLEAN()                   \
    {                             \
        while (getchar() != '\n') \
            ;                     \
    }

typedef enum
{
    FALSE,
    TRUE
} Bool;

typedef struct
{
    char string[WORDSIZE];
    int count;
} Item;

typedef struct node
{
    Item i;
    struct node *left;
    struct node *right;
} BiNode;

typedef struct
{
    BiNode *root;
    int size;
} BiTree;

// BiTree.c
void InitBiTree(BiTree *);
Bool BiTreeEmpty(const BiTree *);
int BiTreeSize(const BiTree *);
Bool AddNode(const Item *, BiTree *);
// Bool InBiTree(const Item *,const BiTree *);
Item *InBiTree(const Item *i, const BiTree *tree);
Bool DeleteNode(const Item *, BiTree *);
void TraverBiTree(const BiTree *, void (*visit)(Item));
void DeleteBiTree(BiTree *);

// readwords.c
void ReadWords(BiTree *tree);
void print(Item i);
void menu(void);
