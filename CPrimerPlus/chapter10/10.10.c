/**
 * @file 10.10.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that sets each element in an array to the sum of the corresponding
elements in two other arrays. That is, if array 1 has the values 2 , 4 , 5 , and 8 and array 2
has the values 1 , 0 , 4 , and 6 , the function assigns array 3 the values 3 , 4 , 9 , and 14 . The
function should take three array names and an array size as arguments. Test the function
in a simple program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void array_add(double *, double *, double *, int);
void show(double *, int);
int main(void)
{
    double operand0[] = {2, 4, 5, 8};
    double operand1[] = {1, 0, 4, 6};
    double result[4];
    array_add(operand0, operand1, result, sizeof(result) / sizeof(double));
    show(result, 4);
    return 0;
}

void show(double *arr, int length)
{
    printf("The result array : {");
    for (int i = 0; i < length; i++)
        printf("%g%c", *(arr + i), i == length - 1 ? ' ' : ',');
    printf("}\n");
    return;
}

void array_add(double *operand0, double *operand1, double *result, int length)
{
    for (int i = 0; i < length; i++, operand0++, operand1++, result++)
        *result = *operand0 + *operand1;
}
