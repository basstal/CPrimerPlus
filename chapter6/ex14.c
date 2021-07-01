/**
编写一个程序读入一行输入，然后反向打印该行。
*/
#include	<stdio.h>

int main(void)
{
	char line[255];
	int i = 0;
	printf("Please input a line:\n");
	do
	{
		if(scanf("%c",&line[i]) < 0)
			return -1;
	}while(line[i] != '\n' && ++i < 255);
	
	while(i >= 0)
		printf("%c",line[--i]);
	printf("\n");
	
	return 0;
}
