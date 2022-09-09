#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOLD 0x20000
#define ITALIC 0x40000
#define UNDERLINE 0x80000
#define RSETALI ~0x18000
#define RSETSIZE ~0x7f00
#define RSETID ~0xff
#define MASK 1
#define center 0x8000
#define right 0x10000

char showmenu(void);

int main(void)
{
    int par = 0;
    char choice;
    int temp;
    char ch;
    char *position[3] = {"left", "center", "right"};

    par |= MASK;
    par |= (12 << 8);
    //初始化字段内容

    printf("ID SIZE ALIGNMENT B I U\n");
    printf("%d  %d  %s %s %s %s\n", par & ~RSETID, (par & ~RSETSIZE) >> 8, position[(par & ~RSETALI) >> 15], (par & BOLD) ? "on" : "off", (par & ITALIC) ? "on" : "off", (par & UNDERLINE) ? "on" : "off");
    choice = showmenu();
    while (choice != 'q')
    {
        switch (choice)
        {
        case 'f':
            printf("Enter Font ID:");
            scanf("%d", &temp);
            while (getchar() != '\n')
                ;
            par &= RSETID;
            par |= temp;
            break;
        case 's':
            printf("Enter Font Size:");
            scanf("%d", &temp);
            while (getchar() != '\n')
                ;
            par &= RSETSIZE;
            par |= (temp << 8);
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
                par &= RSETALI;
                break;
            case 'c':
                par &= RSETALI;
                par |= (1 << 15);
                break;
            case 'r':
                par &= RSETALI;
                par |= (2 << 15);
                break;
            }
            break;
        case 'b':
            par ^= BOLD;
            break;
        case 'i':
            par ^= ITALIC;
            break;
        case 'u':
            par ^= UNDERLINE;
            break;
        }
        printf("ID SIZE ALIGNMENT B I U\n");
        printf("%d  %d  %s %s %s %s\n", par & ~RSETID, (par & ~RSETSIZE) >> 8, position[(par & ~RSETALI) >> 15], (par & BOLD) ? "on" : "off", (par & ITALIC) ? "on" : "off", (par & UNDERLINE) ? "on" : "off");
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
