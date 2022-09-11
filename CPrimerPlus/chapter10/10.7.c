/**
 * @file 10.7.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that initializes a two-dimensional array-of- double and uses one of the
copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
two-dimensional array is an array of arrays, a one-dimensional copy function can be used
with each subarray.)
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define ROWS 3
#define COLS 3
void copy_arr(double[], double[]);
int main(void)
{
    double two_dimensional_source[ROWS][COLS] = {
        {1.0, 5.4, 3.7},
        {3.5, 7.2, 9.5},
        {2.2, 3.7, 1.5}};
    double target[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++)
        copy_arr(target[i], two_dimensional_source[i]);
    return 0;
}
void copy_arr(double target[], double source[])
{
    printf("copy_arr start\n");
    for (int i = 0; i < COLS; i++)
    {
        target[i] = source[i];
        printf("%lf\t", target[i]);
    }
    printf("\n");
}