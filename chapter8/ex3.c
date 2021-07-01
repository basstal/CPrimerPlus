/**
编写一个程序，把输入作为字符流读取，直至遇到EOF。令其报告输入中的大写字母个数和小写字母个数。
*/
#include	<stdio.h>
int main(void)
{
	char c;
	int i,j;

	i=j=0;
	printf("Please input:\n");
	while((c=getchar())!=EOF)
	{
	if(c>=65&&c<=90)
	i++;
	else if(c>=97&&c<=122)
	j++;
	}
	printf("dxzm=%d,xxzm=%d.\n",i,j);
	return 0;
}