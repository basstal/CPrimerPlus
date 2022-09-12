/**
 * @file 11.13.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that echoes the command-line arguments in reverse word order. That
is, if the command-line arguments are see you later , the program should print later
you see .
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Echoes the command-line arguments in reverse word order:\n");
    for (int i = argc - 1; i > 0; i--)
        printf("%s ", argv[i]);
    return 0;
}
