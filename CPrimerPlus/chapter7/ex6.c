/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input up to  #  and reports the number of times that the sequence  ei  occurs.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main(void)
{
    char former = 0, present;
    int count = 0;
    printf("Please input some characters that contains \"ei\" and ends with #:\n");
    while ((present = getchar()) != '#')
    {
        if ((former == 'e') && (present == 'i'))
            count++;
        former = present;
    }
    printf("ei has appeared %d times\n", count);

    return 0;
}