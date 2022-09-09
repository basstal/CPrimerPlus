/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *  Write a program that displays the results of applying the modulus operation. The user should first enter an integer to be used as the second operand, which will then remain unchanged. Then the user enters the numbers for which the modulus will be computed, terminating the process by entering 0 or less. A sample run should look like this:
  This program computes moduli.
  Enter an integer to serve as the second operand:  256
  Now enter the first operand:  438
  438 % 256 is 182
  Enter next number for first operand (<= 0 to quit):  1234567
  1234567 % 256 is 135
  Enter next number for first operand (<= 0 to quit):  0
  Done
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    printf("This program computes moduli\n");
    printf("Please enter an integer to serve as the second operand:");
    int second_operand;
    if (scanf("%d", &second_operand) == -1)
    {
        return -1;
    }
    int be_div;
    printf("Now enter the first operand:");
    while (scanf("%d", &be_div) != -1 && be_div > 0)
    {
        printf("%d %% %d is %d\n", be_div, second_operand, be_div % second_operand);
        printf("Enter next number for first operand (<= 0 to quit):");
    }
    printf("Done\n");
    return 0;
}