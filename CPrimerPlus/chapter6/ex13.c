/**
编写一个程序，创建两个8元素的double数组，使用一个循环来让用户键入第一个数组的8个元素的值。程序把第二个数组的元素设置为第一个数组元素的累积和。最后，使用一个循环来显示两个数组中的内容，第一个数组在一行中显示，而第二个数组中的每个元素在第一个数组的对应元素之下进行显示。
*/
#include	<stdio.h>

int main(void)
{
	double arr_a[8];
	double arr_b[8];

	printf("Please input 8 double numbers:\n");
	for(int i = 0; i < 8; ++i)
		if(scanf("%lf",&arr_a[i]) < 0)
			return -1;
	arr_b[0] = arr_a[0];
	for(int i = 1 ; i < 8; ++i)
		arr_b[i] = arr_b[i-1] + arr_a[i];

	//不知道怎么在一个循环中显示两个数组的内容，这里分两个循环显示
	for(int i = 0 ; i < 8 ; ++i)
		printf("%5.2g ",arr_a[i]);
	printf("\n");
	for(int i = 0 ; i < 8 ; ++i)
		printf("%5.2g ",arr_b[i]);
	printf("\n");

	return 0;
}