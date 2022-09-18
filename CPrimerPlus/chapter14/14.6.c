/**
 * @file 14.6.c
 * @author your name (you@domain.com)
 * @brief
 * A text file holds information about a softball team. Each line has data arranged as
follows:
4 Jessie Joybat 5 2 1 1
The first item is the player’s number, conveniently in the range 0–18. The second item
is the player’s first name, and the third is the player’s last name. Each name is a single
word. The next item is the player’s official times at bat, followed by the number of hits,
walks, and runs batted in (RBIs). The file may contain data for more than one game,
so the same player may have more than one line of data, and there may be data for
other players between those lines. Write a program that stores the data into an array of
structures. The structure should have members to represent the first and last names, the
at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
later). You can use the player number as an array index. The program should read to endof-
file, and it should keep cumulative totals for each player.
The world of baseball statistics is an involved one. For example, a walk or reaching base
on an error doesn’t count as an at-bat but could possibly produce an RBI. But all this
program has to do is read and process the data file, as described next, without worrying
about how realistic the data is.
The simplest way for the program to proceed is to initialize the structure contents to
zeros, read the file data into temporary variables, and then add them to the contents of
the corresponding structure. After the program has finished reading the file, it should
then calculate the batting average for each player and store it in the corresponding
structure member. The batting average is calculated by dividing the cumulative number
of hits for a player by the cumulative number of at-bats; it should be a floating-point
calculation. The program should then display the cumulative data for each player along
with a line showing the combined statistics for the entire team.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char first_name[40];
    char last_name[40];
    int at_bats;
    int hits;
    int walks;
    int RBIs;
    float batting_average;
} softball_statistics;

#define MAX_NUM 18
int main(void)
{
    softball_statistics data[MAX_NUM + 1] = {"", "", 0, 0, 0, 0, 0.0f};
    FILE *fp;
    if ((fp = fopen("softball_statistics.txt", "r+")) == NULL)
    {
        fprintf(stderr, "Can't open softball_statistics.txt file to read data.\n");
        exit(EXIT_FAILURE);
    }

    int index, at_bats, hits, walks, RBIs;
    char first_name[40], last_name[40];
    while (fscanf(fp, "%d %s %s %d %d %d %d", &index, first_name, last_name, &at_bats, &hits, &walks, &RBIs) != EOF)
    {
        if (index <= 0 || index > MAX_NUM)
        {
            fprintf(stderr, "player's number %d is not valid", index);
            exit(EXIT_FAILURE);
        }
        if (data[index - 1].first_name[0] == '\0')
        {
            strcpy(data[index - 1].first_name, first_name);
        }
        else if (strcmp(data[index - 1].first_name, first_name) != 0)
        {
            fprintf(stderr, "player's number %d , first name %s don't match with %s.", index, first_name, data[index - 1].first_name);
            exit(EXIT_FAILURE);
        }
        if (data[index - 1].last_name[0] == '\0')
        {
            strcpy(data[index - 1].last_name, last_name);
        }
        else if (strcmp(data[index - 1].last_name, last_name) != 0)
        {
            fprintf(stderr, "player's number %d , last name %s don't match with %s.", index, last_name, data[index - 1].last_name);
            exit(EXIT_FAILURE);
        }
        data[index - 1].at_bats += at_bats;
        data[index - 1].hits += hits;
        data[index - 1].walks += walks;
        data[index - 1].RBIs += RBIs;
    }
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (data[i].at_bats > 0)
        {
            data[i].batting_average = (float)data[i].hits / (float)data[i].at_bats;
        }
    }
    printf("|number|name|at bats|hits|walks|RBIs|batting_average|\n");
    printf("|---|---|---|---|---|---|---|\n");
    float total_batting_average = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        printf("|%3d|%10s %10s|%10d|%10d|%10d|%10d|%10f|\n", i + 1, data[i].first_name, data[i].last_name, data[i].at_bats, data[i].hits, data[i].walks, data[i].RBIs, data[i].batting_average);
        data[MAX_NUM].at_bats += data[i].at_bats;
        data[MAX_NUM].hits += data[i].hits;
        data[MAX_NUM].walks += data[i].walks;
        data[MAX_NUM].RBIs += data[i].RBIs;

        total_batting_average += data[i].batting_average;
    }
    data[MAX_NUM].batting_average = total_batting_average / MAX_NUM;
    printf("|total at bats|total hits|total walks|total RBIs|team average batting_average|\n");
    printf("|---|---|---|---|---|\n");

    printf("|%10d|%10d|%10d|%10d|%10f|\n", data[MAX_NUM].at_bats, data[MAX_NUM].hits, data[MAX_NUM].walks, data[MAX_NUM].RBIs, data[MAX_NUM].batting_average);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error when close file.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
