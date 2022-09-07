/**
编写一个程序把一个单词读入一个字符数组，然后反向打印出这个词。
*/
#include  <stdio.h>
#include  <string.h>
int main(void)
{
	char word[40];

	printf("Please input single word:");
	if(scanf("%s",word) < 0)
		return -1;
	
	for( int i = strlen(word)-1 ; i >= 0 ; --i)
		printf("%c",word[i]);
	printf("\n");

	return 0;
}