#include <stdio.h>
void copy_arr(double[], double[], int);
void copy_ptr(double *, double *, int);
int main(void)
{
    int i;
    double a[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double b[5], c[5];
    copy_arr(a, b, 5);
    copy_ptr(a, c, 5);
    for (i = 0; i < 5; i++)
        printf("b[%d]=%g%*c", i, b[i], 3, ' ');
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("c[%d]=%g%*c", i, c[i], 3, ' ');
    printf("\n");
    return 0;
}
void copy_arr(double a[], double b[], int c)
{
    int i;
    for (i = 0; i < c; i++)
        b[i] = a[i];
}
void copy_ptr(double *a, double *b, int c)
{
    int i;
    for (i = 0; i < c; i++)
        *(b + i) = *(a + i);
}
