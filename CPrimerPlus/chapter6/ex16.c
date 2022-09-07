/**
Chuckie Lucky赢了100万美元，他把它存入一个每年赢得8%的账户。在每年的最后一天，Chuckie取出10万美元。编写一个程序，计算需要多少年Chuckie就会清空他的账户。
*/
#include	<stdio.h>  
int main(void) 
{  
	double investment = 100;  
	int i=0;  
	while(investment > 0)  
	{   
		investment += investment * 0.08;   
		investment -= 10;   
		i++;  
	}  
	printf("After %d years,Chuckie Lucky's investment is out\n",i);  
	return 0; 
}