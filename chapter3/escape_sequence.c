/**
example:
输出常见的转义字符用法和其含义
*/
#include	<stdio.h>

int main()
{
	printf("输出常见的转义字符用法和其含义:\n");
	printf("\\a : %s , example : \a\n","警报");
	printf("\\b : %s , example : \b\b \n","退格");
	printf("\\f : %s , example : \f\n","走纸");
	printf("\\n : %s , example : \n","换行");
	printf("\\r : %s , example : \rr\n","回车");
	printf("\\t : %s , example : \tt\n","水平制表符");
	printf("\\v : %s , example : \vv\n","垂直制表符");
	printf("\\\\ : %s, example : \\\n","反斜杠");
	printf("\\' : %s , example : \'\n","单引号");
	printf("\\\" : %s, example : \"\n","双引号");
	printf("\\? : %s, example : \?\n","问号");
	printf("\\0 : %s, example : \\077 as \077\n","八进制");
	printf("\\x : %s, example : \\x3f as \x3f\n","十六进制");

	return 0;
}












