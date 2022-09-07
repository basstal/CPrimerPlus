/**
考虑这两个无限序列：
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...

编写一个程序来计算这两个序列不断变化的总和，直到达到某个次数。让用户交互地输入这个次数。看看在20次、100次和500次之后的总和。是否每个序列都看上去要收敛于某个值？
*/
#include	<stdio.h>
int main(void)
{
	int times;
	printf("Please input the times:");
	while( scanf("%d",&times) > 0 && times > 0)
	{
		double sqa = 0;
		double sqb = 0;

		for( int i = 1 ; i <= times ; ++i)
		{
			sqa += 1.0 / i;
			if( i % 2 == 0)
				sqb -= 1.0 / i;
			else
				sqb += 1.0 / i;
		}
		printf("squence a in %d times values : %.2g\n",times,sqa);
		printf("squence b in %d times values : %.2g\n",times,sqb);
	}

	return 0;
}
