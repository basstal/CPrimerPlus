/**
 * @file 10.9.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that initializes a two-dimensional 3×5 array-of- double and uses a VLAbased
function to copy it to a second two-dimensional array. Also provide a VLA-based
function to display the contents of the two arrays. The two functions should be capable,
in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
compiler, use the traditional C approach of functions that can process an N×5 array).
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#define COLS 5
void copy(double (*)[COLS], double (*)[COLS], int);
void display(double (*)[COLS], int);
int main(void)
{
    double source[3][COLS] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.10},
        {11.11, 12.12, 13.13, 14.14, 15.15}};
    double target[6][COLS] = {0};
    copy(source, target, 3);
    puts("source:");
    display(source, 3);
    puts("\ntarget:");
    display(target, 6);
    return 0;
}
void copy(double (*source)[COLS], double target[][COLS], int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < COLS; j++)
            target[i][j] = source[i][j];
}
void display(double (*p)[COLS], int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%g\t", p[i][j]);
        printf("\n");
    }
}
