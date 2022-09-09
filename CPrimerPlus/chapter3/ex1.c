/**
 * @file ex1.c
 * @author your name (you@domain.com)
 * @brief
 * Find out what your system does with integer overflow, floating-point overflow, and floating-point underflow by using the experimental approach; that is, write programs having these problems. (You can check the discussion in  Chapter   4    of  limits.h  and  float.h  to get guidance on the largest and smallest values.)
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("**integer overflow**\n");
    int maxd = INT_MAX;
    printf("INT_MAX = %d, INT_MAX + 1 = %d\n", maxd, maxd + 1);

    printf("**floating-point overflow**\n");
    double maxf = DBL_MAX;
    printf("DBL_MAX = %e, DBL_MAX + 1.0 = %e, DBL_MAX * 10.0 = %e\n", maxf, maxf + 1.0, maxf * 10.0);
    printf("**floating-point underflow**\n");
    double minf = DBL_TRUE_MIN;
    printf("DBL_TRUE_MIN = %e, DBL_TRUE_MIN - 1.0 = %e, DBL_TRUE_MIN / 10.0 = %e\n", minf, minf - 1.0, minf / 10.0);
    return 0;
}