/**
 * @file 12.5.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that generates a list of 100 random numbers in the range 1–10
in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11 ,
“Character Strings and String Functions,” to type int . In this case, just sort the numbers
themselves.)
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

int qsort_core(int numbers[], int lower, int higher)
{
    int x = numbers[higher];
    int i = lower - 1;
    for (int j = lower; j <= higher - 1; ++j)
    {
        if (numbers[j] <= x)
        {
            int temp = numbers[++i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }
    int temp = numbers[i + 1];
    numbers[i + 1] = numbers[higher];
    numbers[higher] = temp;
    return i + 1;
}
void myqsort(int numbers[], int from, int to)
{
    if (from < to)
    {
        int interval_index = qsort_core(numbers, from, to);
        myqsort(numbers, from, interval_index - 1);
        myqsort(numbers, interval_index + 1, to);
    }
}
int main()
{
    int rand_numbers[100];

    for (int i = 0; i < 100; i++)
        rand_numbers[i] = rand() % 10 + 1;
    myqsort(rand_numbers, 0, 99);
    for (int i = 0; i < 100; i++)
    {
        if (i % 9 == 0)
            printf("\n");
        printf("%d ", rand_numbers[i]);
    }
    return 0;
}
