/**
 * @file ex10.c
 * @author your name (you@domain.com)
 * @brief
 *   The 1988 United States Federal Tax Schedule was the simplest in recent times. It had four categories, and each category had two rates. Here is a summary (dollar amounts are taxable income):
  Category     				Tax
  Single		 			15% of first $17,850 plus 28% of excess
   Head of Household 		 15% of first $23,900 plus 28% of excess
    Married, Joint  		 15% of first $29,750 plus 28% of excess
    Married, Separate 		15% of first $14,875 plus 28% of excess
     For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850 + 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category and the taxable income and that then calculates the tax. Use a loop so that the user can enter several tax cases.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define SINGLE 17850
#define MARRIED 29750
#define DIVORCED 14875
#define HOUSEHOLDER 23900
#define NORMAL_RATE 0.15
#define BEYOND_RATE 0.28
//根据薪金和税收的范围计算税金
double taxfunc(int bound, double salary);

int menu()
{
    int kind;
    printf("Enter your kind in range [1,4] (other to quit):\n"
           "1.Single\t\t\t\t15%% of first $17,850 plus 28%% of excess\n"
           "2.Head of Household\t\t\t15%% of first $23,900 plus 28%% of excess\n"
           "3.Married, Joint\t\t\t15%% of first $29,750 plus 28%% of excess\n"
           "4.Married, Separate\t\t\t15%% of first $14,875 plus 28%% of excess\n");
    if (scanf("%d", &kind) > 0)
    {
        return kind;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int kind;
    while ((kind = menu()) && kind > 0 && kind < 5)
    {
        double salary;
        printf("Please input your salary:");
        if (scanf("%lf", &salary) < 0)
            return -1;
        switch (kind)
        {
        case 1:
            printf("your tax is %.2f\n", taxfunc(SINGLE, salary));
            break;
        case 2:
            printf("your tax is %.2f\n", taxfunc(HOUSEHOLDER, salary));
            break;
        case 3:
            printf("your tax is %.2f\n", taxfunc(MARRIED, salary));
            break;
        case 4:
            printf("your tax is %.2f\n", taxfunc(DIVORCED, salary));
            break;
        }
    }
    return 0;
}

double taxfunc(int bound, double salary)
{
    if (salary > bound)
        return (salary - bound) * BEYOND_RATE + bound * NORMAL_RATE;
    else
        return salary * NORMAL_RATE;
}