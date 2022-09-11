/**
 * @file 10.13.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that prompts the user to enter three sets of five double numbers each.
(You may assume the user responds correctly and doesn’t enter non-numeric data.) The
program should accomplish all of the following:
a. Store the information in a 3×5 array.
b. Compute the average of each set of five values.
c. Compute the average of all the values.
d. Determine the largest value of the 15 values.
e. Report the results.
Each major task should be handled by a separate function using the traditional C
approach to handling arrays. Accomplish task “b” by using a function that computes
and returns the average of a one-dimensional array; use a loop to call this function three
times. The other tasks should take the entire array as an argument, and the functions
performing tasks “c” and “d” should return the answer to the calling program.
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define COLS 5

void read_data_from_input(double (*)[COLS], int);
double average_of_set_values(const double (*)[COLS], int);
double average_of_all_values(const double (*)[COLS], int);
double find_largest(const double (*)[COLS], int);
void report(const double (*)[COLS], int);

int main(void)
{
    double source[3][COLS] = {0};
    read_data_from_input(source, 3);
    report(source, 3);
    return 0;
}

void read_data_from_input(double (*source)[COLS], int length)
{
    int i, j;
    printf("Enter %d double number into %d number sets:\n", COLS, length);
    for (i = 0; i < length; i++)
    {
        printf("Please fill number set #%d:\n", i + 1);
        for (j = 0; j < COLS; j++)
        {
            printf("#%d ", j + 1);
            while (scanf("%lf", &source[i][j]) != 1)
            {
                printf("Invalid input, please try again.\n");
                while (getchar() != '\n')
                    ;
                printf("#%d ", j + 1);
            }
        }
    }
}

double average_of_set_values(const double (*source)[COLS], int set_index)
{
    double average = source[set_index][0];
    for (int i = 1; i < COLS; i++)
        average = (average + *(source[set_index] + i)) / 2;
    printf("The average of set #%d is %lf\n", set_index, average);
    return average;
}

double average_of_all_values(const double (*source)[COLS], int length)
{
    double result = 0;
    for (int i = 0; i < length; i++)
        result += average_of_set_values(source, i);
    return result / length;
}

double find_largest(const double (*source)[COLS], int length)
{
    double max = source[0][0];
    for (int i = 0; i < length; i++)
        for (int j = 0; j < COLS; j++)
            max = max > source[i][j] ? max : source[i][j];
    return max;
}

void report(const double (*source)[COLS], int length)
{
    /**
     * @brief
     * {
     *  {0.1, 0.2, 0.3, 0.2, 0.1}
     *  {0.1, 0.2, 0.3, 0.2, 0.1}
     *  {0.1, 0.2, 0.3, 0.2, 0.1}
     * }
     */
    printf("{\n");
    for (int i = 0; i < length; ++i)
    {
        printf(" {");
        for (int j = 0; j < COLS; ++j)
        {
            printf("%lf%c ", source[i][j], j == COLS - 1 ? ' ' : ',');
        }
        printf(" }\n");
    }
    printf("}\n");

    for (int i = 0; i < length; ++i)
    {
        average_of_set_values(source, i);
    }
    double average_all = average_of_all_values(source, length);
    double largest = find_largest(source, length);

    printf("The average of all the values is %lf\n", average_all);
    printf("The largest value of the 15 values is %g\n", largest);
}
