/**
 * @file 11.2.c
 * @author your name (you@domain.com)
 * @brief
 * Modify and test the function in exercise 1 so that it stops after n characters or after the
first blank, tab, or newline, whichever comes first. (Don’t just use scanf() .)
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#define LIMIT 10
void readn_noblank(char *, int);

int main(void)
{
    char storage[LIMIT];
    readn_noblank(storage, LIMIT - 1);
    printf("readn_noblank result are \"%s\"\n", storage);
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
        if (i == n || isspace(ch))
        {
            break;
        }
        str[i++] = ch;
    }
    str[i] = '\0';
}