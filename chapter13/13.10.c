#include<stdio.h>
int main(void)
{
    char fname[40];
	FILE *fp;
	int place,i;
	char ch;

    i=0;
	printf("�������ļ���:\n");
	gets(fname);

	fp=fopen(fname,"r");
    printf("�����������ִ�����ļ�λ�ã�����������˳���:");
	while(scanf("%d",&place))
	{
		while((ch=fgetc(fp))!=EOF&&i++<place);
		while((ch=fgetc(fp))!=EOF&&ch!='\n')
			fputc(ch,stdout);
		printf("\n");
		printf("�����������ִ�����ļ�λ�ã�����������˳���:");
		rewind(fp);
		i=0;
	}
	fclose(fp);
	return 0;
}

