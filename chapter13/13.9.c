#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
{
	FILE *fp;
	char words[MAX];
	int line=1;

	if((fp=fopen("words.txt","a+"))==NULL)
	{
		fprintf(stdout,"Can't open \"words\" file.\n");
		exit(1);
	}
	puts("Enter words to add to the file:press the Enter");
	puts("key at the beginning of a line to terminate.");
	while(fgets(words,MAX,fp)!=NULL)
		line++;
	while(gets(words)!=NULL&&words[0]!='\0')
	{
		fprintf(fp,"%d.",line);
		fprintf(fp,"%s \n",words);
		line++;
	}
	puts("File contents:");
	rewind(fp);
	while(fscanf(fp,"%s",words)==1)
		puts(words);
	if(fclose(fp)!=0)
		fprintf(stderr,"Error closing file\n");
	return 0;
}