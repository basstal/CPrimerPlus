#include<stdio.h>
void clean(void);
void stars(int i);
void print_kt(void);
float choose_gz(char c);
int main(void)
{
	float gzdj;
	char c;

	print_kt();
	printf("Please input a/b/c/d/q:");
	while((c=getchar())!=EOF)
	{
		while(strchr("abcdq",c)==NULL)
		{
		    printf("Please input a/b/c/d/q:");
		    c=getchar();
			if(c!='a'&&c!='b'&&c!='d'&&c!='c')
				clean();
		}
		gzdj=choose_gz(c);
	    if(gzdj==0)
		    break;
		else printf("gzdj=%.2f\n",gzdj);
	}
	return 0;
}
void stars(int i)
{
	int j;
	for(j=0;j<i;j++)
		printf("*");
	printf("\n");
}
void print_kt(void)
{
	stars(70);
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a)$8.75/hr                      b)$9.33/hr\n"
		   "c)$10.00/hr                     d)$11.20/hr\n"
		   "q)quit\n");
    stars(70);
}
float choose_gz(char c)
{
	switch(c)
	{   case 'a':return 8.75;
	    case 'b':return 9.33;
		case 'c':return 10.00;
		case 'd':return 11.20;
		case 'q':return 0;}
}
void clean(void)
{
	while(getchar()!='\n');
}

