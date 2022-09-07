#include<stdio.h>
#define HEAD 0x80000000
#define MASK 1

unsigned int rotate(unsigned int num,int move);

int main(void)
{
	unsigned int num;
	int pos;

	printf("int的大小为:%d\n常量HEAD的大小为%u\n",sizeof(int),HEAD);
	printf("输入测试数值:");
	scanf("%u",&num);
	printf("输入向左旋转的数量:");
	scanf("%d",&pos);
	num=rotate(num,pos);
	printf("旋转后数值为:%u\n",num);

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


	
