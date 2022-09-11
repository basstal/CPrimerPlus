/**
 * @file 9.2.c
 * @author your name (you@domain.com)
 * @brief
 *   Devise a function  chline(ch,i,j)  that prints the requested character in columns  i through  j . Test it in a simple driver.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
void chline(char, int, int);
void clean();
int main()
{
    char input_char;
    int in_number0, in_number1;

    printf("Please input a char:");
    input_char = getchar();
    clean();
    printf("Please input two int for rols:");
    scanf("%d %d", &in_number0, &in_number1);
    chline(input_char, in_number0, in_number1);
    return 0;
}

void chline(char ch, int i, int j)
{
    for (int space_count = 0; space_count < i; space_count++)
        printf(" ");
    for (; i < j; i++)
        printf("%c", ch);
}

void clean()
{
    while (getchar() != '\n')
        continue;
}