#include <stdio.h>
#define SIZE 5
void save_dat(double (*ar)[SIZE], int n);
double ccl_each_set(const double *ar, int n);
double ccl_all_set(const double (*ar)[SIZE], int n);
double maxnum(const double (*ar)[SIZE], int n);
void print(const double (*ar)[SIZE], int n);
int main(void)
{
    double arr[3][5] = {0};
    double av1, av2, av3, avall;
    double max;

    save_dat(arr, 3);
    av1 = ccl_each_set(arr[0], 5);
    av2 = ccl_each_set(arr[1], 5);
    av3 = ccl_each_set(arr[2], 5);
    avall = ccl_all_set(arr, 3);
    max = maxnum(arr, 3);
    print(arr, 3);
    printf("The max number is %g\n", max);
    printf("%10s%10s%10s%15s\n", "average1", "average2", "average3", "averageall");
    printf("%10g%10g%10g%15g\n", av1, av2, av3, avall);

    return 0;
}

void save_dat(double (*ar)[SIZE], int n)
{
    int i, j;
    printf("Enter %d double number into %d number-sets:\n", SIZE, n);
    for (i = 0; i < n; i++)
    {
        printf("Please enter number-set #%d:\n", i + 1);
        for (j = 0; j < SIZE; j++)
        {
            printf("value #%d:", j + 1);
            scanf("%lf", &ar[i][j]);
        }
    }
}
double ccl_each_set(const double *ar, int n)
{
    int i;
    double total = 0;
    for (i = 0; i < n; ar++, i++)
        total += *ar;
    return (total / n);
}
double ccl_all_set(const double (*ar)[SIZE], int n)
{
    int i;
    double total = 0;
    for (i = 0; i < n; i++)
        total += ccl_each_set(ar[i], 5);
    return (total / n);
}
double maxnum(const double (*ar)[SIZE], int n)
{
    int i, j;
    double max;

    for (i = 0; i < n; i++)
        for (j = 0; j < SIZE; j++)
            max = max > ar[i][j] ? max : ar[i][j];
    return (max);
}

void print(const double (*ar)[SIZE], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < SIZE; j++)
            printf("ar[%d][%d]=%3g%3c", i, j, ar[i][j], ' ');
        printf("\n");
    }
}
