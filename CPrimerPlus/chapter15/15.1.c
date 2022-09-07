#include<stdio.h>


int transform(char []);

int main(void)
{
	char c[40];
	int num;

	printf("输入二进制字符串:\n");
	gets(c);
	num=transform(c);
	printf("二进制字符串等于数值 %d.\n",num);

	return 0;
}


int transform(char pc[])
{
	int i=0;
	int MASK=1,num=0;

	while(pc[i]){
		if(pc[i]=='0')
			num<<=1;
		else{
			num |= MASK;
			if(pc[i+1])
				num<<=1;
		}
		i++;
	}

	return num;
}