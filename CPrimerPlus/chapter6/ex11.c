/**
 * @file ex11.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads eight integers into an array and then prints them in reverse order.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main(void)
{
    int arr[8];

    printf("Please input 8 integers:");
    for (int i = 0; i < 8; ++i)
        if (scanf("%d", &arr[i]) < 0)
            return -1;
    printf("Here are the values you entered in reverse order:\n");
    for (int i = 7; i >= 0; --i)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}