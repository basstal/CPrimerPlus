/**
exercise 6:
一个水分子的质量约为3.0e-23g,1夸脱水大约有950g。编写一个程序，要求输入水的夸脱数，然后显示这么多水中包含多少个水分子
*/

#include	<stdio.h>
int main()
{
	float quarts;

	printf("Please input quarts of water:\n");
	if(scanf("%f",&quarts) < 0)
		return -1;
	printf("There are %e water molecules in %f quarts of water\n", quarts * 950 / 3.0e-23,quarts);

	return 0;
}