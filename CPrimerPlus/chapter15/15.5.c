/**
 * @file 15.5.c
 * @author your name (you@domain.com)
 * @brief
 * Write a function that rotates the bits of an unsigned int by a specified number of bits
to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
and the bits lost from the left end would reappear at the right end. That is, the bit moved
out of the high-order position is placed in the low-order position. Test the function in a
program.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <limits.h>

unsigned int rotate(unsigned int num, unsigned int move);

int main(void)
{
    unsigned int num, move;

    printf("Please input the unsigned int to be rotate : ");
    scanf("%u", &num);
    printf("Please input the rotate value : ");
    scanf("%u", &move);
    printf("The result of rotate(%u, %u) is %u\n", num, move, rotate(num, move));

    return 0;
}

unsigned int rotate(unsigned int num, unsigned int move)
{
    if (move > 0)
    {
        unsigned int low = (num & ~(UINT_MAX >> 1)) != 0 ? 1 : 0;
        num <<= 1;
        num |= low;
        return rotate(num, move - 1);
    }
    return num;
}
