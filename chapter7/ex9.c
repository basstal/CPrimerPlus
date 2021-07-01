/**
编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。
*/
#include	<stdio.h>

int main(void)
{
	int upper;
	printf("Please input an integer(enter q to quit):");
	while( scanf("%dd",&upper) == 1 && upper > 0)
	{
		for(int n = 2; n < upper; ++n)
		{
			int is_prime = 1;
			for(int div = 2 ; (div * div) <= n; ++div)
				if(n % div == 0)
					is_prime = 0;
			if(is_prime == 1)
				printf("%d is is_prime.\n", n);
		}
		printf("Please input another integer(Enter q to quit):");
	}

	return 0;
}
