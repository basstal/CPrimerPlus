/**
编写程序，要求输入一周中的工作小时数，然后打印工资总额、税金以及净工资，作如下假设：
a.基本工资等级=10.00美元/小时
b.加班（超过40小时）=1.5倍的时间
c.税率	前300美元为15%
		下一个150美元为20%
		余下的为25%
*/
#include	<stdio.h>
double salaryfunc(int);
double taxfunc(double);

int main(void)
{
	int workhours;

	printf("Please input the workhours:");
	while( scanf("%d", &workhours) > 0 && workhours > 0)
	{
		double salary,tax,net_salary;
		salary = tax = net_salary = 0;

		salary = salaryfunc(workhours);
		tax = taxfunc(salary);
		net_salary = salary - tax;
		printf("salary = %.2f, tax = %.2f , net_salary = %.2f\n", salary,tax,net_salary);
		printf("Please input another workhours:");
	}

	return 0;
}

double salaryfunc(int workhours)
{
	if(workhours > 40)
		return (1.5 * workhours - 20) * 10;
	else
		return workhours * 10;
}
double taxfunc(double salary)
{
	if(salary <= 300)
		return salary * 0.15;
	else if(salary <= 450)
		return 45 + (salary - 300) * 0.2;
	else
		return 75 + (salary - 450) * 0.25;
}