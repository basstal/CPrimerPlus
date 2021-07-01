/**
exercise 4:
编写一个程序，要求输入身高（以英寸为单位）和名字，然后以下列形式显示：
Dabney,you are 6.208 feet tall
*/
#include	<stdio.h>

int main()
{
	float inches;
	char name[40];

	printf("Please input your height in inches:");
	if(scanf("%f",&inches) < 0)
		return -1;
	printf("Enter your name:");
	if(scanf("%s",name) < 0)
		return -1;
	printf("%s,you are %.3f feet tall\n",name,inches / 12);

	return 0;
}