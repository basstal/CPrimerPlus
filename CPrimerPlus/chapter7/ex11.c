/**
 * @file ex11.c
 * @author your name (you@domain.com)
 * @brief
 * The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or more prior to adding shipping costs. It charges $6.50 shipping and handling for any order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or more. Write a program that uses a  switch  statement in a loop such that a response of  a lets the user enter the pounds of  artichokes desired,  b  the pounds of beets,  c  the pounds of carrots, and  q  allows the user to exit the ordering process. The program should keep track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters 5 pounds of beets, the program should use report 9 pounds of beets. The program then should compute the total charges, the discount, if any, the shipping charges, and the grand total. The program then should display all the purchase information: the cost per pound, the pounds ordered, and the cost for that order for each vegetable, the total cost  of the order, the discount (if there is one), the shipping charge, and the grand total of all the charges.
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <ctype.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT_LIMIT 100
#define DISCOUNT_RATE 0.05
#define FREIGHT_FEE1 6.50
#define FREIGHT_LIMIT1 5
#define FREIGHT_FEE2 14.00
#define FREIGHT_LIMIT2 20
#define FREIGHT_PER_POUND_OVER_LIMIT2 0.5

char menu(char last_selection)
{
    printf("Please select your vegetable: a,b,c,q\n"
           "a.artichoke price:$%.2f\n"
           "b.beet price:$%.2f\n"
           "c.carrot price:$%.2f\n"
           "q.end\n"
           "(price as dollars per pound)\n",
           ARTICHOKE, BEET, CARROT);
    if (last_selection != NULL)
    {
        char result;
        while ((result = getchar()) == '\n')
            ;
        return tolower(result);
    }
    return tolower(getchar());
}
int main(void)
{
    char ch = NULL;
    double artichoke = 0, beet = 0, carrot = 0;
    double sum, discount, freight;

    while ((ch = menu(ch)) != 'q')
    {
        switch (ch)
        {
        case 'a':
            printf("How many pounds of artichokes do you want?");
            double tmp_artichoke;
            if (scanf("%lf", &tmp_artichoke) < 0)
                return -1;
            artichoke += tmp_artichoke;
            break;
        case 'b':
            printf("How many pounds of beets do you want?");
            double tmp_beet;
            if (scanf("%lf", &tmp_beet) < 0)
                return -1;
            beet += tmp_beet;
            break;
        case 'c':
            printf("How many pounds of carrots do you want?");
            double tmp_carrot;
            if (scanf("%lf", &tmp_carrot) < 0)
                return -1;
            carrot += tmp_carrot;
            break;
        default:
            break;
        }
    }
    printf("%10s%10s%10s%10s\n", " ", "artichoke", "beet", "carrot");
    printf("%10s%10.2lf%10.2lf%10.2lf\n", "price", ARTICHOKE, BEET, CARROT);
    printf("%10s%10.2lf%10.2lf%10.2lf\n", "pound", artichoke, beet, carrot);
    printf("%10s%10.2lf%10.2lf%10.2lf\n", "charge", ARTICHOKE * artichoke, BEET * beet, CARROT * carrot);
    sum = ARTICHOKE * artichoke + BEET * beet + CARROT * carrot;
    if (sum > DISCOUNT_LIMIT)
    {
        printf("%10s%10.2lf%10.2lf%10.2lf\n", "discount", ARTICHOKE * artichoke * DISCOUNT_RATE, BEET * beet * DISCOUNT_RATE, CARROT * carrot * DISCOUNT_RATE);
        discount = ARTICHOKE * artichoke * DISCOUNT_RATE + BEET * beet * DISCOUNT_RATE + CARROT * carrot * DISCOUNT_RATE;
    }
    else
    {
        printf("%10s%10.2lf%10.2lf%10.2lf\n", "discount", 0.0, 0.0, 0.0);
        discount = 0;
    }
    if (artichoke + beet + carrot <= FREIGHT_LIMIT1)
        freight = FREIGHT_FEE1;
    else if (artichoke + beet + carrot < FREIGHT_LIMIT2)
        freight = FREIGHT_FEE2;
    else
        freight = FREIGHT_FEE2 + (artichoke + beet + carrot - FREIGHT_LIMIT2) * FREIGHT_PER_POUND_OVER_LIMIT2;
    printf("shipping charges: %.2f\n", freight);
    sum = sum - discount + freight;
    printf("grand total: %.2f\n", sum);
    return 0;
}
