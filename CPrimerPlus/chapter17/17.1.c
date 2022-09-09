#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
	struct film *next;
	struct film *previous;
};

int main(void)
{
	struct film *head = NULL;
	struct film *tail = NULL;
	struct film *prev, *current;
	char input[TSIZE];
	int choice;

	puts("Enter first movie title:");
	while (gets(input) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
			current->previous = NULL;
		}
		else
		{
			prev->next = current;
			current->previous = prev;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title(empty line to stop):");
		prev = current;
	}
	tail = current;

	if (head == NULL)
		printf("No data entered.");
	else
		printf("Here is the movie list :\n");
	printf("选择1)从头部开始遍历2)从尾部开始遍历\n");
	while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
		printf("请输入数字1或2:\n");
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
		current = tail;
		while (current != NULL)
		{
			printf("Movie: %s Rating: %d\n", current->title, current->rating);
			current = current->previous;
		}
		break;
	}
	prev = head;
	while (current != NULL)
	{
		current = prev->next;
		free(prev);
	}
	free(prev);
	head = tail = NULL;
	printf("Bye!\n");

	return 0;
}