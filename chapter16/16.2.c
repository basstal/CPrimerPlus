#include"normal.h"

#define HMEAN(X,Y) (1/(((1/(X))+(1/(Y)))/2))

int main(void)
{
	double x,y;
	double result;

	printf("��������������������ֵ�ö��Ÿ���(x,y)=");
	scanf("%lf,%lf",&x,&y);
	result=HMEAN(x,y);
	printf("���������ĵ���ƽ����Ϊ%g\n",result);

	return 0;
}
