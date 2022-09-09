#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i = 2;
    FILE *fp;
    int count = 0;
    char ch;

    if (argc < 2)
    {
        printf("缺少命令行参数");
        exit(0);
    }
    else if (argc < 3)
    {
        fp = stdin;
        printf("以标准输入形式键入文件内容:\n");
        while ((ch = getchar()) != EOF)
            if (argv[1][0] == ch)
                count++;
        printf("%c在屏幕上出现次数为%d次.\n", argv[1][0], count);
    }
    else
        while (i < argc)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "文件无法打开,将打开下一个文件\n");
                i++;
                continue;
            }
            while ((ch = fgetc(fp)) != EOF)
                if (argv[1][0] == ch)
                    count++;
            printf("%c在文件%s出现次数为%d次.\n", argv[1][0], argv[i], count);
            fclose(fp);
            i++;
            count = 0;
        }
    return 0;
}
