/**
ABC Mail Order Grocery 朝鲜藓的售价是1.25美元/磅，甜菜的售价是0.65美元/磅，胡萝卜的售价是0.89美元/磅。在添加运输费之前，它们为100美元的订单提供5%的打折优惠。对5磅或以下的订单收取3.50美元的运输和装卸费用；超过5磅而不足20磅的订单收取10.00美元的运输和装卸费用；20磅或以上的运输，在8美元基础上每磅加收0.1美元。编写程序，在循环中使用switch语句，以便对输入a的响应是让用户输入所需的朝鲜藓磅数，b为甜菜的磅数，c为胡萝卜的磅数，而q允许用户退出订购过程。然后程序计算总费用、折扣和运输费用，以及总数。随后程序应该显示所有的购买信息：每磅的费用、订购的磅数、该订单每种蔬菜的费用、订单的总费用、折扣，如果有的话加上运输费用，以及所有费用的总数。
*/
#include	<stdio.h> 
#include	<ctype.h> 
#define ARTICHOKE 1.25 
#define BEET 0.65 
#define CARROT 0.89 
#define DISCOUNT_LIMIT 100 
#define DISCOUNT_RATE 0.05 
#define FREIGHT_FEE1 3.50 
#define FREIGHT_LIMIT1 5 
#define FREIGHT_FEE2 10.00 
#define FREIGHT_LIMIT2 20 
#define FREIGHT_FEE3 8 
#define FREIGHT_RATE 0.1

int main(void) 
{  
	char ch;  
	double artichoke=0,beet=0,carrot=0;  
	double sum,discount,freight;  
	printf("Please select your vegetable: a,b,c,q\n");  
	printf("a.artichoke price:$%.2f\n",ARTICHOKE);  
	printf("b.beet price:$%.2f\n",BEET);  
	printf("c.carrot price:$%.2f\n",CARROT);  
	printf("q.end\n");  
	printf("(price as dollars per pound)\n");  
	while( ( ch = tolower( getchar() )  ) != 'q') 
	{   
		switch(ch)   
		{   
		case 'a': 
			printf("How many pounds of artichokes do you want?");      
			if(scanf("%lf",&artichoke) < 0)
				return -1;
			printf("Please select your vegetable: a,b,c,q:");      
			continue;    
		case 'b': 
			printf("How many pounds of beets do you want?");      
			if(scanf("%lf",&beet) < 0)
				return -1;
			printf("Please select your vegetable: a,b,c,q:");      
			continue;    
		case 'c': 
			printf("How many pounds of carrots do you want?");      
			if(scanf("%lf",&carrot) < 0)
				return -1;
			printf("Please select your vegetable: a,b,c,q:");      
			continue;   
		default: break;
		}
	}  
	printf("%10s%10s%10s%10s\n"," ","artichoke","beet","carrot");  
	printf("%10s%10.2lf%10.2lf%10.2lf\n","price",ARTICHOKE,BEET,CARROT);  
	printf("%10s%10.2lf%10.2lf%10.2lf\n","pound",artichoke,beet,carrot);  
	printf("%10s%10.2lf%10.2lf%10.2lf\n","charge",ARTICHOKE * artichoke,BEET * beet,CARROT * carrot);  
	sum = ARTICHOKE * artichoke + BEET * beet + CARROT * carrot;  
	if (sum > DISCOUNT_LIMIT) 
		discount = sum*DISCOUNT_RATE; 
	else 
		discount = 0;  
	printf("discount: %.2f\n",discount);  
	if (artichoke + beet + carrot <= 5) 
		freight = 3.50;  
	else if (artichoke + beet + carrot <20) 
		freight = 10;  
	else 
		freight = 8 + (artichoke + beet + carrot) * 0.1;  
	printf("freight: %.2f\n",freight);  
	sum = sum - discount + freight;  
	printf("sum: %.2f\n",sum);  
	return 0; 
}
