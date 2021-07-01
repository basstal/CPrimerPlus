#include<stdio.h>
#include<stdlib.h>
void print(char (*parr)[100],int line);
void print_ASC(char (*parr)[100],int line);
void print_long(char (*parr)[100],int line);
void print_strl(char (*parr)[100],int line);
int strl(char *parr);
void exchange(char (*parr)[100],int n1,int n2);
int hlong(char *parr);
void copy(char (*target)[100],char (*source)[100],int line);
void menu(void);
int main(void)
{
	char arr_cp[10][100];
	char arr[10][100];
	int num,i;

	for(i=0;i<10;i++)
	{
		printf("输入字符串#%d:\n",i);
		if(gets(arr[i])==NULL)
			break;
	}
	copy(arr_cp,arr,i);
	while(1)
	{
		menu();
		printf("Enter your choice:");
		scanf("%d",&num);
		while(getchar()!='\n');
		if(num>=1&&num<=5)
			switch(num)
			{
			case 1:print(arr_cp,i);
				break;
			case 2:print_ASC(arr_cp,i);
				break;
			case 3:print_long(arr_cp,i);
				break;
			case 4:print_strl(arr_cp,i);
				break;
			case 5:exit(0);
			}
		else
			printf("Number between 1 and 5!\n");
		copy(arr_cp,arr,i);
	}
	return 0;
}

void print(char (*parr)[100],int line)
{
	int i;
	for(i=0;i<line;i++)
		puts(parr[i]);
}
void print_ASC(char (*parr)[100],int line)
{
	int i,j;

	for(i=0;i<line-1;i++)
		for(j=i+1;j<line;j++)
			if(parr[i][0]>parr[j][0])
				exchange(parr,i,j);
	print(parr,line);

}
void print_long(char (*parr)[100],int line)
{
	int i,j;

	for(i=0;i<line-1;i++)
		for(j=i+1;j<line;j++)
			if(hlong(parr[i])>hlong(parr[j]))
				exchange(parr,i,j);
	print(parr,line);
}
void print_strl(char (*parr)[100],int line)
{
	int i,j;

	for(i=0;i<line-1;i++)
		for(j=i+1;j<line;j++)
			if(strl(parr[i])>strl(parr[j]))
				exchange(parr,i,j);
	print(parr,line);
}

int strl(char *parr)
{
	int i=0;
	while(*parr++!=' ')
		i++;

	return i;
}
void exchange(char (*parr)[100],int n1,int n2)
{
	char temp[100];
	int i;

	for(i=0;i<100;i++)
	{
		temp[i]=parr[n1][i];
		parr[n1][i]=parr[n2][i];
		parr[n2][i]=temp[i];
	}
}
int hlong(char *parr)
{
	int i=0;

	while(*parr++)
		i++;
	return i;
}
void copy(char (*target)[100],char (*source)[100],int line)
{
	int i,j;

	for(i=0;i<line;i++)
		for(j=0;j<100;j++)
			target[i][j]=source[i][j];
}
void menu(void)
{
	printf("1、输出初始字符串列表\n");
	printf("2、按ASCⅡ顺序输出字符串\n");
	printf("3、按长度递增顺序输出字符串\n");
	printf("4、按字符串中第一个单词的长度输出字符串\n");
	printf("5、退出\n");
}


