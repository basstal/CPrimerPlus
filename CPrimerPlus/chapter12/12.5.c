#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int rd_num[100];
	int i,j;
	int temp;

	for(i=0;i<100;i++)
		rd_num[i]=rand()%10+1;//给数组赋上100个1到10范围内的随机数
	for(i=0;i<99;i++)
		for(j=i+1;j<100;j++)
			if(rd_num[i]<rd_num[j])
			{
				temp=rd_num[i];
				rd_num[i]=rd_num[j];
				rd_num[j]=temp;
			}//将最大的数往前移动
	for(i=0;i<100;i++)	
	{
		if(i%9==0)
			printf("\n");
		printf("%d ",rd_num[i]);
	}//输出数组
	return 0;
}
				
