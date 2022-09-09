/**
 * @file ex18.c
 * @author your name (you@domain.com)
 * @brief
 *   Professor Rabnud joined a social media group. Initially he had five friends. He noticed that his friend count grew in the following fashion. The first week one friend dropped out and the remaining number of friends doubled. The second week two friends dropped out and the remaining number of friends doubled. In general, in the Nth week, N friends dropped out and the remaining number doubled. Write a program that computes and displays the number of friends each week. The program should continue until the count exceeds Dunbar’s number. Dunbar’s number is a rough estimate of the maximum size of a cohesive social group in which each member knows every other member and how they relate to one another. Its approximate value is 150.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main()
{
    int friends_number = 5;
    int week = 1;
    while (friends_number <= 150)
    {
        friends_number = (friends_number - week) * 2;
        printf("On week %d, number of friends is %d.\n", week++, friends_number);
    }
    return 0;
}