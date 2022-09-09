/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *   Modify the guessing program of  Listing   8.4    so that it uses a more intelligent guessing strategy. For example, have the program initially guess 50, and have it ask the user whether the guess is high, low, or correct. If, say, the guess is low, have the next guess be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be halfway between 75 and 50, and so on. Using this  binary search  strategy, the program quickly zeros in on the correct answer, at least if the user does not cheat.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

char get_response(int current_guess)
{
    printf("%d?\n", current_guess);
    printf("Is the guess bigger or smaller than the answer (B for bigger, S for smaller, R for right):");
    char result;
    while ((result = getchar()) == '\n')
        continue;
    return result;
}
int main(void)
{
    int current_guess = 50, min = 1, max = 100;
    char response;

    printf("Please pick an integer number and let me guess.\n");
    while ((response = get_response(current_guess)) != 'R')
    {
        int next_guess;
        switch (response)
        {
        case 'B':
            max = current_guess;
            next_guess = (min + current_guess) / 2;
            break;
        case 'S':
            min = current_guess;
            next_guess = (max + current_guess) / 2;
            break;
        default:
            printf("%c is not a valid option, please response again.\n", response);
            continue;
        }
        if (current_guess == next_guess)
        {
            printf("You are cheating!\n");
            return -1;
        }
        current_guess = next_guess;
    }
    printf("%d, Am i right?\n", current_guess);
    return 0;
}