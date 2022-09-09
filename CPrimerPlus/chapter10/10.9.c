#include <stdio.h>
void addarr(double *ar1, double *ar2, double *ans, int n);
void show(double *ar, int n);
int main(void)
{
    double ar1[] = {2, 4, 5, 8};
    double ar2[] = {1, 0, 4, 6};
    double ar3[4];
    addarr(ar1, ar2, ar3, 4);
    show(ar3, 4);
    return 0;
}
void show(double *ar, int n)
{
    int i;

    for (i = 0; i < n; i++, ar++)
        printf("ar[%d]=%g%c", i, *ar, ' ');
    printf("\n");
    return;
}
void addarr(double *ar1, double *ar2, double *ans, int n)
{
    int i;

    for (i = 0; i < n; i++, ar1++, ar2++, ans++)
        *ans = *ar1 + *ar2;
    return;
}
