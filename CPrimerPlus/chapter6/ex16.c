/**
 * @file ex16.c
 * @author your name (you@domain.com)
 * @brief
 *   Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest compounded annually. (That is, interest is 5% of the current balance, including previous addition of interest.) Write a program that finds how many years it takes for the value of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two values at that time.
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

int main()
{
    double daphne = 100;
    double deidre = 100;
    int years = 0;

    while (deidre <= daphne)
    {
        daphne += 10;
        deidre += 0.05 * deidre;
        ++years;
    }

    printf("Investment values after %d years:\n", years);
    printf("Daphne: $%.2f\n", daphne);
    printf("Deidre: $%.2f\n", deidre);

    return 0;
}