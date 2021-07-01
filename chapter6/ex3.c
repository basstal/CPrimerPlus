/**
使用嵌套循环产生下列图案：
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
#include	<stdio.h>

int main(void)
{
	for(char ed = 'F' ; ed >= 'A' ; --ed)
	{
		for(char c = 'F' ; c >= ed ; --c)
			printf("%c",c);
		printf("\n");
	}

	return 0;
}