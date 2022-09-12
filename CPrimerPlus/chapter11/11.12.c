/**
 * @file 11.12.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that reads input up to EOF and reports the number of words, the
number of uppercase letters, the number of lowercase letters, the number of punctuation
characters, and the number of digits. Use the ctype.h family of functions.
 * @version 0.1
 * @date 2022-09-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
    char c;
    int lowercase_letters = 0;
    int uppercase_letters = 0;
    int digits = 0;
    int words = 0;
    int punctuation = 0;
    bool is_in_word = false;
    printf("Please enter text to be analyzed (EOF to terminate):\n");
    while ((c = getchar()) != EOF)
    {
        if (islower(c))
            lowercase_letters++;
        else if (isupper(c))
            uppercase_letters++;
        else if (isdigit(c))
            digits++;
        else if (ispunct(c))
            punctuation++;
        if (!isspace(c) && !is_in_word)
        {
            is_in_word = true;
            words++;
        }
        if (isspace(c) && is_in_word)
            is_in_word = false;
    }
    printf("\nwords = %d, lowercase = %d, uppercase = %d,"
           "digits = %d, punctuation = %d\n",
           words, lowercase_letters, uppercase_letters, digits, punctuation);
    return 0;
}
