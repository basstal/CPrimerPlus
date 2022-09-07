/**
用switch重做练习3
*/
#include	<stdio.h>
int main(void)
{
	int i;
	int odd,even;
	double oddsum,evensum;

	odd = even = oddsum = evensum = 0;

	printf("Enter integer (0 to quit):");
	while( scanf("%d", &i) > 0 && i != 0)
	{
		switch(i % 2)
		{
			case 0:
				++even;
				evensum += i;
				break;
			case 1:
				++odd;
				oddsum += i;
				break;
		}
	}
	printf("odd numbers = %d , even numbers = %d\n",odd , even);
	printf("odd avg = %.2f , even avg = %.2f\n",oddsum / odd , evensum / even);

	return 0;
}