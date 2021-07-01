/**
Daphne以10%的单利息投资了100美元，Deirdre则以每年5%的复合利息投资了100美元。编写一个程序，计算需要多少年Deirdre的投资额才会超过Daphne，并且显示出到那时两个人的投资额。
*/
#include	<stdio.h>

int main()
{
	double daphne = 100;
	double deidre = 100;
	int years = 0;

	while (deidre <= daphne)
	{
		daphne += 10;
		deidre += 0.05 * deidre;
		++years;
	}

	printf("Investment values after %d years:\n", years);
	printf("Daphne: $%.2f\n", daphne);
	printf("Deidre: $%.2f\n", deidre);

	return 0;
}