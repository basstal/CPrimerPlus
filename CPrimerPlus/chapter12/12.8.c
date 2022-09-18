/**
 * @file 12.8.c
 * @author your name (you@domain.com)
 * @brief
 * Here’s part of a program:
 * Complete the program by providing function definitions for make_array() and show_
array() . The make_array() function takes two arguments. The first is the number
of elements of an int array, and the second is a value that is to be assigned to each
element. The function uses malloc() to create an array of a suitable size, sets each
element to the indicated value, and returns a pointer to the array. The show_array()
function displays the contents, eight numbers to a line.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

int *make_array(int, int);
void show_array(const int[], int);

int main(void)
{
    int *array_point;
    int size;
    int value;

    printf("Enter the size of the elements:");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value:");
        scanf("%d", &value);
        array_point = make_array(size, value);
        if (array_point != NULL)
        {
            show_array(array_point, size);
            free(array_point);
        }
        putchar('\n');
        printf("Enter the number of elements (less than 1 to quit):");
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int size, int initializeValue)
{
    int *result = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        *(result + i) = initializeValue;

    return result;
}

void show_array(const int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
        if ((i + 1) % 8 == 0)
            printf("\n");
    }
}
