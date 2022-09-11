/**
 * @file 10.6.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that reverses the contents of an array of double and test it in a simple program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

void reverse(double *source, int length)
{
    for (int i = 0, j = length - 1; j - i > 0; ++i, --j)
    {
        double tmp = source[i];
        source[i] = source[j];
        source[j] = tmp;
    }
}
int main()
{
    double test[5] = {3.14, 5.68, 9.72, 2.45, 0.26};
    int length = sizeof(test) / sizeof(double);
    printf("before reverse");
    for (int i = 0; i < length; ++i)
    {
        printf("%c%lf%c%c", i == 0 ? '{' : ' ', test[i], i == (length - 1) ? ' ' : ',', i == (length - 1) ? '}' : ' ');
    }
    printf("\n");
    reverse(test, length);
    printf("after reverse");
    for (int i = 0; i < length; ++i)
    {
        printf("%c%lf%c%c", i == 0 ? '{' : ' ', test[i], i == (length - 1) ? ' ' : ',', i == (length - 1) ? '}' : ' ');
    }
    printf("\n");

    return 0;
}