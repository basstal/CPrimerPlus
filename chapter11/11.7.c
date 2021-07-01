#include<stdio.h>
char *string_in(char *,char *);
int main(void)
{
	char ch1[40],ch2[40];
	char *rt;

	printf("Enter string #1:\n");
	while(gets(ch1)&&ch1[0]!='\0')
	{
		printf("Enter string #2:\n");
		gets(ch2);
		printf("Let's find out!\n");
		rt=string_in(ch1,ch2);
		if(rt==NULL)
			printf("×Ö·û´®Î´ÕÒµ½\n");
		else
			printf("The return address is %p.\n",rt);
		printf("Enter string #1(ÊäÈë»»ĞĞ·ûÍË³ö):\n");
	}
	return 0;
}
char *string_in(char *target,char *source)
{
	int i=0,j=0;
	
	while(*(target+i))
	{
		if(*(target+i)==*source)
		{
			while(*(source+j))
				if(*(target+i+j)==*(source+j))
				{
					j++;
					continue;
				}
				else
				{
					j=0;
					goto end;
				}
			return (target+i);
		}
end:i++;
	}
	return NULL;
}


