/**
 * @file ex5.c
 * @author your name (you@domain.com)
 * @brief
 *  Have a program request the user to enter an uppercase letter. Use nested loops to produce a pyramid pattern like this:
 *     A
 *    ABA
 *   ABCBA
 *  ABCDCBA
   ABCDEDCBA
 The pattern should extend to the character entered. For example, the preceding pattern would result from an input value of  E . Hint: Use an outer loop to handle the rows. Use three inner loops in a row, one to handle the spaces, one for printing letters in ascending order, and one for printing letters in descending order. If your system doesn’t use ASCII or a similar system that represents letters in strict number order, see the suggestion in programming exercise 3.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(void)
{
    char c;

    printf("Please input a character in capitals:");
    if (scanf("%c", &c) < 0 || c < 'A' || c > 'Z')
    {
        printf("Input error\n");
        return -1;
    }
    for (char bg = 'A'; bg <= c; ++bg)
    {
        //输出前置空格
        if (bg != c)
            printf("%*c", (int)c - bg, ' ');
        //输出最左边开始到中央的字符
        for (char i = 'A'; i <= bg; ++i)
            printf("%c", i);
        //输出从中央右边开始到最右边的字符
        for (char i = bg - 1; i >= 'A'; --i)
            printf("%c", i);
        //输出换行符
        printf("\n");
    }

    return 0;
}
