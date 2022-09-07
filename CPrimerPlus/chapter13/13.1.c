#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char file_name[40];
	char ch;
	FILE *fp;
	long count=0;

	printf("请输入文件名:\n");
	gets(file_name);
	if((fp=fopen(file_name,"r+"))==NULL)
	{
		printf("Can't open %s\n",file_name);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		count++;
	}
	printf("\n");
	fclose(fp);
	printf("File %s has %ld characters\n",file_name,count);
	getchar();
	return 0;
}
