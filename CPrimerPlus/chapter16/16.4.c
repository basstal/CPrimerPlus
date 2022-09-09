#include "normal.h"
#include <time.h>

void pass(double *begin);

int main(void)
{
    double begin;
    begin = clock();
    pass(&begin);

    return 0;
}

void pass(double *begin)
{
    double end;
    end = clock();
    while (((*begin - end) / CLOCKS_PER_SEC) != 0)
    {
        end = clock();
        printf("%f ", end);
    }
}
