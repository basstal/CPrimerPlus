/**
编写一个程序把8个整数读入一个数组中，然后以相反的顺序打印它们。
*/
#include  <stdio.h>
int main(void)
{
	int arr[8];

	printf("Please input 8 integers:\n");
	for(int i = 0 ; i < 8 ; ++i)
		if(scanf(" %d",&arr[i]) < 0)
			return -1;
	printf("Here, in reverse order, are the values you entered:\n");
	for(int i = 7 ; i >= 0 ; --i)
		printf(" %d",arr[i]);
	printf("\n");
	return 0;
}
