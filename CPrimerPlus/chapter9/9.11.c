/**
 * @file 9.11.c
 * @author your name (you@domain.com)
 * @brief
 *   Write and test a  Fibonacci()  function that uses a loop instead of recursion to calculate Fibonacci numbers.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int fibonacci(int n);

int main(void)
{
    int n;
    printf("Please input Fibonacci limit n:");
    while ((scanf("%d", &n)) == 1)
    {
        printf("fibonacci(n) result to %d\n", fibonacci(n));
        printf("Please input Fibonacci limit n (q to quit):");
    }
    printf("bye!\n");
    return 0;
}

int fibonacci(int n)
{
    int first = 0, second = 1;
    switch (n)
    {
    case 1:
        return first;
    case 2:
        return second;
    default:
        if (n > 2)
        {
            int iter_count = n - 2;
            int next;
            while (iter_count-- > 0)
            {
                next = first + second;
                first = second;
                second = next;
            }
            return next;
        }
        else
        {
            printf("wrong fibonacci sequence index %d\n", n);
            return -1;
        }
    }
}
