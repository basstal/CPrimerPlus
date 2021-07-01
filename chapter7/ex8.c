/**
修改练习7中的假设a,使程序提供一个选择工资等级的菜单。用switch选择工资等级。程序运行开头应该像这样：
*****************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr 			2) $9.33/hr
3) $10.00/hr			4) $11.20/hr
5) quit
*****************************************
如果选择1到4，那么程序应该请求输入工作小时数。程序应该一直循环运行，直到输入5.如果输入1到5以外的选项，那么程序应该提醒用户合适的选项是哪些，然后再循环。
*/
#include	<stdio.h>
#define SALARY1 8.75
#define SALARY2 9.33
#define SALARY3 10.00
#define SALARY4 11.2
#define NORMAL_RATE 0.15
#define NEXT_RATE 0.2
#define UPPER_RATE 0.25
#define NORMAL_TAX 300
#define NEXT_TAX 450
#define OVERWORK_RATE 1.5
#define OVERWORK_BOUND 40

//根据工作小时和时薪计算薪水
double salaryfunc(int,double);
//根据薪水计算税金
double taxfunc(double);
//显示菜单栏
int menu();
//根据选项返回时薪
double select(int);

int main(void)
{

	int slct;
	while( (slct = menu()) != 5)
	{
		double slr_per_hr = select(slct);
		int  workhours;
		printf("Please input the workhours:");
		if( scanf("%d",&workhours) < 0)
			return -1;
		double salary,tax,net_salary;
		salary = tax = net_salary = 0;

		salary = salaryfunc(workhours, slr_per_hr);
		tax = taxfunc(salary);
		net_salary = salary - tax;
		printf("salary = %.2f, tax = %.2f , net_salary = %.2f\n", salary,tax,net_salary);
	}

	return 0;
}

double salaryfunc(int workhours,double pay)
{
	if(workhours > OVERWORK_BOUND)
		return (OVERWORK_RATE * (workhours - OVERWORK_BOUND)) * pay + OVERWORK_BOUND * pay;
	else
		return workhours * pay;
}
double taxfunc(double salary)
{
	if(salary <= NORMAL_TAX)
		return salary * NORMAL_RATE;
	else if(salary <= NEXT_TAX)
		return NORMAL_TAX * NORMAL_RATE + (salary - NORMAL_TAX) * NEXT_RATE;
	else
		return NORMAL_TAX * NORMAL_RATE + (NEXT_TAX - NORMAL_TAX) * NEXT_RATE + (salary - NEXT_TAX) * UPPER_RATE;
}

int menu()
{
	for(;;)
	{
		printf("*****************************************\n\
Enter the number corresponding to the desired pay rate or action:\n\
1) $8.75/hr 			2) $9.33/hr\n\
3) $10.00/hr			4) $11.20/hr\n\
5) quit\n\
*****************************************\n");
		int input;
		if( scanf("%d",&input) == 1 && input > 0 && input < 6 )
			return input;
		else
		{
			printf("input error : please try again!\n");
			while(getchar() != '\n');
		}
	}
}

double select(int slct)
{
	switch(slct)
	{
		case 1:
			return SALARY1;
		case 2:
			return SALARY2;
		case 3:
			return SALARY3;
		case 4:
			return SALARY4;
		default:
			return -1;
	}
}