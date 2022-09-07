/**
编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取的所有其他字符数目。
*/
#include	<stdio.h>
int main(void)
{
	char c;
	int space,newln,other;
	space = newln = other = 0;
	printf("Please input (# to quit):\n");
	while(( c = getchar() ) != '#')
	{
		if(c == ' ')
			++space;
		else if(c == '\n')
			++newln;
		else
			++other;
	}
	printf("space = %d, newline = %d,others = %d\n",space,newln,other);

	return 0;
}
