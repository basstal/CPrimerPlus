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
#define LIMIT 100

// void print_ASC(char (*parr)[LIMIT], int line);
// void print_long(char (*parr)[LIMIT], int line);
// void print_strl(char (*parr)[LIMIT], int line);
// int strl(char *parr);
// void exchange(char (*parr)[LIMIT], int n1, int n2);
// int hlong(char *parr);
// void copy(char (*target)[LIMIT], char (*source)[LIMIT], int line);

int menu();
void print_original_list(char (*)[LIMIT], int length);
void print_ascii_collating_sequence(char (*)[LIMIT], int length);
void print_order_of_increasing_length(char (*)[LIMIT], int length);

int main()
{
    char source[10][LIMIT];
    int i = 0;
    while (i < 10 && gets(source[i++]))
        ;
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
    while (scanf("%d", &selection) != 1 || selection < 1 || selection > 5)
    {
        gets();
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
        for (char *ch = source[i]; ch != '\0'; ++ch)
        {
            printf("%c(%d)", *ch, *ch);
        }
        printf("\n");
    }
}

void print_order_of_increasing_length(char (*source)[LIMIT], int length)
{

    // for (i = 0; i < line - 1; i++)
    //     for (j = i + 1; j < line; j++)
    //         if (hlong(parr[i]) > hlong(parr[j]))
    //             exchange(parr, i, j);
    // print(parr, line);
}
// void print_strl(char (*parr)[LIMIT], int line)
// {
//     int i, j;

//     for (i = 0; i < line - 1; i++)
//         for (j = i + 1; j < line; j++)
//             if (strl(parr[i]) > strl(parr[j]))
//                 exchange(parr, i, j);
//     print(parr, line);
// }

// int strl(char *parr)
// {
//     int i = 0;
//     while (*parr++ != ' ')
//         i++;

//     return i;
// }
// void exchange(char (*parr)[LIMIT], int n1, int n2)
// {
//     char temp[LIMIT];
//     int i;

//     for (i = 0; i < LIMIT; i++)
//     {
//         temp[i] = parr[n1][i];
//         parr[n1][i] = parr[n2][i];
//         parr[n2][i] = temp[i];
//     }
// }
// int hlong(char *parr)
// {
//     int i = 0;

//     while (*parr++)
//         i++;
//     return i;
// }
// void copy(char (*target)[LIMIT], char (*source)[LIMIT], int line)
// {
//     int i, j;

//     for (i = 0; i < line; i++)
//         for (j = 0; j < LIMIT; j++)
//             target[i][j] = source[i][j];
// }
