/**
 * @file 17.7.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that opens and reads a text file and records how many times each word
occurs in the file. Use a binary search tree modified to store both a word and the number
of times it occurs. After the program has read the file, it should offer a menu with three
choices. The first is to list all the words along with the number of occurrences. The
second is to let you enter a word, with the program reporting how many times the word
occurred in the file. The third choice is to quit.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#define EX17_7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
typedef struct
{
    Trnode *parent;
    Trnode *child;
} Pair;

static void DeleteAllNodes(Trnode *root);
static void Delete(Trnode **p);
static void InOrder_1(const Trnode *root, void (*visit)(Item));
static void InOrder_2(const Trnode *root, void (*visit)(Item));
static void InOrder_3(const Trnode *root, void (*visit)(Item));
static Pair SeekNode(const Item *i, const Tree *tree);
static bool ToRight(const Item *i1, const Item *i2);
static bool ToLeft(const Item *i1, const Item *i2);
static void Add(Trnode *new_node, Trnode *root);
static Trnode *MakeNode(const Item *i);

void InitBiTree(Tree *tree)
{
    tree->root = NULL;
    tree->size = 0;
}

bool BiTreeEmpty(const Tree *tree)
{
    return tree->size == 0 ? true : false;
}

int BiTreeSize(const Tree *tree)
{
    return tree->size;
}

bool AddNode(const Item *i, Tree *tree)
{
    Trnode *new_node;

    /*if(SeekItem(i,tree).child!=NULL){
        fprintf(stderr,"Attempted to add duplicate item\n");
        return false;
    }*/
    new_node = MakeNode(i);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    tree->size++;
    if (tree->root == NULL)
        tree->root = new_node;
    else
        Add(new_node, tree->root);
    return true;
}

Item *InBiTree(const Item *i, const Tree *tree)
{
    if (SeekNode(i, tree).child)
        return &SeekNode(i, tree).child->item;
    else
        return NULL;
}

bool DeleteNode(const Item *i, Tree *tree)
{
    Pair look;
    look = SeekNode(i, tree);
    if (look.child == NULL)
        return false;

    if (look.parent == NULL)
        Delete(&tree->root);
    else if (look.parent->left == look.child)
        Delete(&look.parent->left);
    else
        Delete(&look.parent->right);
    tree->size--;
    return true;
}

void TraverBiTree(const Tree *tree, void (*visit)(Item))
{
    if (tree->size != 0)
        InOrder_1(tree->root, visit);
}

void DeleteBiTree(Tree *tree)
{
    if (tree->size != 0)
        DeleteAllNodes(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

/*****************************************
 *        Internal functions
 *****************************************/
static Trnode *MakeNode(const Item *item)
{
    Trnode *new_node;

    new_node = malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *item;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static void Add(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
            root->left = new_node;
        else
            Add(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            Add(new_node, root->right);
    }
    else
        root->item.count++;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    if (strcmp(i1->string, i2->string) < 0)
        return true;
    else
        return false;
}
static bool ToRight(const Item *i1, const Item *i2)
{
    if (strcmp(i1->string, i2->string) > 0)
        return true;
    else
        return false;
}
static Pair SeekNode(const Item *i, const Tree *tree)
{
    Pair look;
    look.parent = NULL;
    look.child = tree->root;

    if (look.child == NULL)
        return look;
    while (look.child != NULL)
    {
        if (ToLeft(i, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(i, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }
    return look;
}

static void Delete(Trnode **p)
{
    Trnode *temp;

    puts((*p)->item.string);
    if ((*p)->left == NULL)
    {
        temp = *p;
        *p = (*p)->right;
        free(temp);
    }
    else if ((*p)->right == NULL)
    {
        temp = *p;
        *p = (*p)->left;
        free(temp);
    }
    else
    {
        for (temp = (*p)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*p)->right;
        temp = *p;
        *p = (*p)->left;
        free(temp);
    }
}

static void InOrder_1(const Trnode *root, void (*visit)(Item))
{
    if (root != NULL)
    {
        visit(root->item);
        InOrder_1(root->left, visit);
        InOrder_1(root->right, visit);
    }
}
static void InOrder_2(const Trnode *root, void (*visit)(Item))
{
    if (root != NULL)
    {
        InOrder_2(root->left, visit);
        visit(root->item);
        InOrder_2(root->right, visit);
    }
}
static void InOrder_3(const Trnode *root, void (*visit)(Item))
{
    if (root != NULL)
    {
        InOrder_3(root->left, visit);
        InOrder_3(root->right, visit);
        visit(root->item);
    }
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

void ReadWords(Tree *tree)
{
    FILE *fp;
    char name[20];
    char word[WORDSIZE];
    Item temp;
    int i = 0, j;
    int ch;

    printf("Please enter the filename to read :");
    scanf("%s", name);
    if ((fp = fopen(name, "r+b")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", name);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
        if (ch < 1 || ch > 255)
        {
            continue;
        }
        if (isalpha(ch))
        {
            word[i++] = ch;
        }
        else if (word[0] != '\0')
        {
            word[i] = '\0';
            for (j = 0; j <= i; j++)
                temp.string[j] = word[j];
            temp.count = 1;
            AddNode(&temp, tree);
            word[0] = '\0';
            i = 0;
        }
    }
    fclose(fp);
}

void print(Item i)
{
    printf("\"%s\" occured %d times.\n", i.string, i.count);
}

void menu(void)
{
    printf("***********************************************\n");
    printf("1) list all the words along with the number of occurrences.\n");
    printf("2) reporting how many times the input word occurred in the file.\n");
    printf("3) quit.\n");
    printf("***********************************************\n");
    printf("Please input a number :");
}

int main(void)
{
    Tree tree;
    Item *temp;
    char word[20];
    int i, s;

    InitBiTree(&tree);
    ReadWords(&tree);
    menu();
    while (1)
    {
        scanf("%d", &s);
        while (getchar() != '\n')
            ;
        switch (s)
        {
        case 1:
            TraverBiTree(&tree, print);
            break;
        case 2:
            printf("Please enter the word to search :");
            scanf("%s", word);
            while (getchar() != '\n')
                ;
            temp = malloc(sizeof(Item));
            for (i = 0; i <= strlen(word); i++)
                temp->string[i] = word[i];
            temp = InBiTree(temp, &tree);
            if (temp)
                print(*temp);
            else
                printf("\"%s\" not found.\n", word);
            break;
        case 3:
            return 0;
        default:
            printf("Input is not valid, please try again.\n");
            continue;
        }
        menu();
    }

    return 0;
}
