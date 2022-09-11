

#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;

    i = argc;
    printf("命令行参数有%d个.\n", argc);
    printf("以下用相反顺序输出命令行参数:\n");
    for (; i > 0; i--)
        printf("%s ", argv[i]);
    return 0;
}
