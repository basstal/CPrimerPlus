#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int rd_num[100];
	int i,j;
	int temp;

	for(i=0;i<100;i++)
		rd_num[i]=rand()%10+1;//�����鸳��100��1��10��Χ�ڵ������
	for(i=0;i<99;i++)
		for(j=i+1;j<100;j++)
			if(rd_num[i]<rd_num[j])
			{
				temp=rd_num[i];
				rd_num[i]=rd_num[j];
				rd_num[j]=temp;
			}//����������ǰ�ƶ�
	for(i=0;i<100;i++)	
	{
		if(i%9==0)
			printf("\n");
		printf("%d ",rd_num[i]);
	}//�������
	return 0;
}
				
