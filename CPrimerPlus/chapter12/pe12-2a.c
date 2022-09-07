#include<stdio.h>
#include"pe12-2a.h"
void get_info(void);
void show_info(void);
void set_mode(int);
static int mode_in;
static int distance;
static double use_fuel;
void set_mode(int mode)
{
	mode_in=mode;
}
void get_info(void)
{
	if(mode_in==0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in liters:");
		scanf("%lf",&use_fuel);
	}
	else if(mode_in==1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in gallons:");
		scanf("%lf",&use_fuel);
	}
	else
	{
		printf("Invalid mode specified. Mode 1 (US) used.\n");
		printf("Enter distance traveled in miles:");
		scanf("%d",&distance);
		printf("Enter fuel consumerd in gallons:");
		scanf("%lf",&use_fuel);
	}
}
void show_info(void)
{
	if(mode_in==0)
		printf("Fuel consumption is %lf liters per 100 km.\n",use_fuel/(distance/100));
	else 
		printf("Fuel consumption is %lf miles per gallon.\n",distance/use_fuel);
}


int main()
{
	return 0;
}