#include<stdio.h> 
#include<ctype.h> 
float get_float(void); 
char get_first(void);   
int main(void) 
{  
	char select;  
	float num1,num2;  
	while(1)  
	{   
		printf("Enter the operation of your choice:\n");   
		printf("a.add            s.subtract:\n");   
		printf("m.multiply       d.divide\n");   
		printf("q.quit\n");   
		select = get_first();   
		if( select != 'a' && select != 's' && select != 'm' && select != 'd')   
		{    
			printf("Bye.\n");    
			break;   
		}   
		printf("Enter first number:"); 
		num1 = get_float();   
		printf("Enter second number:");   
		num2 = get_float();   
		while( select == 'd' && num2 == 0)    
		{    
			printf("Enter a number other than 0:");    
			num2 = get_float();   
		}   
		switch(select)   
		{    
		case 'a': printf("%.2f + %.2f = %.2f\n",num1, num2, num1 + num2); 
			break;    
		case 's': printf("%.2f - %.2f = %.2f\n",num1, num2, num1 - num2); 
			break;    
		case 'm': printf("%.2f * %.2f = %.2f\n",num1, num2, num1 * num2); 
			break;    
		case 'd': printf("%.2f / %.2f = %.2f\n",num1, num2, num1 / num2); 
			break;    
		default : break;   
		}  
	}  
	return(0); 
}  
float get_float(void) 
{  
	float num;  
	char str[40];  
	while(scanf("%f",&num)!=1)  
	{   
		gets(str);   
		printf("%s is not a number.\n",str);   
		printf("Please enter a numbe, such as 2.5, -1.78E8, or 3:");  
	}  
	while ( getchar() != '\n');  
	return num; 
}  
char get_first(void) 
{  
	int ch;  
	while( isspace( ch = getchar() ) );  
	while ( getchar() != '\n');  
	return ch; 
}
