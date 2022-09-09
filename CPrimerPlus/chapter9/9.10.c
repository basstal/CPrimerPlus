#include <stdio.h>
int fibonacci(int n);
int main(void)
{
    int n;
    printf("Please input n:");
    while ((scanf("%d", &n)) == 1)
    {
        printf("fibonacci n=%d", fibonacci(n));
        printf("\nPlease input n:");
    }
    return 0;
}
int fibonacci(int n)
{
    int a[255];
    int i;
    a[0] = 1;
    a[1] = 1;
    for (i = 0; i < n; i++)
        a[i + 1] = a[i] + a[i - 1];
    return a[n - 1];
}
