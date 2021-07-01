#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
	char source[40],target[40];
	FILE *fps,*fpt;
	char ch;
	
	printf("输入源文件名:\n");
	gets(source);
	printf("输入目标文件名:\n");
	gets(target);
	fps=fopen(source,"r");
	fpt=fopen(target,"w");

	while((ch=getc(fps))!=EOF)
	{
		ch=toupper(ch);
		putc(ch,fpt);
	}
	fclose(fps);
	fclose(fpt);
	return 0;
}
	
