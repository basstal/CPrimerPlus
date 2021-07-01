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

	printf("�����������ȺͽǶ�,�м��Զ��Ÿ���(r,deg)=");
	scanf("%lf,%lf",&s2.r,&s2.a);
	s1=transform(&s2);
	printf("������������x=%g,y=%g\n",s1.x,s1.y);
	
	return 0;
}


Coordinates transform(Angle * ps)
{
	Coordinates rt;

	rt.x=ps->r*cos((ps->a)/RAD_TO_DEG);
	rt.y=ps->r*sin((ps->a)/RAD_TO_DEG);

	return rt;
}

