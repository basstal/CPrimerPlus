/**
exercise 5:
编写一个程序，首先要求用户输入名字，然后要求用户输入姓氏。在一行打印输入的姓名，在下一行打印每个名字中字母的个数。把字母个数与相应名字的结尾对齐，如下所示：
Melissa Honeybee
      7        8
然后打印相同的信息，但是字母个数与相应单词的开始对齐。
Melissa Honeybee
7       8

*/
#include  <stdio.h>
#include  <string.h>

int main()
{
	char fstnm[40],lstnm[40];

	printf("Please input your first name:");
	if(scanf("%s",fstnm) < 0)
		return -1;
	printf("Please input your last name:");
	if(scanf("%s",lstnm) < 0)
		return -1;

	int fstlen,lstlen;
	fstlen = strlen(fstnm);
	lstlen = strlen(lstnm);
	printf("%s %s\n",fstnm,lstnm);
	printf("%*d %*d\n",fstlen,fstlen,lstlen,lstlen);
	printf("%s %s\n",fstnm,lstnm);
	printf("%-*d %-*d\n",fstlen,fstlen,lstlen,lstlen);

	return 0;
}