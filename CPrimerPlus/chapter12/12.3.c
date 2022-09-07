#include<stdio.h>
void get_info(int mode);
void show_info(int mode,int distance,double use_fuel);
int main(void)
{
	int mode;

	printf("Enter 0 for metric mode,1 for US mode:");
	scanf("%d",&mode);
	while(mode>=0)
	{
		get_info(mode);
		printf("Enter 0 for metric mode,1for US mode");
		printf("(-1 to quit):");
		scanf("%d",&mode);
	}
	printf("Done.\n");
	return 0;
}
void get_info(int mode)
{
	int distance;
	double use_fuel;

	if(mode==0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in liters:");
		scanf("%lf",&use_fuel);
		show_info(mode,distance,use_fuel);
	}
	else if(mode==1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in gallons:");
		scanf("%lf",&use_fuel);
		show_info(mode,distance,use_fuel);
	}
	else
	{
		printf("Invalid mode specified. Mode 1 (US) used.\n");
		printf("Enter distance traveled in miles:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in gallons:");
		scanf("%lf",&use_fuel);
		show_info(mode,distance,use_fuel);
	}
}
void show_info(int mode,int distance,double use_fuel)
{
	if(mode==0)
		printf("Fuel consumption is %lf liters per 100 km.\n",use_fuel/(distance/100));
	else 
		printf("Fuel consumption is %lf miles per gallon.\n",distance/use_fuel);
}