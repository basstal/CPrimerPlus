#include <stdio.h>
int main(void)
{
    char fname[40];
    FILE *fp;
    int place, i;
    char ch;

    i = 0;
    printf("请输入文件名:\n");
    gets(fname);

    fp = fopen(fname, "r");
    printf("请输入用数字代表的文件位置（输入非数字退出）:");
    while (scanf("%d", &place))
    {
        while ((ch = fgetc(fp)) != EOF && i++ < place)
            ;
        while ((ch = fgetc(fp)) != EOF && ch != '\n')
            fputc(ch, stdout);
        printf("\n");
        printf("请输入用数字代表的文件位置（输入非数字退出）:");
        rewind(fp);
        i = 0;
    }
    fclose(fp);
    return 0;
}
