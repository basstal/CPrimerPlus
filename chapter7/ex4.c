/**
利用if else语句编写程序读取输入，直到#。用一个感叹号代替每个句号，将原有的每个感叹号用两个感叹号代替，最后报告进行了多少次替换。
*/
#include	<stdio.h>
int main(void)
{
	char ch;
	int ct1 = 0;
	int ct2 = 0;

	while ((ch = getchar()) != '#')
	{
		switch(ch)
		{
		case '.' : putchar('!');
			++ct1;
			break;
		case '!' : putchar('!');
			putchar('!');
			++ct2;
			break;
		default : putchar(ch);	
		}
	}
	printf("%d replacements of . with !\n", ct1);
	printf("%d replacements of ! with !!\n", ct2);
	
	return 0;
}