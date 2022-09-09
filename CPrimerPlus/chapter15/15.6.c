#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID 0x000000ff
#define SIZE 0x0000007f
#define MASK 1

typedef struct
{
    unsigned int Font_ID : 8;
    unsigned int Font_Size : 7;
    unsigned int Pos : 2;
    unsigned int Bold : 1;
    unsigned int Italic : 1;
    unsigned int Underline : 1;
} CType;

char showmenu(void);

int main(void)
{
    CType par;
    char choice;
    int temp;
    char ch;
    char *position[3] = {"left", "center", "right"};

    par.Font_ID = 1;
    par.Font_Size = 12;
    par.Bold = 0;
    par.Italic = 0;
    par.Underline = 0;
    par.Pos = 0;
    //初始化位字段结构
    printf("ID SIZE ALIGNMENT B I U\n");
    printf("%d  %d  %s %s %s %s\n", par.Font_ID, par.Font_Size, position[par.Pos], par.Bold ? "on" : "off", par.Italic ? "on" : "off", par.Underline ? "on" : "off");
    choice = showmenu();
    while (choice != 'q')
    {
        switch (choice)
        {
        case 'f':
            printf("Enter Font ID:");
            scanf("%d", &temp);
            temp &= ID;
            par.Font_ID = temp;
            while (getchar() != '\n')
                ;
            break;
        case 's':
            printf("Enter Font Size:");
            scanf("%d", &temp);
            temp &= SIZE;
            par.Font_Size = temp;
            while (getchar() != '\n')
                ;
            break;
        case 'a':
            printf("Select alignment:\n"
                   "l)left c)center r)right\n");
            while (scanf("%c", &ch) && strchr("lcrLCR", ch) == NULL)
            {
                printf("请重新输入选项首字母!\n");
                while (getchar() != '\n')
                    continue;
            }
            while (getchar() != '\n')
                ;
            ch = tolower(ch);
            switch (ch)
            {
            case 'l':
                par.Pos = 0;
                break;
            case 'c':
                par.Pos = 1;
                break;
            case 'r':
                par.Pos = 2;
                break;
            }
            break;
        case 'b':
            par.Bold = ~par.Bold;
            break;
        case 'i':
            par.Italic = ~par.Italic;
            break;
        case 'u':
            par.Underline = ~par.Underline;
            break;
        }
        printf("ID SIZE ALIGNMENT B I U\n");
        printf("%d  %d  %s %s %s %s\n", par.Font_ID, par.Font_Size, position[par.Pos], par.Bold ? "on" : "off", par.Italic ? "on" : "off", par.Underline ? "on" : "off");
        choice = showmenu();
    }
    puts("bye!");

    return 0;
}

char showmenu(void)
{
    char ch;

    printf("f)change font  s)change size  a)change alignment\n"
           "b)toggle bold  i)toggle italic  u)toggle underline\n"
           "q)quit\n");
    while (scanf("%c", &ch) && strchr("FSABIUQfsabiuq", ch) == NULL)
    {
        printf("输入非法!请重新输入.\n");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        ;
    ch = tolower(ch);
    return ch;
}
