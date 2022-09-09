#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char showmenu(void);
void fixlibrary(struct book *plib);
void dellibrary(struct book *plib, int count, int *pi);

int main(void)
{
    int count = 0, i = 0, pos;
    char choice;
    struct book library[MAXBKS];
    int del[MAXBKS] = {0};
    FILE *fp;
    int size = sizeof(struct book);

    if ((fp = fopen("library.dat", "r+b")) == NULL)
    {
        fputs("Can't open library.dat file\n", stderr);
        exit(1);
    }

    while (count < MAXBKS && fread(&library[count], size, 1, fp) == 1)
    {
        printf("%s written by %s : $%g\n", library[count].title, library[count].author, library[count].value);
        choice = showmenu();
        switch (choice)
        {
        case 'f':
            fixlibrary(&library[count]);
            break;
        case 'd':
            dellibrary(&library[count], count, del);
        case 'n':
            break;
        }
        count++;
    }

    while (count < MAXBKS)
    {
        printf("请输入书名(输入空行结束)\n");
        if (del[i] != 0)
        {
            pos = del[i - 1];
            del[i++] = 0;
        }
        else
            pos = count;
        if (gets(library[pos].title) == NULL || library[pos].title[0] == '\0')
            break;
        printf("请输入作者\n");
        gets(library[pos].author);
        printf("请输入本书价格:");
        scanf("%f", &library[pos].value);
        while (getchar() != '\n')
            continue;
        count++;
    }

    rewind(fp);
    if (count > 0)
        fwrite(&library[0], size, count, fp);
    else
        printf("没有书?太可惜了.\n");

    puts("bye\n");
    fclose(fp);
    return 0;
}

char showmenu(void)
{
    char ch;
    printf("请输入字符对应选项:f)修改   d)删除  n)不处理\n");
    ch = tolower(getchar());
    while (ch != '\n' && getchar() != '\n')
        continue;
    while (strchr("fdn", ch) == NULL)
    {
        printf("请输入对应字符:f)修改   d)删除  n)不处理\n");
        ch = tolower(getchar());
        while (ch != '\n' && getchar() != '\n')
            continue;
    }
    return ch;
}

void fixlibrary(struct book *plib)
{
    printf("以下为修改内容\n请输入书名:\n");
    gets(plib->title);
    printf("请输入作者:");
    gets(plib->author);
    printf("请输入本书价格:");
    scanf("%f", plib->value);
    while (getchar() != '\n')
        continue;
}

void dellibrary(struct book *plib, int count, int *pi)
{
    static int i = 0;
    pi[i++] = count + 1;
    strcpy(plib->title, '\0');
    strcpy(plib->author, '\0');
    plib->value = 0;
}
