/**
 * @file 13.12.c
 * @author your name (you@domain.com)
 * @brief
 * Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
0–9 and be separated by spaces. The file is a digital representation of a picture, with
the values 0 through 9 representing increasing levels of darkness. Write a program that
reads the contents of the file into a 20-by-30 array of int s. In a crude approach toward
converting this digital representation to a picture, have the program use the values
in this array to initialize a 20-by-31 array of char s, with a 0 value corresponding to a
space character, a 1 value to the period character, and so on, with each larger number
represented by a character that occupies more space. For example, you might use # to
represent 9. The last character (the 31st) in each row should be a null character, making
it an array of 20 strings. Have the program display the resulting picture (that is, print the
strings) and also store the result in a text file. For example, suppose you start with this
data:
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
For one particular choice of output characters, the output looks like this:
   #        *%##%*'
     #      *%##%**'
            *%.#%*~*'
     #      *%##%* ~*'
   #        *%##%*  ~*'
            *%#.%*   ~*'
            *%##%*    ~*'
*************%##%*************
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
#### #################:#######
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
*************%##%*************
            *%##%*
            *%##%*    ==
     ''     *%##%*  *=  =*
     ::     *%##%* *=....=*
     ~~     *%##%*  *=  =*
     **     *%##%*    ==
            *%##%*
            *%##%*

 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%@";

void make_picture(int source[][COLS], char result[][COLS + 1]);
void init(char result[][COLS + 1]);

int main(void)
{
    int row, col;
    int source[ROWS][COLS];
    char result[ROWS][COLS + 1];
    char filename[40];
    FILE *fp;

    init(result);

    printf("Enter name of file:");
    scanf("%s", filename);
    if ((fp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            fscanf(fp, "%d", &source[row][col]);
    if (ferror(fp))
    {
        fprintf(stderr, "Error getting data from file.\n");
        exit(EXIT_FAILURE);
    }
    make_picture(source, result);

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
            putchar(result[row][col]);
        putchar('\n');
    }
    return 0;
}

void init(char array[][COLS + 1])
{
    int row, col;
    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            array[row][col] = '\0';
}

void make_picture(int source[][COLS], char result[][COLS + 1])
{
    int row, col;
    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            result[row][col] = trans[source[row][col]];
}
