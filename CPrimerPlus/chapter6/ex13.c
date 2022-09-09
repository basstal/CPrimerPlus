/**
 * @file ex13.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that creates an eight-element array of  ints and sets the elements to the first eight powers of 2 and then prints the values. Use a  for  loop to set the values, and, for variety, use a  do while  loop to display the values.
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
    arr[0] = 2;
    for (int i = 1; i < 8; ++i)
        arr[i] = arr[i - 1] * 2;
    int i = 0;
    do
    {
        printf("%d\t", arr[i++]);
    } while (i < 8);
    printf("\n");

    return 0;
}