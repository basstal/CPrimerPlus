/**
编写一个程序，创建一个8个元素的int数组，并且把元素分别设置为2的前8次幂，然后打印出它们的值。使用for循环来设置值；为了变化，使用do while循环来显示这些值。
*/
#include	<stdio.h>

int main(void)
{
	int arr[8];
	arr[0] = 2;
	for(int i = 1; i < 8; ++i)
		arr[i] = arr[i-1] * 2;
	int i = 0;
	do
	{
		printf("%d ",arr[i++]);
	}while(i < 8);
	printf("\n");
	
	return 0;
}