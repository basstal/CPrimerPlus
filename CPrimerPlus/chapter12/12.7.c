/**
 * @file 12.7.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that behaves like the modification of Listing 12.13 , which we discussed
after showing the output of Listing 12.13 . That is, have the program produce output like
the following:
Enter the number of sets; enter q to stop : 18
How many sides and how many dice? 6 3
Here are 18 sets of 3 6-sided throws.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
13 8 14
How many sets? Enter q to stop: q
 * @version 0.1
 * @date 2022-09-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_dice(int);

int main(void)
{
    int dice, count, total;
    int sides;
    int set, sets;

    srand((unsigned int)time(0));

    printf("Enter the number of sets;enter q to stop :");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++)
        {
            for (total = 0, count = 0; count < dice; count++)
                total += roll_dice(sides);
            printf("%4d ", total);
            if (set % 15 == 14)
                putchar('\n');
        }
        if (set % 15 != 0)
            putchar('\n');
        printf("How many sets?Enter q to stop : ");
    }
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}

int roll_dice(int sides)
{
    return rand() % sides + 1;
}