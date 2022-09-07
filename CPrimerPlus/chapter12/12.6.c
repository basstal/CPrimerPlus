#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void)
{
	int num;
	int one,two,three,four,five,six,seven,eight,nine,ten;
	unsigned int seed;
	int i;

    one=two=three=four=five=six=seven=eight=nine=ten=0;
	printf("输入种子值(输入非整数退出):");
	while(scanf("%u",&seed))
	{
		srand(seed);
		for(i=0;i<1000;i++)
		{
			num=rand()%10+1;
			switch(num)
			{
			case 1:one++;break;
			case 2:two++;break;
			case 3:three++;break;
			case 4:four++;break;
			case 5:five++;break;
			case 6:six++;break;
			case 7:seven++;break;
			case 8:eight++;break;
			case 9:nine++;break;
			case 10:ten++;break;
			}
		}
		printf("数字#%d出现次数为%d.\n",1,one);
		printf("数字#%d出现次数为%d.\n",2,two);
		printf("数字#%d出现次数为%d.\n",3,three);
		printf("数字#%d出现次数为%d.\n",4,four);
		printf("数字#%d出现次数为%d.\n",5,five);
		printf("数字#%d出现次数为%d.\n",6,six);
		printf("数字#%d出现次数为%d.\n",7,seven);
		printf("数字#%d出现次数为%d.\n",8,eight);
		printf("数字#%d出现次数为%d.\n",9,nine);
		printf("数字#%d出现次数为%d.\n",10,ten);
		printf("输入种子值(输入非整数退出):");
		one=two=three=four=five=six=seven=eight=nine=ten=0;
	}
	return 0;
}
