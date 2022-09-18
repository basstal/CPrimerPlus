/**
 * @file 14.4.c
 * @author your name (you@domain.com)
 * @brief
 * Write a program that creates a structure template with two members according to the
following criteria:
a. The first member is a social security number. The second member is a structure
with three members. Its first member contains a first name, its second member
contains a middle name, and its final member contains a last name. Create and
initialize an array of five such structures. Have the program print the data in this
format:
Dribble, Flossie M. –– 302039823
Only the initial letter of the middle name is printed, and a period is added. Neither the
initial (of course) nor the period should be printed if the middle name member is empty.
Write a function to do the printing; pass the structure array to the function.
b. Modify part a. by passing the structure value instead of the address.
 * @version 0.1
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

struct name
{
    char first[40];
    char middle[40];
    char final[40];
};

struct record
{
    long social_security_number;
    struct name name;
};

void print_all(struct record[], int);
void print_record(struct record data);
struct record data[5] = {
    {302039823, {"Dribble", "Mirst", "Flossie"}},
    {329584358, {"wang", "", "junke"}},
    {264981358, {"sylar", "w", "four"}},
    {246781215, {"yoiequ", "akuou", "kdlfuo"}},
    {549791321, {"Yoursluo", "", "alskdufo"}}};

int main(void)
{
    print_all(data, 5);
    for (int i = 0; i < 5; ++i)
        print_record(data[i]);
    return 0;
}

void print_record(struct record data)
{
    struct name name = data.name;
    if (name.middle[0] != '\0')
        printf("%s,%s %c. - %ld\n", name.first, name.final, name.middle[0], data.social_security_number);
    else
        printf("%s,%s - %ld\n", name.first, name.final, data.social_security_number);
}

void print_all(struct record data[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        struct name name = data[i].name;
        if (name.middle[0] != '\0')
            printf("%s,%s %c. - %ld\n", name.first, name.final, name.middle[0], data[i].social_security_number);
        else
            printf("%s,%s - %ld\n", name.first, name.final, data[i].social_security_number);
    }
}
