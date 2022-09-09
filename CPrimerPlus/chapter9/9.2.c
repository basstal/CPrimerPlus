#include <stdio.h>
void chline(char, int, int);
void clean();
int main()
{
    char a;
    int c, d;

    printf("Please input a char:");
    a = getchar();
    clean();
    printf("Please input two int for rols:");
    scanf("%d %d", &c, &d);
    chline(a, c, d);
    return 0;
}

void chline(char ch, int i, int j)
{
    int kg;
    for (kg = 0; kg < i; kg++)
        printf(" ");
    for (; i < j; i++)
        printf("%c", ch);
}

void clean()
{
    while (getchar() != '\n')
        continue;
}