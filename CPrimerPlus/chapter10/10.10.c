#include <stdio.h>
#define SIZE 5
void show(double (*ar)[SIZE], int n);
void doubled(double (*ar)[SIZE], int n);
int main(void)
{
    double ar[3][SIZE] = {
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.2, 2.3, 2.4, 2.5, 2.6},
        {3.3, 3.4, 3.5, 3.6, 3.7}};
    doubled(ar, 3);
    show(ar, 3);
    return 0;
}
void show(double (*ar)[SIZE], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < SIZE; j++)
        {
            printf("ar[%d][%d]=%3g%3c", i, j, ar[i][j], ' ');
            printf("\n");
        }
    return;
}
void doubled(double (*ar)[SIZE], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < SIZE; j++)
            ar[i][j] *= 2;
    return;
}
