/**
 * @file 17.6.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that takes three arguments: the name of an array of sorted integers, the
number of elements of the array, and an integer to seek. The function returns the value
1 if the integer is in the array, and 0 if it isn’t. Have the function use the binary search
technique.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20

int compare(const void *p1, const void *p2);
bool binary_search(int num[], int count, int n);

int main(void)
{
    int num[SIZE];
    int n;
    int size;
    int i;

    printf("Please enter the maximum of the rand number :");
    scanf("%d", &size);
    for (i = 0; i < SIZE; i++)
        num[i] = rand() % size;
    qsort(num, SIZE, sizeof(int), compare);
    printf("Sorted array contents :\n[");
    for (i = 0; i < SIZE; i++)
        printf("%d%c", num[i], i == SIZE - 1 ? ' ' : ',');
    printf("]\n");
    printf("Please enter the number you want to search (q to quit):");
    while (scanf("%d", &n) == 1)
    {
        if (binary_search(num, SIZE, n))
            printf("The number %d is in the array.\n", n);
        else
            printf("The number %d isn't in the array!\n", n);
        while (getchar() != '\n')
            ;
        printf("Please enter the number you want to search (q to quit):");
    }
    return 0;
}

int compare(const void *p1, const void *p2)
{
    int *a, *b;

    a = (int *)p1;
    b = (int *)p2;

    if (*a < *b)
        return -1;
    else if (*a == *b)
        return 0;
    else
        return 1;
}

bool binary_search(int num[], int count, int n)
{
    int temp = compare(&num[count / 2], &n);

    if (temp == 0)
        return true;
    else if (temp < 0)
        return binary_search(&num[count / 2 + 1], count / 2 - 1, n);
    else
    {
        if (count == 0)
            return false;
        return binary_search(num, count / 2, n);
    }
}
