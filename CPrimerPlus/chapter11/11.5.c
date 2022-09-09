#include <stdio.h>
#define SIZE 41
int is_within(char, char *);
int main(void)
{

    char ch;
    char str[SIZE] = {'\0'};
    int i;

    printf("Enter a string:\n");
    while (gets(str) && str[0] != '\0')
    {
        printf("Enter the char you want to search:");
        scanf("%c", &ch);
        while (getchar() != '\n')
            ;
        i = is_within(ch, str);
        if (i == 0)
            printf("Sorry,we didn't found %c in string.\n", ch);
        else
            printf("See!We found %c in string.\n", ch);
        printf("Enter a string:\n");
    }
    return 0;
}
int is_within(char ch, char *pc)
{
    while (*pc != ch && *pc != '\0')
        pc++;
    return *pc;
}
