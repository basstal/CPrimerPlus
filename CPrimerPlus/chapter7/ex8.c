/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *  Modify assumption a. in exercise 7 so that the program presents a menu of pay rate
 * from which to choose. Use a  switch  to select the pay rate. The beginning of a run should look something like this:
  *****************************************************************
  Enter the number corresponding to the desired pay rate or action:
    1) $8.75/hr			2) $9.33/hr
    3) $10.00/hr		4) $11.20/hr
    5) quit
  *****************************************************************
 If choices 1 through 4 are selected, the program should request the hours worked. The program should recycle until 5 is entered. If something other than choices 1 through 5 is entered, the program should remind the user what the proper choices are and then recycle. Use  #defined  constants for the various earning rates and tax rates.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define OVERTIME_WORK_HOURS 40
#define OVERTIME_PAY_RATE 15
#define TAX_RATE_LEVEL0 0.15
#define TAX_RATE_LEVEL1 0.2
#define TAX_RATE_LEVEL2 0.25
#define TAX_RATE_LEVEL0_AMOUNT 30
#define TAX_RATE_LEVEL1_AMOUNT 150

double salaryfunc(int, double);
double taxfunc(double);
int menu();
double select_pay_rate(int);

int main(void)
{

    int select;
    while ((select = menu()) != 5)
    {
        int workhours;
        printf("Please input the workhours:");
        if (scanf("%d", &workhours) < 0)
            return -1;
        double salary, tax, net_salary;
        salary = tax = net_salary = 0;

        salary = salaryfunc(workhours, select_pay_rate(select));
        tax = taxfunc(salary);
        net_salary = salary - tax;
        printf("salary = %.2f, tax = %.2f, net_salary = %.2f\n", salary, tax, net_salary);
    }

    return 0;
}

double salaryfunc(int workhours, double pay_rate)
{
    if (workhours > OVERTIME_WORK_HOURS)
        return OVERTIME_WORK_HOURS * pay_rate + (workhours - OVERTIME_WORK_HOURS) * OVERTIME_PAY_RATE;
    else
        return workhours * pay_rate;
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

int menu()
{
    for (;;)
    {
        printf("*****************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "1) $8.75/hr 			2) $9.33/hr\n"
               "3) $10.00/hr			4) $11.20/hr\n"
               "5) quit\n"
               "*****************************************\n");
        int input;
        if (scanf("%d", &input) == 1 && input > 0 && input < 6)
            return input;
        else
        {
            printf("Input error, please try again!\n");
            while (getchar() != '\n')
                ;
        }
    }
}

double select_pay_rate(int select)
{
    switch (select)
    {
    case 1:
        return 8.75;
    case 2:
        return 9.33;
    case 3:
        return 10.00;
    case 4:
        return 11.2;
    }
}