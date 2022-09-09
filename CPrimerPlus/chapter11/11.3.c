#include <stdio.h>
#define LEN 80
char *getword(char *str);
int main(void)
{
    char input[LEN];

    while (getword(input) != NULL)
        puts(input);
    puts("done.\n");

    return 0;
}
#include <ctype.h>
char *getword(char *str)
{
    char ch;

    while ((ch = getchar()) != EOF && !isspace(ch))
        *str++ = ch;
    *str = '\0';
    if (ch == EOF)
        return NULL;
    else
    {
        while (ch != '\n')
            ch = getchar();
        return str;
    }
}