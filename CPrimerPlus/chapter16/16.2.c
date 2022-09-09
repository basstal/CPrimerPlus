#include "normal.h"

#define HMEAN(X, Y) (1 / (((1 / (X)) + (1 / (Y))) / 2))

int main(void)
{
    double x, y;
    double result;

    printf("依次输入两个待测试数值用逗号隔开(x,y)=");
    scanf("%lf,%lf", &x, &y);
    result = HMEAN(x, y);
    printf("这两个数的调和平均数为%g\n", result);

    return 0;
}
