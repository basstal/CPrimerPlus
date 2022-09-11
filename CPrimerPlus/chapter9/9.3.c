/**
 * @file 9.3.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a function that takes three arguments: a character and two integers. The character is to be printed. The first integer specifies the number of times that the character is to be printed on a line, and the second integer specifies the number of lines that are to be printed. Write a program that makes use of this function.
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
void print_func(char, int, int);
int main()
{
    char input_char;
    int print_times, lines;

    printf("Enter a character (# to quit):");
    while ((input_char = getchar()) != '#')
    {
        if (input_char == '\n')
            continue;
        printf("Enter number of columns and number of rows:");
        if ((scanf("%d %d", &print_times, &lines)) != 2)
            break;
        print_func(input_char, print_times, lines);
        printf("Enter next character (# to quit):");
    }
    printf("Bye!\n");
    return 0;
}

void print_func(char ch, int print_times, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < print_times; j++)
            putchar(ch);
        printf("\n");
    }
}
