/**
 * @file 11.7.c
 * @author your name (you@domain.com)
 * @brief
 * The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1 , truncating
s2 or padding it with extra null characters as necessary. The target string may not be
null-terminated if the length of s2 is n or more. The function returns s1 . Write your own
version of this function; call it mystrncpy() . Test the function in a complete program
that uses a loop to provide input values for feeding to the function.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LIMIT 255
char *mystrncpy(char *, char *, int);
int main(void)
{
    char target[LIMIT];
    char source[LIMIT];

    printf("Please enter string for copy:\n");
    while (gets(source) && source[0] != '\0')
    {
        printf("enter strncpy n:");
        int num;
        while (scanf("%d", &num) != 1)
        {
            while (getchar() != '\n')
                ;
        };
        while (getchar() != '\n')
            ;
        if (num > LIMIT - 1)
        {
            printf("strncpy should less than %d\n", LIMIT);
            return -1;
        }
        char *result = mystrncpy(target, source, num);
        printf("The return address %p is same with %p\n", result, target);
        puts(target);
        printf("Enter string for copy (empty to quit):\n");
    }
    return 0;
}

char *mystrncpy(char *target, char *source, int n)
{
    int i = 0;
    int limit = n < LIMIT ? n : LIMIT;
    for (; *(source + i) && i < limit; i++)
        *(target + i) = *(source + i);
    while (i < LIMIT)
    {
        *(target + i++) = '\0';
    }
    return target;
}