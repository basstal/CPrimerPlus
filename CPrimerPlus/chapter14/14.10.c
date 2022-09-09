#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 40
#define MAXSEAT 12
#define PLANE 4

typedef struct
{
    char first[MAXNAME];
    char last[MAXNAME];
} Name;

typedef struct
{
    int code;
    int flag;
    Name person;
} Seat;

int showplane(void);
int showmenu(void);
void swemptynum(const Seat pseat[]);
void swemptylist(const Seat pseat[]);
void swalllist(const Seat pseat[]);
void assignseat(Seat pseat[]);
void deleteseat(Seat pseat[]);
void getchoice(Seat planeseat[][MAXSEAT], int plane);
void (*pf[5])(Seat[]) = {swemptynum, swemptylist, swalllist, assignseat, deleteseat};

int main(void)
{
    int plane;
    Seat planeseat[PLANE][MAXSEAT];
    FILE *fp;
    int i, j;

    for (j = 0; j < PLANE; j++)
        for (i = 0; i < MAXSEAT; i++)
        {
            planeseat[j][i].code = i + 1;
            planeseat[j][i].flag = 0;
            planeseat[j][i].person.first[0] = '\0';
            planeseat[j][i].person.last[0] = '\0';
        } //初始化结构数组
    while ((plane = showplane()) != 5)
    {
        switch (plane)
        {
        case 1:
            plane = plane - 1;
            if ((fp = fopen("planeseat102.dat", "r+b")) == NULL)
            {
                printf("打开文件错误\n");
                exit(1);
            }
            if (fread(planeseat[plane], sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
            {
                printf("读取文件错误或文件内无内容\n");
            }
            getchoice(planeseat, plane);
            break;
        case 2:
            plane = plane - 1;
            if ((fp = fopen("planeseat311.dat", "r+b")) == NULL)
            {
                printf("打开文件错误\n");
                exit(1);
            }
            if (fread(planeseat[plane], sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
            {
                printf("读取文件错误或文件内无内容\n");
            }
            getchoice(planeseat, plane);
            break;
        case 3:
            plane = plane - 1;
            if ((fp = fopen("planeseat444.dat", "r+b")) == NULL)
            {
                printf("打开文件错误\n");
                exit(1);
            }
            if (fread(planeseat[plane], sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
            {
                printf("读取文件错误或文件内无内容\n");
            }
            getchoice(planeseat, plane);
            break;
        case 4:
            plane = plane - 1;
            if ((fp = fopen("planeseat519.dat", "r+b")) == NULL)
            {
                printf("打开文件错误\n");
                exit(1);
            }
            if (fread(planeseat[plane], sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
            {
                printf("读取文件错误或文件内无内容\n");
            }
            getchoice(planeseat, plane);
            break;
        }
    }
    for (j = 0; j < PLANE; j++)
        if (fwrite(planeseat[j], sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
        {
            printf("写入文件错误\n");
            exit(1);
        }
    puts("bye");
    return 0;
}

int showmenu(void)
{
    char ch;
    printf("\nTo choose a function, enter its letter label:\n"
           "a)Show number of empty seats\n"
           "b)Show list of empty seats\n"
           "c)Show alphabetical list of seats\n"
           "d)Assign a customer to a seat assignment\n"
           "e)Delete a seat assignment\n"
           "f)回到航班选择菜单\n");
    ch = tolower(getchar());
    while (ch != '\n' && getchar() != '\n')
        continue;
    while (strchr("abcdef", ch) == NULL)
    {
        printf("请输入abcdef以对应以上选项");
        ch = tolower(getchar());
        while (ch != '\n' && getchar() != '\n')
            continue;
    }
    return (int)(ch - 97);
}

void swemptynum(const Seat pseat[])
{
    int i = 0, count = 0;
    while (i < MAXSEAT)
    {
        if ((pseat + i)->flag == 0)
            count++;
        i++;
    }
    printf("总共还有%d个空余座位", count);
}

void swemptylist(const Seat pseat[])
{
    int i = 0;
    printf("以下为空余座位的座位编码:\n");
    while (i < MAXSEAT)
    {
        if ((pseat + i)->flag == 0)
            printf(" %d", (pseat + i)->code);
        i++;
    }
}

void swalllist(const Seat pseat[])
{
    int i = 0;
    printf("编号   是否被预约   预约人姓名\n");
    while (i < MAXSEAT)
    {
        printf(" %-8d %-10s %-s %-s\n", (pseat + i)->code, (pseat + i)->flag == 0 ? "No" : "Yes",
               (pseat + i)->person.last, (pseat + i)->person.first);
        i++;
    }
}

void assignseat(Seat pseat[])
{
    int cd;
    printf("请输入申请座位编号(输入非数字字符退出):");
    while (scanf("%d", &cd))
    {
        while (getchar() != '\n')
            continue;
        if (cd < 1 || cd > MAXSEAT)
        {
            printf("输入值在1--%d之间", MAXSEAT);
            continue;
        }
        if (pseat[cd - 1].flag == 1)
            printf("该座位已被预定\n");
        else
        {
            pseat[cd - 1].flag = 1;
            printf("请输入您的姓\n");
            while (gets(pseat[cd - 1].person.last) == NULL || pseat[cd - 1].person.last[0] == '\0')
                printf("请重新输入\n");
            printf("请输入您的名\n");
            while (gets(pseat[cd - 1].person.first) == NULL || pseat[cd - 1].person.first[0] == '\0')
                printf("请重新输入\n");
            printf("您的姓名:%s %s\n", pseat[cd - 1].person.last, pseat[cd - 1].person.first);
        }
        printf("请输入申请座位编号(输入非数字字符退出):");
    }
    while (getchar() != '\n')
        continue;
}

void deleteseat(Seat pseat[])
{
    int cd;
    printf("请输入申请座位编号(输入非数字字符退出):");
    while (scanf("%d", &cd))
    {
        while (getchar() != '\n')
            continue;
        if (cd < 1 || cd > MAXSEAT)
        {
            printf("输入值在1--%d之间", MAXSEAT);
            continue;
        }
        if (pseat[cd - 1].flag == 0)
            printf("该座位无人预定,不能清除.\n");
        else
        {
            pseat[cd - 1].flag = 0;
            pseat[cd - 1].person.first[0] = pseat[cd - 1].person.last[0] = '\0';
            printf("已清除#%d座位的预定\n", pseat[cd - 1].code);
        }
        printf("请输入申请座位编号(输入非数字字符退出):");
    }
    while (getchar() != '\n')
        continue;
}

int showplane(void)
{
    int plane;
    printf("请选择对应编号航班:\n"
           "1)航班102   2)航班311\n"
           "3)航班444   4)航班519\n"
           "5)退出程序\n");
    while (scanf("%d", &plane) != 1)
        printf("请输入数字1-5");
    while (plane < 1 || plane > 5)
    {
        printf("输入数字范围在1-5,请重新输入");
        scanf("%d", &plane);
    }
    while (getchar() != '\n')
        continue;
    return plane;
}

void getchoice(Seat planeseat[][MAXSEAT], int plane)
{
    int choice;
    choice = showmenu();
    while (choice != 5)
    {
        switch (choice)
        {
        case 0:
            pf[choice](planeseat[plane]);
            break;
        case 1:
            pf[choice](planeseat[plane]);
            break;
        case 2:
            pf[choice](planeseat[plane]);
            break;
        case 3:
            pf[choice](planeseat[plane]);
            break;
        case 4:
            pf[choice](planeseat[plane]);
        }
        choice = showmenu();
    }
}
