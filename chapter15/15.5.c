#include<stdio.h>
#define HEAD 0x80000000
#define MASK 1

unsigned int rotate(unsigned int num,int move);

int main(void)
{
	unsigned int num;
	int pos;

	printf("int�Ĵ�СΪ:%d\n����HEAD�Ĵ�СΪ%u\n",sizeof(int),HEAD);
	printf("���������ֵ:");
	scanf("%u",&num);
	printf("����������ת������:");
	scanf("%d",&pos);
	num=rotate(num,pos);
	printf("��ת����ֵΪ:%u\n",num);

	return 0;
}

unsigned int rotate(unsigned int num,int move)
{
	int pos;
	int i=0;

	while(i++<move){
		pos=num & HEAD;
		//printf("%u",pos);
		num<<=1;
		if(pos==HEAD){
			num |= MASK;
			//printf("test1");
		}
		else{
			num &= ~MASK;
			//printf("test2");
		}

	}

	return num;
}


	
