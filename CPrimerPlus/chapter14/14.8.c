#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 40
#define MAXSEAT 12

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

char showmenu(void);
void swemptynum(const Seat pseat[]);
void swemptylist(const Seat pseat[]);
void swalllist(const Seat pseat[]);
void assignseat(Seat pseat[]);
void deleteseat(Seat pseat[]);

int main(void)
{
	Seat planeseat[MAXSEAT];
	FILE *fp;
	char choice;
	int i;
	for (i = 0; i < MAXSEAT; i++)
	{
		planeseat[i].code = i + 1;
		planeseat[i].flag = 0;
		planeseat[i].person.first[0] = '\0';
		planeseat[i].person.last[0] = '\0';
	}
	if ((fp = fopen("planeseat.dat", "r+b")) == NULL)
	{
		printf("打开文件错误\n");
		exit(1);
	}
	if (fread(planeseat, sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
	{
		printf("读取文件错误或文件内无内容\n");
	}
	choice = showmenu();
	while (choice != 'f')
	{
		switch (choice)
		{
		case 'a':
			swemptynum(planeseat);
			break;
		case 'b':
			swemptylist(planeseat);
			break;
		case 'c':
			swalllist(planeseat);
			break;
		case 'd':
			assignseat(planeseat);
			break;
		case 'e':
			deleteseat(planeseat);
		}
		choice = showmenu();
	}
	if (fwrite(planeseat, sizeof(Seat), MAXSEAT, fp) < MAXSEAT)
	{
		printf("写入文件错误\n");
		exit(1);
	}
	puts("bye");
	return 0;
}

char showmenu(void)
{
	char ch;
	printf("\nTo choose a function, enter its letter label:\n"
		   "a)Show number of empty seats\n"
		   "b)Show list of empty seats\n"
		   "c)Show alphabetical list of seats\n"
		   "d)Assign a customer to a seat assignment\n"
		   "e)Delete a seat assignment\n"
		   "f)Quit\n");
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
	return ch;
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
