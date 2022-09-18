/**
 * @file 16.5.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that takes as arguments the name of an array of type int elements, the
size of an array, and a value representing the number of picks. The function then should
select the indicated number of items at random from the array and prints them. No
array element is to be picked more than once. (This simulates picking lottery numbers or
jury members.) Also, if your implementation has time() (discussed in Chapter 12 ) or a
similar function available, use its output with srand() to initialize the rand() randomnumber
generator. Write a simple program that tests the function.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Common.h"
#include <time.h>

#define SIZE 10

void pick(const int[], int, int);

int main(void)
{

    int source[SIZE], picks;

    for (int i = 0; i < SIZE; i++)
        source[i] = i;
    printf("Please input the number of picks [1, %d] :", SIZE);
    while (scanf("%d", &picks) == 1 && picks >= 1 && picks <= SIZE)
    {
        while (getchar() != '\n')
            ;
        pick(source, SIZE, picks);
        printf("Please input the number of picks [1, %d] :", SIZE);
    }
    puts("bye!");
    return 0;
}

void pick(const int source[], int size, int picks)
{
    time_t t;
    srand(time(&t));
    int picked[SIZE], pick = 1;
    for (int i = 0; i < SIZE; ++i)
        picked[i] = -1;
    while (pick <= picks)
    {
        int potential_pick = rand() % size;
        if (picked[potential_pick] != -1)
        {
            continue;
        }
        picked[potential_pick] = potential_pick;
        printf("The %d pick is %d.\n", pick, source[potential_pick]);
        ++pick;
    }
}