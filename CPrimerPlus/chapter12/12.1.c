/**
 * @file 12.1.c
 * @author your name (you@domain.com)
 * @brief
 * Rewrite the program in Listing 12.4 so that it does not use global variables.
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void critic(int *units);
int main(void)
{
    int units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
void critic(int *units)
{
    printf("No luck,chummy.Try again.\n");
    scanf("%d", units);
}