#include <stdio.h>
#define SHUCHU printf("a=%g\n", a)
double power(double a, int n);
int main(void)
{
    double a;
    int n;
    printf("Please input a and n:");
    while ((scanf("%lf %d", &a, &n)) == 2)
    {
        a = power(a, n);
        SHUCHU;
    }
    return 0;
}
double power(double a, int n)
{
    if (a == 0)
        return 0;
    else
    {
        if (n > 0)
            a = power(a, --n) * a;
        else if (n == 0)
            return 1;
        else
            a = power(a, --n) * (1 / a);
    }
    return a;
}
