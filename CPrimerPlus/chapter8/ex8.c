/**
 * @file ex8.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that shows you a menu offering you the choice of addition, subtraction, multiplication, or division. After getting your choice, the program asks for two numbers, then performs the requested operation. The program should accept only the offered menu choices. It should use type  float  for the numbers and allow the user to try again if he or she fails to enter a number. In the case of division, the program should prompt the user to enter a new value if  0  is entered as the value for the second number. A typical program run should look like this:
 *   Enter the operation of your choice:
 *   a. add         s. subtract
 *   m. multiply    d. divide
 *   q.	quit
   a
  Enter first number:  22 .4
  Enter second number:  one
  one is not an number.
  Please enter a number, such as 2.5, -1.78E8, or 3:  1   
  22.4 + 1 = 23.4
  Enter the operation of your choice:
    a.add           s.	subtract
    m. multiply     d. divide
    q.	quit
   d
  Enter first number:  18.4
  Enter second number:  0
  Enter a number other than 0:  0.2   
  18.4 / 0.2 = 92
  Enter the operation of your choice:
    a.add           s.	subtract
    m. multiply     d. divide
    q.	quit
    q
  Bye.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>

float get_float(void);
char get_first(void);

int main(void)
{
    char operation;
    float operand1, operand2;
    while (1)
    {
        printf("Enter the operation of your choice:\n"
               "a.add               s.subtract:\n"
               "m.multiply          d.divide\n"
               "q.quit\n");
        operation = get_first();
        if (operation == 'q')
        {
            printf("Bye.\n");
            break;
        }
        printf("Enter first number:");
        operand1 = get_float();
        printf("Enter second number:");
        operand2 = get_float();
        while (operation == 'd' && operand2 == 0)
        {
            printf("Enter a number other than 0:");
            operand2 = get_float();
        }
        switch (operation)
        {
        case 'a':
            printf("%.2f + %.2f = %.2f\n", operand1, operand2, operand1 + operand2);
            break;
        case 's':
            printf("%.2f - %.2f = %.2f\n", operand1, operand2, operand1 - operand2);
            break;
        case 'm':
            printf("%.2f * %.2f = %.2f\n", operand1, operand2, operand1 * operand2);
            break;
        case 'd':
            printf("%.2f / %.2f = %.2f\n", operand1, operand2, operand1 / operand2);
            break;
        default:
            break;
        }
    }
    return 0;
}
float get_float(void)
{
    float num;
    char str[40];
    while (scanf("%f", &num) != 1)
    {
        gets(str);
        printf("%s is not a number.\n", str);
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
    }
    while (getchar() != '\n')
        ;
    return num;
}
char get_first(void)
{
    int ch;
    while (isspace(ch = getchar()))
        ;
    while (getchar() != '\n')
        ;
    return ch;
}
