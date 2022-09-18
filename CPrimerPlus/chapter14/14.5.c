/**
 * @file 14.5.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that fits the following recipe:
 * a. Externally define a name structure template with two members: a string to hold the
first name and a string to hold the second name.
b. Externally define a student structure template with three members: a name
structure, a grade array to hold three floating-point scores, and a variable to hold
the average of those three scores.
c. Have the main() function declare an array of CSIZE (with CSIZE = 4 ) student
structures and initialize the name portions to names of your choice. Use functions
to perform the tasks described in parts d., e., f., and g.
d. Interactively acquire scores for each student by prompting the user with a student
name and a request for scores. Place the scores in the grade array portion of the
appropriate structure. The required looping can be done in main() or in the
function, as you prefer.
e. Calculate the average score value for each structure and assign it to the proper
member.
f. Print the information in each structure.
g. Print the class average for each of the numeric structure members.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#define LEN 14
#define CSIZE 4
#define SCORES 3

typedef struct
{
    char first[LEN];
    char last[LEN];
} name;
typedef struct
{
    name person;
    float scores[SCORES];
    float mean;
} student;

void get_scores(student[], int);
void find_means(student[], int);
void show_class(const student[], int);
void show_ave(const student[], int);

int main(void)
{
    student class[CSIZE] = {
        {"Flip", "Snide"},
        {"Clare", "Voyans"},
        {"Bingo", "Higgs"},
        {"Fawn", "Hunter"}};

    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_ave(class, CSIZE);
    return 0;
}

void get_scores(student students[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Please enter %d scores for %s %s :", SCORES, students[i].person.first, students[i].person.last);
        while (scanf("%f %f %f", &students[i].scores[0], &students[i].scores[1], &students[i].scores[2]) != 3)
        {
            while (getchar() != '\n')
                ;
            printf("Input scores are not valid.\n");
            printf("Please enter %d scores for %s %s :", SCORES, students[i].person.first, students[i].person.last);
        }
    }
}

void find_means(student students[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        students[i].mean = (students[i].scores[0] +
                            students[i].scores[1] +
                            students[i].scores[2]) /
                           3.0f;
    }
}

void show_class(const student students[], int length)
{
    printf("|name|score1|score2|score3|avg_score|\n");
    printf("|---|---|---|---|---|\n");
    for (int i = 0; i < length; i++)
    {
        printf("|%s %s|", students[i].person.first, students[i].person.last);
        printf("%lf|%lf|%lf|%lf|\n", students[i].scores[0], students[i].scores[1], students[i].scores[2], students[i].mean);
    }
}

void show_ave(const student students[], int length)
{
    printf("|avg_score1|avg_score2|avg_score3|\n");
    printf("|---|---|---|\n");
    printf("|");
    for (int i = 0; i < SCORES; i++)
    {
        float total = 0;
        for (int stu = 0; stu < length; stu++)
            total += students[stu].scores[i];
        printf("%6.2f|", total / length);
    }
    putchar('\n');
}