#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNAME 40
#define MAXSEAT 12
#define PLANE 4

typedef struct {
	char first[MAXNAME];
	char last[MAXNAME];
}Name;

typedef struct {
	int code;
	int flag;
	Name person;
}Seat;

int showplane(void);
char showmenu(void);
void swemptynum(const Seat pseat[]);
void swemptylist(const Seat pseat[]);
void swalllist(const Seat pseat[]);
void assignseat(Seat pseat[]);
void deleteseat(Seat pseat[]);
void getchoice(Seat planeseat[][MAXSEAT],int plane);

int main(void)
{
	int plane;
	Seat planeseat[PLANE][MAXSEAT];
	FILE *fp;
	int i,j;

	for(j=0;j<PLANE;j++)
		for(i=0;i<MAXSEAT;i++){
			planeseat[j][i].code=i+1;
			planeseat[j][i].flag=0;
			planeseat[j][i].person.first[0]='\0';
			planeseat[j][i].person.last[0]='\0';
		}//��ʼ���ṹ����
	while((plane=showplane())!=5){
		switch(plane)
		{
		case 1:
			plane=plane-1;
			if((fp=fopen("planeseat102.dat","r+b"))==NULL){
				printf("���ļ�����\n");
				exit(1);
			}
			if(fread(planeseat[plane],sizeof(Seat),MAXSEAT,fp)<MAXSEAT){
				printf("��ȡ�ļ�������ļ���������\n");
			}
			getchoice(planeseat,plane);
			break;
		case 2:
			plane=plane-1;
			if((fp=fopen("planeseat311.dat","r+b"))==NULL){
				printf("���ļ�����\n");
				exit(1);
			}
			if(fread(planeseat[plane],sizeof(Seat),MAXSEAT,fp)<MAXSEAT){
				printf("��ȡ�ļ�������ļ���������\n");
			}
			getchoice(planeseat,plane);
			break;
		case 3:
			plane=plane-1;
			if((fp=fopen("planeseat444.dat","r+b"))==NULL){
				printf("���ļ�����\n");
				exit(1);
			}
			if(fread(planeseat[plane],sizeof(Seat),MAXSEAT,fp)<MAXSEAT){
				printf("��ȡ�ļ�������ļ���������\n");
			}
			getchoice(planeseat,plane);
			break;
		case 4:
			plane=plane-1;
			if((fp=fopen("planeseat519.dat","r+b"))==NULL){
				printf("���ļ�����\n");
				exit(1);
			}
			if(fread(planeseat[plane],sizeof(Seat),MAXSEAT,fp)<MAXSEAT){
				printf("��ȡ�ļ�������ļ���������\n");
			}
			getchoice(planeseat,plane);
			break;
		}
	}
	for(j=0;j<PLANE;j++)
		if(fwrite(planeseat[j],sizeof(Seat),MAXSEAT,fp)<MAXSEAT){	
			printf("д���ļ�����\n");	
			exit(1);
		}
	puts("bye");
	return 0;
}

char showmenu(void)
{
	char ch;
	printf("\nTo choose a function, enter its letter label:\n"
		"a)Show number of empty seats\n"
		"b)Show list of empty seats\n"
		"c)Show alphabetical list of seats\n"
		"d)Assign a customer to a seat assignment\n"
		"e)Delete a seat assignment\n"
		"f)�ص�����ѡ��˵�\n");
	ch=tolower(getchar());
	while(ch!='\n' && getchar()!='\n')continue;
	while(strchr("abcdef",ch)==NULL){
		printf("������abcdef�Զ�Ӧ����ѡ��");
		ch=tolower(getchar());
		while(ch!='\n' && getchar()!='\n')continue;
	}
	return ch;
}

void swemptynum(const Seat pseat[])
{
	int i=0,count=0;
	while(i<MAXSEAT){
		if((pseat+i)->flag==0)
			count++;
		i++;
	}
	printf("�ܹ�����%d��������λ",count);
}

void swemptylist(const Seat pseat[])
{
	int i=0;
	printf("����Ϊ������λ����λ����:\n");
	while(i<MAXSEAT){
		if((pseat+i)->flag==0)
			printf(" %d",(pseat+i)->code);
		i++;
	}
}

void swalllist(const Seat pseat[])
{
	int i=0;
	printf("���   �Ƿ�ԤԼ   ԤԼ������\n");
	while(i<MAXSEAT){
		printf(" %-8d %-10s %-s %-s\n",(pseat+i)->code,(pseat+i)->flag==0?"No":"Yes",
			(pseat+i)->person.last,(pseat+i)->person.first);
		i++;
	}
}

void assignseat(Seat pseat[])
{
	int cd;
	printf("������������λ���(����������ַ��˳�):");
	while(scanf("%d",&cd)){
		while(getchar()!='\n')continue;
		if(cd<1 || cd>MAXSEAT){
			printf("����ֵ��1--%d֮��",MAXSEAT);
			continue;
		}
		if(pseat[cd-1].flag==1)
			printf("����λ�ѱ�Ԥ��\n");
		else{
			pseat[cd-1].flag=1;
			printf("������������\n");
			while(gets(pseat[cd-1].person.last)==NULL || pseat[cd-1].person.last[0]=='\0')
				printf("����������\n");
			printf("������������\n");
			while(gets(pseat[cd-1].person.first)==NULL || pseat[cd-1].person.first[0]=='\0')
				printf("����������\n");
			printf("��������:%s %s\n",pseat[cd-1].person.last,pseat[cd-1].person.first);
		}
		printf("������������λ���(����������ַ��˳�):");
	}
	while(getchar()!='\n')continue;
}

void deleteseat(Seat pseat[])
{
	int cd;
	printf("������������λ���(����������ַ��˳�):");
	while(scanf("%d",&cd)){
		while(getchar()!='\n')continue;
		if(cd<1 || cd>MAXSEAT){
			printf("����ֵ��1--%d֮��",MAXSEAT);
			continue;
		}
		if(pseat[cd-1].flag==0)
			printf("����λ����Ԥ��,�������.\n");
		else{
			pseat[cd-1].flag=0;
			pseat[cd-1].person.first[0]=pseat[cd-1].person.last[0]='\0';
			printf("�����#%d��λ��Ԥ��\n",pseat[cd-1].code);
		}
		printf("������������λ���(����������ַ��˳�):");
	}
	while(getchar()!='\n')continue;
}

int showplane(void)
{
	int plane;
	printf("��ѡ���Ӧ��ź���:\n"
		"1)����102   2)����311\n"
		"3)����444   4)����519\n"
		"5)�˳�����\n");
	while(scanf("%d",&plane)!=1)
		printf("����������1-5");
	while(plane<1 || plane>5){
		printf("�������ַ�Χ��1-5,����������");
		scanf("%d",&plane);
	}
	while(getchar()!='\n')continue;
	return plane;
}


void getchoice(Seat planeseat[][MAXSEAT],int plane)
{
    char choice;
	choice=showmenu();
	while(choice!='f'){
		switch(choice)	
		{
		case 'a':swemptynum(planeseat[plane]);
			break;
		case 'b':swemptylist(planeseat[plane]);
			break;
		case 'c':swalllist(planeseat[plane]);
			break;
		case 'd':assignseat(planeseat[plane]);
			break;
		case 'e':deleteseat(planeseat[plane]);
		}
		choice=showmenu();
	}
}


