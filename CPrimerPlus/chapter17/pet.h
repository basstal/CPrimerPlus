#define PETNAME 20
#define PETKIND 20

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

typedef struct lnode
{
    char petname[PETNAME];
    char petkind[PETKIND];
    struct lnode *next;
} LNode;

typedef struct
{
    char petname[PETNAME];
    char petkind[PETKIND];
    struct lnode *next;
    int count;
} Item, List;

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
List *InBiTree(Item *i, BiTree *tree);
Bool DeleteNode(Item *, BiTree *);
void TraverBiTree(const BiTree *, void (*visit)(Item));
void DeleteBiTree(BiTree *);

// list.c
void InitList(List *);
Bool ListEmpty(const List *);
int ListSize(const List *);
Bool AddLNode(Item, List *);
Bool SeekLNode(char[], List *);
Bool DeleteLNode(char kind[], List *plist);
void TraverList(const List *, void (*visit)(LNode));
void ClearList(List *plist);
void visit(LNode node);

// petclub.c
char menu(void);
void addpet(BiTree *);
void droppet(BiTree *);
void showpets(const BiTree *);
void findpet(BiTree *);
