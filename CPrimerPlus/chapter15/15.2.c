/**
 * @file 15.2.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that reads two binary strings as command-line arguments and prints
the results of applying the ~ operator to each number and the results of applying the
& , | , and ^ operators to the pair. Show the results as binary strings. (If you don’t have a
command-line environment available, have the program read the strings interactively.)
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int transform(char[]);
void print_all(char *, char *);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s binary_str1 binary_str2", argv[0]);
        exit(EXIT_FAILURE);
    }
    print_all(argv[1], argv[2]);

    return 0;
}

int transform(char inStr[])
{
    int i = 0, result = 0;

    while (inStr[i])
    {
        result |= inStr[i] == '0' ? 0 : 1;
        if (inStr[i + 1])
        {
            result <<= 1;
        }
        i++;
    }
    return result;
}

char *to_binary_str(char *str, int num, int length)
{
    int i = 0;
    str[length] = '\0';
    while (length > 0)
    {
        str[length - 1] = (num & 1) == 0 ? '0' : '1';
        num >>= 1;
        --length;
    }
    return str;
}

void print_all(char *num1, char *num2)
{
    char tmp[40];
    printf("~%s result to %s\n", num1, to_binary_str(tmp, ~transform(num1), (int)strlen(num1)));
    printf("~%s result to %s\n", num2, to_binary_str(tmp, ~transform(num2), (int)strlen(num1)));
    int maxlen = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    printf("%s & %s result to %s\n", num1, num2, to_binary_str(tmp, transform(num1) & transform(num2), maxlen));
    printf("%s | %s result to %s\n", num1, num2, to_binary_str(tmp, transform(num1) | transform(num2), maxlen));
    printf("%s ^ %s result to %s\n", num1, num2, to_binary_str(tmp, transform(num1) ^ transform(num2), maxlen));
    printf("bye\n");
}
