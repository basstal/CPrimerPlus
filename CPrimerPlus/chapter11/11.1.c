/**
 * @file 11.1.c
 * @author your name (you@domain.com)
 * @brief
 * Design and test a function that fetches the next n characters from input (including
blanks, tabs, and newlines), storing the results in an array whose address is passed as an
argument.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define LIMIT 10
void readn_noblank(char *, int);

int main(void)
{
    char storage[LIMIT];
    readn_noblank(storage, LIMIT - 1);
    printf("Your %d characters from input are \"%s\"\n", LIMIT - 1, storage);
    printf("Done.\n");
    return 0;
}

void readn_noblank(char *str, int n)
{
    printf("The program will fetches the next %d characters from input:\n", n);
    int i = 0;
    char ch;
    while ((ch = getchar()) != EOF)
    {
        str[i++] = ch;
        if (i == n)
        {
            break;
        }
    }
    str[i] = '\0';
}
