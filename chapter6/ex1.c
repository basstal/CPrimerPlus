/**
编写一个程序，创建一个具有26个元素的数组，并在其中存储26个小写字母。并让该程序显示该数组的内容。
*/
#include	<stdio.h>

int main()
{
	char lcase[26];

	for (int i = 0; i < 26; i++)
		lcase[i] = 'a' + i;
	for (int i = 0; i < 26; i++)
		printf(" %c",lcase[i]);
	printf("\n");
	
	return 0;
}
