/**
 * @file 10.11.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that declares a 3×5 array of int and initializes it to some values of
your choice. Have the program print the values, double all the values, and then display
the new values. Write a function to do the displaying and a second function to do the
doubling. Have the functions take the array name and the number of rows as arguments.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define COLS 5
void show(double (*)[COLS], int);
void doubling(double (*)[COLS], int);
int main(void)
{
    double source[3][COLS] = {
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.2, 2.3, 2.4, 2.5, 2.6},
        {3.3, 3.4, 3.5, 3.6, 3.7}};
    doubling(source, 3);
    show(source, 3);
    return 0;
}
void show(double (*source)[COLS], int length)
{
    int i, j;

    printf("The doubling result are :\n{\n");
    for (i = 0; i < length; i++)
    {
        printf("{");
        for (j = 0; j < COLS; j++)
        {
            printf("%3g%c ", source[i][j], j == COLS - 1 ? ' ' : ',');
        }
        printf("}\n");
    }
    printf("}\n");
    return;
}
void doubling(double (*source)[COLS], int length)
{
    int i, j;

    for (i = 0; i < length; i++)
        for (j = 0; j < COLS; j++)
            source[i][j] *= 2;
    return;
}
