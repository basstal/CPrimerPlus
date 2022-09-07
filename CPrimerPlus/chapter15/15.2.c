#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MASK 1

int transform1(char pc[]);
void print(int num1,int num2,int,int);
char * transform2(int num,int);

int main(int argc,char *argv[])
{
	int num1,num2;
	int strl1,strl2;
	
	if(argc<3){
		fprintf(stderr,"参数个数错误");
		exit(1);
	}
	strl1=strlen(argv[1]);
	strl2=strlen(argv[2]);

	num1=transform1(argv[1]);
	num2=transform1(argv[2]);
	print(num1,num2,strl1,strl2);

	return 0;
}

int transform1(char pc[])
{
	int num;
	int i=0;

	while(pc[i]){
		if(pc[i]=='0')
			num<<=1;
		else{
			num |=MASK;
			if(pc[i+1])
				num<<=1;
		}
		i++;
	}
	return num;
}

char * transform2(int num,int strl)
{
	static char ch[40];
	int i=strl;

	ch[i]='\0';
	while(--i>=0){
		if(num & MASK==1)
			ch[i]='1';
		else
			ch[i]='0';
		num>>=1;
	}

	return ch;
}

void print(int num1,int num2,int strl1,int strl2)
{
	char * ch;

	printf("原始二进制字符串#1为:\n");
	ch=transform2(num1,strl1);
	printf("%s\n",ch);
	printf("原始二进制字符串#2为:\n");
	ch=transform2(num2,strl2);
	printf("%s\n",ch);
	printf("对二进制字符串#1使用~运算符后为:\n");
	ch=transform2(~num1,strl1);
	printf("%s\n",ch);
	printf("对二进制字符串#2使用~运算符后为:\n");
	ch=transform2(~num2,strl2);
	printf("%s\n",ch);
	printf("使用&运算符后结果为:\n");
	ch=transform2(num1&num2,strl1>strl2?strl1:strl2);
	printf("%s\n",ch);
	printf("使用|运算符后结果为:\n");
	ch=transform2(num1|num2,strl1>strl2?strl1:strl2);
	printf("%s\n",ch);
	printf("使用^运算符后结果为:\n");
	ch=transform2(num1^num2,strl1>strl2?strl1:strl2);
	printf("%s\n",ch);
	printf("bye\n");
}
	


	


