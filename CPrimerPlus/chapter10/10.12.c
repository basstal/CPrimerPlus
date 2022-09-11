/**
 * @file 10.12.c
 * @author your name (you@domain.com)
 * @brief
 * Rewrite the rain program in Listing 10.7 so that the main tasks are performed by
functions instead of in main() .
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define MONTHS 12
#define YEARS 5
void every_year_rainfall(const float (*)[MONTHS]);
void average_rainfall_monthly(const float (*)[MONTHS]);
int main(void)
{
    const float rain[YEARS][MONTHS] = {
        {4.3f, 4.3f, 4.3f, 3.0f, 2.0f, 1.2f, 0.2f, 0.2f, 0.4f, 2.4f, 3.5f, 6.6f},
        {8.5f, 8.2f, 1.2f, 1.6f, 2.4f, 0.0f, 5.2f, 0.9f, 0.3f, 0.9f, 1.4f, 7.3f},
        {9.1f, 8.5f, 6.7f, 4.3f, 2.1f, 0.8f, 0.2f, 0.2f, 1.1f, 2.3f, 6.1f, 8.4f},
        {7.2f, 9.9f, 8.4f, 3.3f, 1.2f, 0.8f, 0.4f, 0.0f, 0.6f, 1.7f, 4.3f, 6.2f},
        {7.6f, 5.6f, 3.8f, 2.8f, 3.8f, 0.2f, 0.0f, 0.0f, 0.0f, 1.3f, 2.6f, 5.2f}};
    every_year_rainfall(rain);
    average_rainfall_monthly(rain);
    return 0;
}

void every_year_rainfall(const float (*source)[MONTHS])
{
    printf("YEAR   RAINFALL(inches)\n");
    int year, month;
    float total, subtot;

    for (year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += source[year][month];
        printf("%5d %15.1f\n", 2000 + year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
}

void average_rainfall_monthly(const float (*source)[MONTHS])
{
    printf("MONTHLY  AVERAGES:\n\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    int year, month;
    float subtot;

    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += source[year][month];
        printf("%4.1f", subtot / YEARS);
    }
    printf("\n");
}
