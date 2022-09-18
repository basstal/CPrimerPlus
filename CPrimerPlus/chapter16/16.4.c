/**
 * @file 16.4.c
 * @author your name (you@domain.com)
 * @brief
 * The ANSI library features a clock() function with this description:
#include <time.h>
clock_t clock (void);
Here, clock_t is a type defined in time.h . The function returns the processor time,
which is given in some implementation-dependent units. (If the processor time is
unavailable or cannot be represented, the function returns a value of -1 .) However,
CLOCKS_PER_SEC , also defined in time.h , is the number of processor time units per
second. Therefore, dividing the difference between two return values of clock() by
CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls.
Typecasting the values to double before division enables you to get fractions of a second.
Write a function that takes a double argument representing a desired time delay and
then runs a loop until that amount of time has passed. Write a simple program that tests
the function.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <time.h>
#include "Common.h"

void wait_time(double time);

int main(void)
{
    double test_time;
    printf("Please input a time value as second to wait (less than 0 to quit): ");
    while (scanf("%lf", &test_time) == 1 && test_time > 0)
    {
        wait_time(test_time);
        printf("Please input a time value as second to wait (less than 0 to quit): ");
    }
    puts("bye!");
    return 0;
}

void wait_time(double time)
{
    clock_t begin = clock();
    int waiting = 1;
    while (waiting)
    {
        double elapse = (double)(clock() - begin) / CLOCKS_PER_SEC;
        waiting = elapse < time;
    }
}
