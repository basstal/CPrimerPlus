/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that requests your first name and does the following with it:
a.	   Prints it enclosed in double quotation marks
b.	   Prints it in a field 20 characters wide, with the whole field in quotes and the name at the right end of the field
c.	   Prints it at the left end of a field 20 characters wide, with the whole field enclosed in quotes
d.	   Prints it in a field three characters wider than the name
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char name[40];

    printf("Please input your name (less than 40 letters):");
    if (scanf("%s", name) < 0)
        return -1;
    printf("\"%s\"\n", name);    // Prints it enclosed in double quotation marks
    printf("\"%20s\"\n", name);  // Prints it in a field 20 characters wide, with the whole field in quotes and the name at the right end of the field
    printf("\"%-20s\"\n", name); // Prints it at the left end of a field 20 characters wide, with the whole field enclosed in quotes
    int len = strlen(name) + 3;
    printf("%*s\n", len, name); // Prints it in a field three characters wider than the name

    return 0;
}
