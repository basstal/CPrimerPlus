/**
exercise 1:
通过试验的方法观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况
*/
#include	<stdio.h>
//defines INT_MAX
#include	<limits.h>
//defines FLT_MAX
#include	<float.h>

int main()
{
	printf("**整数上溢**\n");
	int maxd = INT_MAX;
	printf("INT_MAX = %d, INT_MAX + 1 = %d\n",maxd,maxd + 1);

	printf("**浮点数上溢**\n");
	double maxf = DBL_MAX;
	// printf("sizeof(double) = %lu\n",sizeof(maxf));
	printf("DBL_MAX = %e, DBL_MAX * 10.0 = %e\n",maxf,maxf * 10.0);
	printf("**浮点数下溢**\n");
	double minf = 2.225074e-323;
	printf("%e / 10.0 = %e\n",minf,minf / 10.0);
	// printf("DBL_MIN_EXP = %d\n",DBL_MIN_EXP);
	return 0;
}