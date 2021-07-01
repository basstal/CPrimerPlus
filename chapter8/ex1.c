/**
设计一个程序，统计从输入到文件结尾为止的字符数。
*/
#include	<stdio.h>
int main(void)
{
	int i=0;
	char c;

	printf("Please input:\n");
	while((c = getchar()) != EOF)
		i++;
	printf("There are %d characters.\n",i);

	return 0;
}
