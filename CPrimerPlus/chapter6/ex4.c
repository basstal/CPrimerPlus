/**
 * @file ex4.c
 * @author your name (you@domain.com)
 * @brief
 *   Use nested loops to produce the following pattern:
  A
  BC
  DEF
  GHIJ
  KLMNO
  PQRSTU
   If your system doesn’t encode letters in numeric order, see the suggestion in programming exercise 3.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    int line_count = 1;
    for (char p = 'A'; p <= 'U'; ++line_count)
    {
        for (int i = 0; i < line_count; ++i)
        {
            printf("%c", p++);
        }
        printf("\n");
    }
    return 0;
}