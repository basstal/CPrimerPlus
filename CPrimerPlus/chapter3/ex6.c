/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *   The mass of a single molecule of water is about 3.0×(10^-23)  grams. A quart of water is about 950 grams. Write a program that requests an amount of water, in quarts, and displays the number of water molecules in that amount.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int main()
{
    float quarts;

    printf("Please input an amount of water, in quarts:");
    if (scanf("%f", &quarts) < 0)
        return -1;
    printf("There are %e water molecules approximately in %.2f quarts of water.\n", quarts * 950 / 3.0e-23, quarts);

    return 0;
}