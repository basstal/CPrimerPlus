#include <stdio.h>
double min(double, double);
int main()
{
    double x, y;
    printf("Please input two double number:");
    while ((scanf("%lf %lf", &x, &y)) == 2)
    {
        printf("%.2lf is smaller.\n", min(x, y));
        printf("Next two values(q to quit):");
    }
    printf("bye!\n");

    return 0;
}
double min(double x, double y)
{
    return x < y ? x : y;
}