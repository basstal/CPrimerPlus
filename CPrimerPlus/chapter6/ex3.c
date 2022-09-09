/**
 * @file ex3.c
 * @author your name (you@domain.com)
 * @brief
 *   Use nested loops to produce the following pattern:
  F
  FE
  FED
  FEDC
  FEDCB
  FEDCBA
  Note: If your system doesn’t use ASCII or some other code that encodes letters in numeric order, you can use the following to initialize a character array to the letters of the alphabet:
  char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 Then you can use the array index to select individual letters; for example,  lets[0]  is  'A' , and so on.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    for (char ed = 'F'; ed >= 'A'; --ed)
    {
        for (char c = 'F'; c >= ed; --c)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}