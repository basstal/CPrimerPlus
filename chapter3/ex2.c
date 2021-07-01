/**
exercise 2:
编写一个程序，要求输入一个ASCII码值，然后输出相应的字符。
*/
#include	<stdio.h>
int main()
{
	int code;

	printf("Please input an ASCII encode (0~127):\n");
	if(scanf("%d",&code) < 0)
		return -1;
	printf("your input in ASCII is %c.\n",code);
	return 0;
}