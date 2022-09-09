#include <stdio.h>
void to_base_n(unsigned long, unsigned int);
int main(void)
{
    unsigned long number;
    unsigned int base;
    printf("Enter an integer and base number(q to quit):\n");
    while (scanf("%lu%u", &number, &base) == 2)
    {
        printf("%lu's base %u equivalent: ", number, base);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}
void to_base_n(unsigned long n, unsigned int base)
{
    int r;
    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    printf("%d", r);
    return;
}