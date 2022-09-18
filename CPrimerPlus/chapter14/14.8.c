/**
 * @file 14.8.c
 * @author your name (you@domain.com)
 * @brief
 * The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
one flight daily. Write a seating reservation program with the following features:
a. The program uses an array of 12 structures. Each structure should hold a seat
identification number, a marker that indicates whether the seat is assigned, the last
name of the seat holder, and the first name of the seat holder.
b. The program displays the following menu:
To choose a function, enter its letter label:
    a) Show number of empty seats
    b) Show list of empty seats
    c) Show alphabetical list of seats
    d) Assign a customer to a seat assignment
    e) Delete a seat assignment
    f) Quit
c. The program successfully executes the promises of its menu. Choices d) and e)
require additional input, and each should enable the user to abort an entry.
d. After executing a particular function, the program shows the menu again, except
for choice f) .
e. Data is saved in a file between runs. When the program is restarted, it first loads in
the data, if any, from the file.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 40
#define MAXSEAT 12

typedef struct
{
    char first[MAXNAME];
    char last[MAXNAME];
} Name;

typedef struct
{
    int number;
    int assigned;
    Name name;
} Seat;

char showmenu(Seat planeseats[]);
void show_empty_seats(const Seat[]);
void show_list_empty_seats(const Seat[]);
void show_alpha_list_seats(const Seat[]);
void assignment(Seat[]);
void delete_assignment(Seat[]);

int main(void)
{
    Seat planeseats[MAXSEAT];
    FILE *fp;
    for (int i = 0; i < MAXSEAT; i++)
    {
        planeseats[i].number = i + 1;
        planeseats[i].assigned = 0;
        strcpy(planeseats[i].name.first, "");
        strcpy(planeseats[i].name.last, "");
    }
    if ((fp = fopen("planeseat.dat", "r+b")) != NULL)
    {
        int count = 0;
        while (count < MAXSEAT && fread(&planeseats[count], sizeof(Seat), 1, fp) == 1)
        {
            if (count == 0)
                puts("Current contents of planeseat.dat:");
            if (planeseats[count].assigned)
            {
                printf("#%d assigned by %s %s.\n", planeseats[count].number,
                       planeseats[count].name.first, planeseats[count].name.last);
            }
            else
            {
                printf("#%d wasn't assigned.\n", planeseats[count].number);
            }
            count++;
        }
        fclose(fp);
    }
    if ((fp = fopen("planeseat.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "Can't open planeseat.dat for write.\n");
        exit(EXIT_FAILURE);
    }
    while (showmenu(planeseats) != 'f')
        ;
    rewind(fp);
    if (fwrite(planeseats, sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
    {
        fprintf(stderr, "Error when write data to planseats.dat file.\n");
        exit(EXIT_FAILURE);
    }
    puts("bye");
    fclose(fp);
    return 0;
}

char showmenu(Seat planeseats[])
{
    char ch;
    printf("\nTo choose a function, enter its letter label:\n"
           "a) Show number of empty seats\n"
           "b) Show list of empty seats\n"
           "c) Show alphabetical list of seats\n"
           "d) Assign a customer to a seat assignment\n"
           "e) Delete a seat assignment\n"
           "f) Quit\n");
    ch = tolower(getchar());
    while (ch != '\n' && getchar() != '\n')
        continue;
    while (strchr("abcdef", ch) == NULL)
    {
        printf("Input label is not valid, please try again.\n");
        ch = tolower(getchar());
        while (ch != '\n' && getchar() != '\n')
            continue;
    }
    switch (ch)
    {
    case 'a':
    case 'b':
        show_empty_seats(planeseats);
        break;
    case 'c':
        show_alpha_list_seats(planeseats);
        break;
    case 'd':
        assignment(planeseats);
        break;
    case 'e':
        delete_assignment(planeseats);
        break;
    }
    return ch;
}

void show_empty_seats(const Seat seats[])
{
    int i = 0, count = 0;
    while (i < MAXSEAT)
    {
        if ((seats + i)->assigned == 0)
        {
            printf("#%d seat is empty\n", (seats + i)->number);
            count++;
        }
        i++;
    }
    printf("There are %d empty seats totally.\n", count);
}

void show_alpha_list_seats(const Seat seats[])
{
    int i = 0;
    printf("|number|assigned|assignee name|\n");
    printf("|---|---|---|\n");
    while (i < MAXSEAT)
    {
        printf("|%-8d|%-10s|%-s %-s|\n", (seats + i)->number, (seats + i)->assigned == 0 ? "No" : "Yes",
               (seats + i)->name.last, (seats + i)->name.first);
        i++;
    }
}

void assignment(Seat seats[])
{
    int number;
    printf("Please enter the seat you want to reserve [1, %d] (q to quit):", MAXSEAT);
    if (scanf("%d", &number) != 1 || number < 1 || number > MAXSEAT)
    {
        printf("Abort.\n");
        return;
    }
    while (getchar() != '\n')
        continue;
    if (seats[number - 1].assigned == 1)
        printf("This seat has been assigned.\n");
    else
    {
        seats[number - 1].assigned = 1;
        printf("Please enter your last name : ");
        while (gets(seats[number - 1].name.last) == NULL || seats[number - 1].name.last[0] == '\0')
            printf("Input is not valid.\n");
        printf("Please enter your first name : ");
        while (gets(seats[number - 1].name.first) == NULL || seats[number - 1].name.first[0] == '\0')
            printf("Input is not valid.\n");
        printf("Your name is %s %s and you have reserved the #%d seat, Thanks.\n", seats[number - 1].name.last, seats[number - 1].name.first, number);
    }
}

void delete_assignment(Seat seats[])
{
    printf("Please enter the seat you want to delete [1, %d] (q to quit) :", MAXSEAT);
    int number;
    if (scanf("%d", &number) != 1 || number < 1 || number > MAXSEAT)
    {
        printf("Abort.\n");
        return;
    }
    while (getchar() != '\n')
        continue;
    if (seats[number - 1].assigned == 0)
        printf("Seat #%d was not assigned.\n", number);
    else
    {
        seats[number - 1].assigned = 0;
        strcpy(seats[number - 1].name.first, "");
        strcpy(seats[number - 1].name.last, "");
        printf("Seat #%d assignment have been reset.\n", number);
    }
}
