#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};

void backprint(struct film *);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    int choice;

    puts("Enter first movie title:");
    while (gets(input) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title(empty line to stop):");
        prev = current;
    }

    if (head == NULL)
        printf("No data entered.");
    else
        printf("Here is the movie list :\n");
    printf("选择1)从头部开始遍历2)从尾部开始遍历\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf("请输入数字1或2:\n");
        while (getchar() != '\n')
            continue;
    }
    switch (choice)
    {
    case 1:
        current = head;
        while (current != NULL)
        {
            printf("Movie: %s Rating: %d\n", current->title, current->rating);
            current = current->next;
        }
        break;
    case 2:
        current = head;
        backprint(current);
        break;
    }
    prev = head;
    while (current != NULL)
    {
        current = prev->next;
        free(prev);
        prev = current;
    }
    free(prev);
    head = NULL;
    printf("Bye!\n");

    return 0;
}

void backprint(struct film *p)
{
    if (p)
    {
        backprint(p->next);
        printf("Movie: %s Rating: %d\n", p->title, p->rating);
    }
}
