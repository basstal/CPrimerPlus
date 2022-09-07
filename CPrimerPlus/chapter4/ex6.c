/**
 * @file ex6.c
 * @author your name (you@domain.com)
 * @brief
 *   Write a program that requests the user’s first name and then the user’s last name. Have it print the entered names on one line and the number of letters in each name on the following line. Align each letter count with the end of the corresponding name, as in the following:
  Melissa Honeybee
		7		8
Next, have it print the same information, but with the counts aligned with the beginning of each name.
  Melissa Honeybee
  7       8
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char fstnm[40], lstnm[40];

	printf("Please input your first name(less than 40 letters):");
	if (scanf("%s", fstnm) < 0)
		return -1;
	printf("Please input your last name(less than 40 letters):");
	if (scanf("%s", lstnm) < 0)
		return -1;

	int fstlen, lstlen;
	fstlen = (int)strlen(fstnm);
	lstlen = (int)strlen(lstnm);
	printf("%s %s\n", fstnm, lstnm);
	printf("%*d %*d\n", fstlen, fstlen, lstlen, lstlen);
	printf("%s %s\n", fstnm, lstnm);
	printf("%-*d %-*d\n", fstlen, fstlen, lstlen, lstlen);

	return 0;
}
