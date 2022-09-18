/**
 * @file 15.6.c
 * @author your name (you@domain.com)
 * @brief
 * Design a bit-field structure that holds the following information:
Font ID: A number in the range 0–255
Font Size: A number in the range 0–127
Alignment: A number in the range 0–2 represented the choices Left, Center, and Right
Bold: Off (0) or on (1)
Italic: Off (0) or on (1)
Underline: Off (0) or on (1)
Use this structure in a program that displays the font parameters and uses a looped menu
to let the user change parameters. For example, a sample run might look like this:
ID SIZE ALIGNMENT B I U
1 12 left off off off
f)change font s)change size a)change alignment
b)toggle bold i)toggle italic u)toggle underline
q)quit
s
Enter font size (0-127): 36
ID SIZE ALIGNMENT B I U
1 36 left off off off
f)change font s)change size a)change alignment
b)toggle bold i)toggle italic u)toggle underline
q)quit
a
Select alignment:
l)left c)center r)right
r
ID SIZE ALIGNMENT B I U
1 36 right off off off
f)change font s)change size a)change alignment
b)toggle bold i)toggle italic u)toggle underline
q)quit
i
ID SIZE ALIGNMENT B I U
1 36 right off on off
f)change font s)change size a)change alignment
b)toggle bold i)toggle italic u)toggle underline
q)quit
q
Bye!
The program should use the & operator and suitable masks to ensure that the ID and size
entries are converted to the specified range.

 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief
 *
 * Font ID: A number in the range 0–255
Font Size: A number in the range 0–127
Alignment: A number in the range 0–2 represented the choices Left, Center, and Right
Bold: Off (0) or on (1)
Italic: Off (0) or on (1)
Underline: Off (0) or on (1)
 */
typedef struct
{
    unsigned int Font_ID : 8;
    unsigned int Font_Size : 7;
    unsigned int Alignment : 2;
    unsigned int Bold : 1;
    unsigned int Italic : 1;
    unsigned int Underline : 1;
} Font_Param;

union Views
{
    Font_Param font_view;
    unsigned long ul_view;
};
const char *positions[3] = {"left", "center", "right"};

void show(union Views *font_param)
{
    printf("|ID|SIZE|ALIGNMENT|B|I|U|\n");
    printf("|---|---|---|---|---|---|\n");
    printf("|%d|%d|%s|%s|%s|%s|\n",
           font_param->font_view.Font_ID,
           font_param->font_view.Font_Size,
           positions[font_param->font_view.Alignment],
           font_param->font_view.Bold ? "on" : "off",
           font_param->font_view.Italic ? "on" : "off",
           font_param->font_view.Underline ? "on" : "off");
}
char menu(union Views *font_param)
{
    char ch;
    show(font_param);
    printf("f)change font s)change size a)change alignment\n"
           "b)toggle bold i)toggle italic u)toggle underline\n"
           "q) quit\n");
    while (scanf("%c", &ch) && strchr("FSABIUQfsabiuq", ch) == NULL)
    {
        printf("Input is not valid, please try again.\n");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        ;
    ch = tolower(ch);
    switch (ch)
    {
    case 'f':
        printf("Enter Font ID:");
        int id = 0;
        scanf("%d", &id);
        while (getchar() != '\n')
            ;
        font_param->font_view.Font_ID = 0;
        font_param->font_view.Font_ID |= id;
        break;
    case 's':
        printf("Enter Font Size:");
        int size = 0;
        scanf("%d", &size);
        while (getchar() != '\n')
            ;
        font_param->font_view.Font_Size = 0;
        font_param->font_view.Font_Size |= size;
        break;
    case 'a':
        printf("Select alignment:\n"
               "l)left c)center r)right\n");
        char alignment;
        while (scanf("%c", &alignment) && strchr("lcrLCR", alignment) == NULL)
        {
            printf("Input is not valid, please try again.\n");
            while (getchar() != '\n')
                continue;
        }
        while (getchar() != '\n')
            ;
        alignment = tolower(alignment);
        switch (alignment)
        {
        case 'l':
            font_param->font_view.Alignment = 0;
            break;
        case 'c':
            font_param->font_view.Alignment = 1;
            break;
        case 'r':
            font_param->font_view.Alignment = 2;
            break;
        }
        break;
    case 'b':
        font_param->font_view.Bold = ~font_param->font_view.Bold;
        break;
    case 'i':
        font_param->font_view.Italic = ~font_param->font_view.Italic;
        break;
    case 'u':
        font_param->font_view.Underline = ~font_param->font_view.Underline;
        break;
    }
    return ch;
}
int main(void)
{
    union Views font_param;

    font_param.font_view.Font_ID = 1;
    font_param.font_view.Font_Size = 12;
    font_param.font_view.Bold = 0;
    font_param.font_view.Italic = 0;
    font_param.font_view.Underline = 0;
    font_param.font_view.Alignment = 0;

    while (menu(&font_param) != 'q')
        ;
    puts("bye!");
    return 0;
}
