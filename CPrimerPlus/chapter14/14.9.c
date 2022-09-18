/**
 * @file 14.9.c
 * @author your name (you@domain.com)
 * @brief
 * Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
handle four flights. Have a top-level menu that offers a choice of flights and the option
to quit. Selecting a particular flight should then bring up a menu similar to that of
exercise 8. However, one new item should be added: confirming a seat assignment. Also,
the quit choice should be replaced with the choice of exiting to the top-level menu. Each
display should indicate which flight is currently being handled. Also, the seat assignment
display should indicate the confirmation status.
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
#define MAXPLANE 4

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
    int confirmed;
} Seat;

typedef struct
{
    Seat seats[MAXSEAT];
} Plane;

char showmenu(Seat[], char[MAXNAME]);
void show_empty_seats(const Seat[]);
void show_list_empty_seats(const Seat[]);
void show_alpha_list_seats(const Seat[]);
void confirm_assignment(Seat[]);
void assignment(Seat[]);
void delete_assignment(Seat[]);
void read_data(Plane planes[])
{
    FILE *fp;
    if ((fp = fopen("planes.dat", "r+b")) != NULL)
    {
        size_t read_count = fread(planes, sizeof(Plane), MAXPLANE, fp);
        fclose(fp);
        if (read_count == MAXPLANE)
        {
            return;
        }
        fprintf(stderr, "planes.dat was corrupted. all data are lost.\n");
    }
    for (int i = 0; i < MAXPLANE; ++i)
    {
        Plane *plane = &planes[i];
        for (int seat = 0; seat < MAXSEAT; seat++)
        {
            plane->seats[seat].number = seat + 1;
            plane->seats[seat].assigned = 0;
            plane->seats[seat].confirmed = 0;
            strcpy(plane->seats[seat].name.first, "");
            strcpy(plane->seats[seat].name.last, "");
        }
    }
}
char top_level_menu(Plane planes[])
{
    char ch;
    printf("\nTo choose a plane, enter its letter label:\n"
           "a) plane 102\n"
           "b) plane 311\n"
           "c) plane 444\n"
           "d) plane 519\n"
           "f) Quit\n");
    ch = tolower(getchar());
    while (ch != '\n' && getchar() != '\n')
        continue;
    while (strchr("abcdf", ch) == NULL)
    {
        printf("Input label is not valid, please try again.\n");
        ch = tolower(getchar());
        while (ch != '\n' && getchar() != '\n')
            continue;
    }
    switch (ch)
    {
    case 'a':
        printf("You are now reserve the plane 102 seat.\n");
        while (showmenu(planes[0].seats, "plane 102") != 'f')
            ;
        break;
    case 'b':
        printf("You are now reserve the plane 311 seat.\n");
        while (showmenu(planes[1].seats, "plane 311") != 'f')
            ;
        break;
    case 'c':
        printf("You are now reserve the plane 444 seat.\n");
        while (showmenu(planes[2].seats, "plane 444") != 'f')
            ;
        break;
    case 'd':
        printf("You are now reserve the plane 519 seat.\n");
        while (showmenu(planes[3].seats, "plane 519") != 'f')
            ;
        break;
    }
    return ch;
}

int main(void)
{
    Plane planes[MAXPLANE];
    FILE *fp;
    read_data(planes);

    if ((fp = fopen("planes.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "Can't open planes.dat for write.\n");
        exit(EXIT_FAILURE);
    }
    while (top_level_menu(planes) != 'f')
        ;
    rewind(fp);
    if (fwrite(planes, sizeof(Plane), MAXPLANE, fp) < MAXPLANE)
    {
        fprintf(stderr, "Error when write data to planes.dat file.\n");
        exit(EXIT_FAILURE);
    }
    puts("bye");
    fclose(fp);
    return 0;
}

char showmenu(Seat planeseats[], char flight[MAXNAME])
{
    char ch;
    printf("\nTo choose a function for %s, enter its letter label:\n", flight);
    printf("a) Show number of empty seats\n"
           "b) Show list of empty seats\n"
           "c) Show alphabetical list of seats\n"
           "d) Assign a customer to a seat assignment\n"
           "e) Delete a seat assignment\n"
           "g) Confirming a seat assignment\n"
           "f) Quit\n");
    ch = tolower(getchar());
    while (ch != '\n' && getchar() != '\n')
        continue;
    while (strchr("abcdefg", ch) == NULL)
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
    case 'g':
        confirm_assignment(planeseats);
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
    printf("|number|assigned|confirm|assignee name|\n");
    printf("|---|---|---|---|\n");
    while (i < MAXSEAT)
    {
        printf("|%-8d|%-10s|%-10s|%-s %-s|\n",
               (seats + i)->number,
               (seats + i)->assigned == 0 ? "No" : "Yes",
               (seats + i)->confirmed == 0 ? "No" : "Yes",
               (seats + i)->name.last,
               (seats + i)->name.first);
        i++;
    }
}
void confirm_assignment(Seat seats[])
{
    int number;
    printf("Please enter the seat you want to confirm [1, %d] (q to quit):", MAXSEAT);
    if (scanf("%d", &number) != 1 || number < 1 || number > MAXSEAT)
    {
        printf("Abort.\n");
        return;
    }
    while (getchar() != '\n')
        continue;
    if (seats[number - 1].assigned == 0)
        printf("This seat hasn't been assigned that can't confirm.\n");
    else
    {
        printf("Confirming seat #%d have been reserved by %s %s.\n", number, seats[number - 1].name.last, seats[number - 1].name.first);
        seats[number - 1].confirmed = 1;
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
