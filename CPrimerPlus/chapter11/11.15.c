

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
long atoi_cp(char *pc);
long num_pow(int pow);
int main(void)
{
    long num;
    char ch_num[256];

    printf("输入一行带数字的字符串:\n");
    gets(ch_num);
    num = atoi_cp(ch_num);
    printf("该数字为%ld.\n", num);
    return 0;
}

long atoi_cp(char *pc)
{
    int i = 0, num;
    long total = 0;
    int number[40];

    while (isspace(*pc))
        pc++;
    while (isdigit(*pc))
    {
        number[i] = *pc - 48;
        pc++;
        i++;
    }
    number[i] = '\0';
    num = i;
    // printf("%d",num);
    // for(i=0;i<num;i++)
    // printf("%d",number[i]);
    for (i = 0; i < num; i++)
        total += num_pow(num - 1 - i) * number[i];
    total += number[i];
    return total;
}
long num_pow(int pow)
{
    int i;
    long num = 1;
    for (i = 0; i < pow; i++)
        num *= 10;
    return num;
}
