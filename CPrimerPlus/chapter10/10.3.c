#include <stdio.h>
int max_arr(int *, int);
int main(void)
{
    int a[5] = {5, 6, 2, 3, 1};
    printf("max=%d\n", max_arr(a, 5));
    return 0;
}

int max_arr(int *ar, int n)
{
    int i, max;
    max = ar[0];

    for (i = 1; i < n; i++)
        if (max < ar[i])
            max = ar[i];
    return max;
}
