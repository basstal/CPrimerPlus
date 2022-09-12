/**
 * @file 11.11.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that reads in up to 10 strings or to EOF , whichever comes first. Have it
offer the user a menu with five choices:
print the original list of strings,
print the strings in ASCII collating sequence,
print the strings in order of increasing length,
print the strings in order of the length of the first word in the string,
and quit.
Have the menu recycle until the user enters the quit request. The program, of course, should actually perform the promised tasks.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LIMIT 100

int menu();
void print_original_list(char (*)[LIMIT], int length);
void print_ascii_collating_sequence(char (*)[LIMIT], int length);
void print_order_of_increasing_length(char (*)[LIMIT], int length);
void print_order_of_the_length_of_the_first_word(char (*)[LIMIT], int);
int get_first_word_length(char *source)
{
    char *from = source;
    while (isspace(*from))
        ++from;
    source = from;
    while (isalpha(*source))
        source++;
    return source - from;
}

int main()
{
    char source[10][LIMIT];
    int i = 0;
    printf("Please input 10 strings:\n");
    while (i < 10 && gets(source[i++]))
        printf("Read input string as No.%d\n", i);
    if (i < 10)
    {
        printf("Not enough input!");
        return -1;
    }
    int selection;
    while ((selection = menu()) != 5)
    {
        switch (selection)
        {
        case 1:
            print_original_list(source, 10);
            break;
        case 2:
            print_ascii_collating_sequence(source, 10);
            break;
        case 3:
            print_order_of_increasing_length(source, 10);
            break;
        case 4:
            print_order_of_the_length_of_the_first_word(source, 10);
            break;
        }
    }
    return 0;
}

int menu()
{
    printf("Program function are below:\n");
    printf("1. print the original list of strings\n"
           "2. print the strings in ASCII collating sequence\n"
           "3. print the strings in order of increasing length\n"
           "4. print the strings in order of the length of the first word in the string\n"
           "5. quit.\n");
    int selection;
    while (scanf("%d", &selection) != 1)
    {
        printf("Input is not a number, please input agian\n");
    }
    if (selection < 1 || selection > 5)
    {
        return menu();
    }
    return selection;
}

void print_original_list(char (*source)[LIMIT], int length)
{
    for (int i = 0; i < length; i++)
        puts(source[i]);
}

void print_ascii_collating_sequence(char (*source)[LIMIT], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (char *ch = source[i]; *ch != '\0'; ++ch)
        {
            printf("%c(%d)", *ch, *ch);
        }
        printf("\n");
    }
}

void print_order_of_increasing_length(char (*source)[LIMIT], int length)
{
    if (length > 10)
    {
        printf("print_order_of_increasing_length length should be less than 10\n");
        return;
    }
    char *ordered[10] = {NULL};
    int current_ordered_size = 0;
    for (int i = 0; i < length; ++i)
    {
        ordered[current_ordered_size++] = source[i];
        int length_of_str = strlen(source[i]);
        for (int j = current_ordered_size - 1; j >= 0; --j)
        {
            if (length_of_str < strlen(ordered[j]))
            {
                char *tmp = ordered[j];
                ordered[j] = ordered[j + 1];
                ordered[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < current_ordered_size; ++i)
    {
        printf("%s\n", ordered[i]);
    }
    printf("\n");
}

void print_order_of_the_length_of_the_first_word(char (*source)[LIMIT], int length)
{
    if (length > 10)
    {
        printf("print_order_of_the_length_of_the_first_word length should be less than 10\n");
        return;
    }
    char *ordered[10] = {NULL};
    int current_ordered_size = 0;
    for (int i = 0; i < length; ++i)
    {
        ordered[current_ordered_size++] = source[i];
        int length_of_str = get_first_word_length(source[i]);
        for (int j = current_ordered_size - 1; j >= 0; --j)
        {
            if (length_of_str < get_first_word_length(ordered[j]))
            {
                char *tmp = ordered[j];
                ordered[j] = ordered[j + 1];
                ordered[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < current_ordered_size; ++i)
    {
        printf("%s\n", ordered[i]);
    }
    printf("\n");
}