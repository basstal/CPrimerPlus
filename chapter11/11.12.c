#include<stdio.h>
int main(int argc,char *argv[])
{
	int i;

	i=argc;
	printf("�����в�����%d��.\n",argc);
	printf("�������෴˳����������в���:\n");
	for(;i>0;i--)
		printf("%s ",argv[i]);
	return 0;
}