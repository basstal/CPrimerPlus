/**
让程序要求用户输入一个大写字母，使用嵌套循环产生像下面这样的金字塔图案：
	A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
这种图案要扩展到用户输入的字符。
*/
#include  <stdio.h>

int main(void)
{
	char c;

	printf("Please input a character in capitals:");
	if( scanf("%c",&c) < 0 || c < 'A' || c > 'Z')
	{
		printf("Input error\n");
		return -1;
	}
	for(char bg = 'A' ; bg <= c ; ++bg)
	{
		//输出前置空格
		if(bg != c)
			printf("%*c",(int)c-bg,' ');
		//输出最左边开始到中央的字符
		for(char i = 'A' ; i <= bg ; ++i)
			printf("%c",i);
		//输出从中央右边开始到最右边的字符
		for(char i = bg-1 ; i >= 'A' ; --i)
			printf("%c",i);
		//输出换行符
		printf("\n");
	}

	return 0;
}