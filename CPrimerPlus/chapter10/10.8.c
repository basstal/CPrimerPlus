/**
 * @file 10.8.c
 * @author your name (you@domain.com)
 * @brief
 * Use a copy function from Programming Exercise 2 to copy the third through fifth
elements of a seven-element array into a three-element array. The function itself need not be altered; just choose the right actual arguments. (The actual arguments need not be
an array name and array size. They only have to be the address of an array element and a
number of elements to be processed.)
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void copy_ptr(double *target, double *source, int length)
{
    printf("copy_ptr start\n");
    for (int i = 0; i < length; i++)
    {
        *(target + i) = *(source + i);
        printf("%lf\t", *(target + i));
    }
    printf("\n");
}

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target[3];
    copy_ptr(target, source + 2, 3);
    return 0;
}