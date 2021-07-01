/**
编写一个程序。该程序读取输入直到遇到#字符。使程序打印每个输入的字符以及它的十进制ASCII码。每行打印8个字符/编码对。
*/
#include	<stdio.h>
#include	<string.h>
int main(void)
{
	char ch;
	int countl = 0;
	printf("Please input characters:\n");
	while(( ch = getchar()) != '#')
	{
		printf("%c(%d) ",ch,(int)ch);
		++countl;
		if(countl % 8 == 0)
		{
			countl = 0;
			printf("\n");
		}
	}

	return 0;
}