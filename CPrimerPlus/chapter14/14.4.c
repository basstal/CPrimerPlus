#include <stdio.h>
struct name
{
    char name1[40];
    char name2[40];
    char name3[40];
};
struct record
{
    long number;
    struct name allname;
};
void print(long number, struct name allname, int i);
struct record data[5] = {
    {302039823, {"Dribble", "Mirst", "Flossie"}},
    {329584358, {"wang", "", "junke"}},
    {264981358, {"sylar", "w", "four"}},
    {246781215, {"yoiequ", "akuou", "kdlfuo"}},
    {549791321, {"Yoursluo", "", "alskdufo"}}};
int main(void)
{
    int i;
    for (i = 0; i < 5; i++)
        print(data[i].number, data[i].allname, i);
    return 0;
}

void print(long number, struct name allname, int i)
{
    if (allname.name2 != '\0')
        printf("%s,%s %c. - %ld\n", allname.name1, allname.name3, allname.name2[0], number);
    else
        printf("%s,%s - %ld\n", allname.name1, allname.name3, number);
}
