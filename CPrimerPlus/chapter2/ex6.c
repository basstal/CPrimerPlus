/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that creates an integer variable called  toes . Have the program set  toes to  10 . Also have the program calculate what twice  toes  is and what  toes  squared is. The program should print all three values, identifying them.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main(void)
{
    int toes = 10;

    printf("toes = %d, toes + toes = %d, toes * toes = %d\n", toes, toes + toes, toes * toes);

    return 0;
}