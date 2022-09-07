#include"normal.h"
#define RAD_TO_DEG (180/(4*atan(1)))

typedef struct {
	double x;
	double y;
}Coordinates;

typedef struct {
	double r;
	double a;
}Angle;

Coordinates transform(Angle * ps);

int main(void)
{
	Coordinates s1;
	Angle s2;

	printf("输入向量长度和角度,中间以逗号隔开(r,deg)=");
	scanf("%lf,%lf",&s2.r,&s2.a);
	s1=transform(&s2);
	printf("该向量的坐标x=%g,y=%g\n",s1.x,s1.y);
	
	return 0;
}


Coordinates transform(Angle * ps)
{
	Coordinates rt;

	rt.x=ps->r*cos((ps->a)/RAD_TO_DEG);
	rt.y=ps->r*sin((ps->a)/RAD_TO_DEG);

	return rt;
}

