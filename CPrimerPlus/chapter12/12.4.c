/**
 * @file 12.4.c
 * @author your name (you@domain.com)
 * @brief
 * Write and test in a loop a function that returns the number of times it has been called.
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int return_called_times();
int main()
{
    int loop = rand(time(0));
    int called_times = 0;
    for (int i = 0; i < loop; i++)
        called_times = return_called_times();
    printf("called_times result to %d, loop result to %d\n", called_times, loop);
    return 0;
}

int return_called_times()
{
    static int called = 0;
    return ++called;
}
