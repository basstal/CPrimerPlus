/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests the hours worked in a week and then prints the gross pay, the taxes, and the net pay. Assume the following:
a.	   Basic pay rate = $10.00/hr
b.	   Overtime (in excess of 40 hours) = time and a half
c.	   Tax rate: #15% of the first $30
20% of the next $150
 25% of the rest
 Use  #define  constants, and don’t worry if the example does not conform to current tax law.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
double salaryfunc(int);
double taxfunc(double);
#define BASIC_PAY_RATE 10
#define OVERTIME_WORK_HOURS 40
#define OVERTIME_PAY_RATE 15
#define TAX_RATE_LEVEL0 0.15
#define TAX_RATE_LEVEL1 0.2
#define TAX_RATE_LEVEL2 0.25
#define TAX_RATE_LEVEL0_AMOUNT 30
#define TAX_RATE_LEVEL1_AMOUNT 150

int main(void)
{
    int workhours;

    printf("Please input the workhours:");
    while (scanf("%d", &workhours) > 0 && workhours > 0)
    {
        double salary, tax, net_salary;
        salary = tax = net_salary = 0;

        salary = salaryfunc(workhours);
        tax = taxfunc(salary);
        net_salary = salary - tax;
        printf("salary = %.2f, tax = %.2f , net_salary = %.2f\n", salary, tax, net_salary);
        printf("Please input another workhours (0 to quit):");
    }

    return 0;
}

double salaryfunc(int workhours)
{
    if (workhours > OVERTIME_WORK_HOURS)
        return OVERTIME_WORK_HOURS * BASIC_PAY_RATE + (workhours - OVERTIME_WORK_HOURS) * OVERTIME_PAY_RATE;
    else
        return workhours * BASIC_PAY_RATE;
}
double taxfunc(double salary)
{
    if (salary <= TAX_RATE_LEVEL0_AMOUNT)
        return salary * TAX_RATE_LEVEL0;
    else if (salary <= TAX_RATE_LEVEL0_AMOUNT + TAX_RATE_LEVEL1_AMOUNT)
        return TAX_RATE_LEVEL0_AMOUNT * TAX_RATE_LEVEL0 + (salary - TAX_RATE_LEVEL0_AMOUNT) * TAX_RATE_LEVEL1;
    else
        return TAX_RATE_LEVEL0_AMOUNT * TAX_RATE_LEVEL0 + TAX_RATE_LEVEL1_AMOUNT * TAX_RATE_LEVEL1 + (salary - TAX_RATE_LEVEL0_AMOUNT - TAX_RATE_LEVEL1_AMOUNT) * TAX_RATE_LEVEL2;
}