
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, void *argv[])
{
    double num;
    int exp;

    if (argc != 3)
        printf("Usage:%s number exponent\n", argv[0]);
    else
    {
        num = atof(argv[1]);
        exp = atoi(argv[2]);
        printf("%g to the %d power = %g\n", num, exp, pow(num, exp));
    }

    return 0;
}
