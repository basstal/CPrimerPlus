/**
编写一个程序，把输入作为字符流读取，直到遇到EOF。令该程序打印每个输入字符及其ASCII编码的十进制值。
*/
#include	<stdio.h>  
int main(void) 
{  
	char ch;  
	int i = 0;
	printf("Please input(EOF to quit):");
	while( (ch = getchar()) != EOF)  
	{
		if (ch >= ' ' || ch == '\n' || ch == '\t')
			printf("%-3c",ch);
		else
			printf("^%-2c",ch+64);
		printf("(%-3d)",ch);
		++i;
		if(i%10 == 0)
		{
			i = 0;
			printf("\n");
		}
	}
	return 0;
}