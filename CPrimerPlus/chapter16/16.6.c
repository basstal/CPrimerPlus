/**
 * @file 16.6.c
 * @author your name (you@domain.com)
 * @brief
 * Modify Listing 16.17 so that it uses an array of struct names elements (as defined after
the listing) instead of an array of double . Use fewer elements, and initialize the array
explicitly to a suitable selection of names.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Common.h"

#define NUM 5
#define CNUM 40

struct names
{
    char first[CNUM];
    char last[CNUM];
};

void fillarray(struct names ar[], int n);
void showarray(const struct names ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(void)
{
    struct names vals[NUM] = {{'\0', '\0'}};
    fillarray(vals, NUM);
    puts("Random list: ");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(struct names), mycomp);
    puts("\nSorted list: ");
    showarray(vals, NUM);
    return 0;
}

void fillarray(struct names ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("Please enter the #%d name, seperate last name and first name with space :", index + 1);
        scanf("%s %s", ar[index].last, ar[index].first);
    }
}

void showarray(const struct names ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
        printf("%s·%s\n", ar[index].last, ar[index].first);
}

int mycomp(const void *p1, const void *p2)
{
    const struct names *ps1 = (const struct names *)p1;
    const struct names *ps2 = (const struct names *)p2;
    int res;

    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}