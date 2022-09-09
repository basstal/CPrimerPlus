/**
 * @file ex7.c
 * @author your name (you@domain.com)
 * @brief
 *  Modify Programming Exercise 8 from  Chapter   7    so that the menu choices are labeled by characters instead of by numbers; use  q  instead of  5  as the cue to terminate input.
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
char menu();
double select_pay_rate(char);
void clear()
{
    while (getchar() != '\n')
        ;
}

int main(void)
{

    char select;
    while ((select = menu()) != 'q')
    {
        int workhours;
        printf("Please input the workhours:");
        if (scanf("%d", &workhours) < 0)
            return -1;
        clear();
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

char menu()
{
    for (;;)
    {
        printf("*****************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "a) $8.75/hr 			b) $9.33/hr\n"
               "c) $10.00/hr			d) $11.20/hr\n"
               "q) quit\n"
               "*****************************************\n");
        char input;
        if (scanf("%c", &input) == 1 && ((input >= 'a' && input < 'e') || input == 'q'))
            return input;
        else
        {
            printf("Input error, please try again!\n");
            clear();
        }
    }
}

double select_pay_rate(char select)
{
    switch (select)
    {
    case 'a':
        return 8.75;
    case 'b':
        return 9.33;
    case 'c':
        return 10.00;
    case 'd':
        return 11.2;
    }
}
