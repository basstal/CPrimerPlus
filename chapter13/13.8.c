#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int i=2;
	FILE *fp;
	int count=0;
	char ch;
	
	if(argc<2)
	{
		printf("ȱ�������в���");
		exit(0);
	}
	else if(argc<3)
	{
		fp=stdin;
		printf("�Ա�׼������ʽ�����ļ�����:\n");
		while((ch=getchar())!=EOF)
			if(argv[1][0]==ch)
				count++;
		printf("%c����Ļ�ϳ��ִ���Ϊ%d��.\n",argv[1][0],count);
	}
	else 
		while(i<argc)
		{
			if((fp=fopen(argv[i],"r"))==NULL)
			{
				fprintf(stderr,"�ļ��޷���,������һ���ļ�\n");
				i++;
				continue;
			}
			while((ch=fgetc(fp))!=EOF)
				if(argv[1][0]==ch)
					count++;
			printf("%c���ļ�%s���ִ���Ϊ%d��.\n",argv[1][0],argv[i],count);
			fclose(fp);
			i++;
			count=0;
		}
	return 0;
}




