/**
编写一个程序读取输入，直到#，并报告序列ei出现的次数。
*/
#include	<stdio.h>  
int main(void) 
{  
	char former=0,present;  
	int count=0;  
	while((present=getchar()) != '#')  
	{   
		if((former == 'e') && (present == 'i')) 
			count++;   
		former = present;  
	}  
	printf("ei has appeared %d times\n",count);  
	
	return 0; 
}