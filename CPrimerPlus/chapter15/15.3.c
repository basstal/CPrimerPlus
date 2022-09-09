#include <stdio.h>
#define MASK 1

int openmount(int num);

int main(void)
{
    int num;
    int count;

    printf("输入数字:");
    scanf("%d", &num);
    count = openmount(num);
    printf("打开的位数为%d\n", count);

    return 0;
}

int openmount(int num)
{
    int count = 0;
    int copy = num;

    while ((num /= 2) != 0)
    {
        if (copy & MASK == 1)
            count++;
        copy >>= 1;
    }
    if (copy & MASK == 1)
        count++;

    return count;
}
