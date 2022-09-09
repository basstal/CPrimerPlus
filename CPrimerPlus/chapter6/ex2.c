/**
 * @file ex2.c
 * @author your name (you@domain.com)
 * @brief
 *   Use nested loops to produce the following pattern:
  $
  $$
  $$$
  $$$$
  $$$$$
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= i; ++j)
            printf("$");
        printf("\n");
    }

    return 0;
}
