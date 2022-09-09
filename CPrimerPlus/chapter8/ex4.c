/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that reads input as a stream of characters until encountering  EOF . Have it report the average number of letters per word. Don’t count whitespace as being letters in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that now. (If you do want to worry about it, consider using the  ispunct()  function from the  ctype.h  family.)
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char current_char;
    int words, letters_in_this_word;
    float avg_number_of_letters;

    words = avg_number_of_letters = letters_in_this_word = 0;
    printf("Please input some characters (EOF to quit):\n");
    while ((current_char = getchar()) != EOF)
    {
        if (current_char < 0 || current_char > 255 || ispunct(current_char) || isdigit(current_char))
        {
            continue;
        }
        if (current_char == ' ' || current_char == '\n')
        {
            if (letters_in_this_word > 0)
            {
                avg_number_of_letters = avg_number_of_letters == 0 ? letters_in_this_word : (avg_number_of_letters + letters_in_this_word) / 2;
                letters_in_this_word = 0;
                ++words;
            }
        }
        else
        {
            letters_in_this_word++;
        }
    }
    printf("There are %d words, average number of letters per word is %.2f.\n", words, avg_number_of_letters);
    return 0;
}