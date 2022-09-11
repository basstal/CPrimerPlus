/**
 * @file 9.10.c
 * @author your name (you@domain.com)
 * @brief
 *   Generalize the  to_binary()  function of  Listing   9.8    to a  to_base_n()  function that takes a second argument in the range 2–10. It then should print the number that is its first argument to the number base given by the second argument. For example,  to_ base_n(129,8)  would display  201 , the base-8 equivalent of  129 . Test the function in a complete program.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

unsigned long long to_base_n(unsigned long number, unsigned int base);

int main(void)
{
    unsigned long number;
    unsigned int base;
    printf("Enter an integer and base number (q to quit):");
    while (scanf("%lu %u", &number, &base) == 2)
    {
        printf("to_base_n(%lu, %u) result to %llu.\n", number, base, to_base_n(number, base));
        printf("Enter an integer and base number (q to quit):");
    }
    printf("Done.\n");
    return 0;
}

/**
 * @brief
 * to_ base_n(129,8)  would display  201
 * @param number
 * @param base
 * @return unsigned long
 */
unsigned long long to_base_n(unsigned long number, unsigned int base)
{
    if (base < 2 || base > 10)
        return number;
    if (number == 0)
    {
        return 0;
    }
    unsigned long long result = number % base + to_base_n(number / base, base) * 10;
    printf("number %lu, base %d, result %llu\n", number, base, result);
    return result;
}