#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char showmenu(void);
void fixlibrary(struct book *plib);
void dellibrary(struct book *plib,int count,int *pi);

int main(void)
{
	int count=0,i=0,pos;
	char choice;
	struct book library[MAXBKS];
	int del[MAXBKS]={0};
	FILE *fp;
	int size=sizeof(struct book);


	if((fp=fopen("library.dat","r+b"))==NULL){
		fputs("Can't open library.dat file\n",stderr);
		exit(1);
	}

	while(count<MAXBKS && fread(&library[count],size,1,fp)==1){
		printf("%s written by %s : $%g\n",library[count].title,library[count].author,library[count].value);
		choice=showmenu();
		switch(choice)
		{
		case 'f':fixlibrary(&library[count]);
			break;
		case 'd':dellibrary(&library[count],count,del);
		case 'n':break;
		}
		count++;
	}

	while(count<MAXBKS){
		printf("����������(������н���)\n");
		if(del[i]!=0){
			pos=del[i-1];
			del[i++]=0;
		}
		else
			pos=count;
		if(gets(library[pos].title)==NULL||library[pos].title[0]=='\0')
			break;
		printf("����������\n");
		gets(library[pos].author);
		printf("�����뱾��۸�:");
		scanf("%f",&library[pos].value);
		while(getchar()!='\n')continue;
		count++;
	}

	rewind(fp);
	if(count>0)
		fwrite(&library[0],size,count,fp);
	else
		printf("û����?̫��ϧ��.\n");
	
	puts("bye\n");
	fclose(fp);
	return 0;
}

char showmenu(void)
{
	char ch;
	printf("�������ַ���Ӧѡ��:f)�޸�   d)ɾ��  n)������\n");
	ch=tolower(getchar());
	while(ch!='\n' && getchar()!='\n')continue;
	while(strchr("fdn",ch)==NULL){
		printf("�������Ӧ�ַ�:f)�޸�   d)ɾ��  n)������\n");
		ch=tolower(getchar());
		while(ch!='\n' && getchar()!='\n')continue;
	}
	return ch;
}

void fixlibrary(struct book *plib)
{
	printf("����Ϊ�޸�����\n����������:\n");
	gets(plib->title);
	printf("����������:");
	gets(plib->author);
	printf("�����뱾��۸�:");
	scanf("%f",plib->value);
	while(getchar()!='\n')continue;
}

void dellibrary(struct book *plib,int count,int *pi)
{
	static int i=0;
	pi[i++]=count+1;
	strcpy(plib->title,'\0');
	strcpy(plib->author,'\0');
	plib->value=0;
}









