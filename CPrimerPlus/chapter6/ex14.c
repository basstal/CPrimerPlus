/**
 * @file ex14.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that creates two eight-element arrays of  doubles and uses a loop to let the user enter values for the eight elements of the first array. Have the program set the elements of the second array to the cumulative totals of the elements of the first array. For example, the fourth element of the second array should equal the sum of the first four elements of the first array, and the fifth element of the second array should equal the sum of the first five elements of the first array. (It’s possible to do this with nested loops,  but by using the fact that the fifth element of the second array equals the fourth element of the second array plus the fifth element of the first array, you can avoid nesting and just use a single loop for this task.) Finally, use loops to display the contents of the two arrays, with the first array displayed on one line and with each element of the second array displayed below the corresponding element of the first array.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main(void)
{
    double arr_a[8];
    double arr_b[8];

    printf("Please input 8 floating-point numbers:");
    for (int i = 0; i < 8; ++i)
        if (scanf("%lf", &arr_a[i]) < 0)
            return -1;
    arr_b[0] = arr_a[0];
    for (int i = 1; i < 8; ++i)
        arr_b[i] = arr_b[i - 1] + arr_a[i];

    for (int i = 0; i < 8; ++i)
        printf("%5.2lf", arr_a[i]);
    printf("\n");
    for (int i = 0; i < 8; ++i)
        printf("%5.2lf", arr_b[i]);
    printf("\n");

    return 0;
}