/**
 * @file 12.6.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or
print the numbers, but do print how many times each number was produced. Have the
program do this for 10 different seed values. Do the numbers appear in equal amounts?
You can use the functions from this chapter or the ANSI C rand() and srand()
functions, which follow the same format that our functions do. This is one way to
examine the randomness of a particular random-number generator.
 * @version 0.1
 * @date 2022-09-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    int records[10] = {0};
    unsigned int seed;
    printf("Please enter a seed value for randomization (q to quit):");
    while (scanf("%u", &seed))
    {
        srand(seed);
        for (int i = 0; i < 1000; i++)
        {
            int rand_number = rand() % 10 + 1;
            records[rand_number - 1]++;
        }
        for (int i = 0; i < 10; ++i)
        {
            printf("number %d occurs %d times.\n", i + 1, records[i]);
            records[i] = 0;
        }
        printf("Please enter a seed value for randomization (q to quit):");
    }
    return 0;
}
