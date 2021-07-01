/**
example:
各种转换说明符以及其作为结果的打印输出示例
*/
#include	<stdio.h>
void clear()
{
	while(getchar() != '\n');
}
int main()
{
	float flt;
	double dbl;
	char c,hhi;
	short hi;
	int i,io,ix;
	unsigned ui;
	long unsigned lu;
	long long lli;
	long long unsigned llu;
	char c_str[6];
	int *pi;
	int *pia;
	printf("**按scanf转换说明符提示输入数字或字符，然后展示printf转换说明符**\n");
	printf("PS:任意的错误输入都将导致退出程序!\n\n");

	for(;;)
	{
		printf("scanf 的 转换说明符:\n");
		printf("%%d %%i , 输入解释成有符号十进制整数: i = ");
		if(scanf("%d",&i) <= 0)
			break;
		printf("%%c , 输入解释成一个字符: c = ");
		if(scanf(" %c",&c) <= 0)
			break;
		clear();
		printf("%%E %%F %%G %%A ,输入解释成浮点数(float): flt = " );
		if(scanf("%F",&flt) <= 0)
			break;
		printf("%%le %%lf %%lg %%la ,输入解释成浮点数(double): dbl = ");
		if(scanf("%lg",&dbl) <= 0)
			break;
		printf("%%o , 输入解释成有符号八进制整数: io = ");
		if(scanf("%o",&io) <= 0)
			break;
		printf("%%x %%X, 输入解释成有符号十六进制整数: ix = ");
		if(scanf("%x",&ix) <= 0)
			break;
		printf("%%p , 输入解释成指针: pi = ");
		if(scanf("%p",&pi) <= 0)
			break;
		printf("%%5s , 输入解释成字符串（附加最大字段宽度，达到字段宽度时停止对输入项读取）: c_str[6] = ");
		if(scanf("%5s",c_str) <= 0)
			break;
		printf("%%u , 输入解释成无符号十进制整数: ui = ");
		if(scanf("%u",&ui) <= 0)
			break;
		printf("%%ld %%lu , 输入解释成long(signed/unsigned)十进制整数: lu = ");
		if(scanf("%lu",&lu) <= 0)
			break;
		printf("%%lld %%llu , 输入解释成long long(signed/unsigned)十进制整数: lli = ");
		if(scanf("%lld",&lli) <= 0)
			break;
		printf("%%hd %%hu , 输入解释成short(signed/unsigned)十进制整数: hi = ");
		if(scanf("%hd",&hi) <= 0)
			break;
		printf("%%hhd %%hhu , 输入解释成char(signed/unsigned)十进制整数: hhi = ");
		if(scanf("%hhd",&hhi) <= 0)
			break;
		printf("%%*p %%p , *滞后赋值（跳过前一个赋值）: pia = ");
		if(scanf("%*p %p",&pia) <= 0)
			break;
		clear();
		printf("input success!\n\n******************************\n");
		
		printf("printf 的 用例 (转换说明符):\n");
		printf("%10s = %-24a , %s","flt",flt,"%%a %%A 浮点数、十六进制数字和p-记数法(c99)\n");
		printf("%10s = %-24c , %s","c",c,"%%c 字符\n");
		printf("%10s = %-24e , %s","dbl",dbl,"%%e %%E 浮点数、e-记数法（printf表达式中的float会被自动转换为double）\n");
		printf("%10s = %-24f , %s","flt",flt,"%%f 浮点数、十进制记数法\n");
		printf("%10s = %-24g , %s","dbl",dbl,"%%g %%G 根据数值不同自动选择%%f或%%e\n");
		printf("%10s = %-24d , %s","i",i,"%%d %%i 十进制整数（有符号、无符号皆可）\n");
		printf("%10s = %-24u , %s","ui",ui,"%%u 无符号十进制整数\n");
		printf("%10s = %-24x , %s","ui",ui,"%%x %%X 无符号十六进制整数\n");
		printf("%10s = %-24o , %s","ui",ui,"%%o 无符号八进制整数\n");
		printf("%10s = %-24p , %s","pi",pi,"%%p 指针\n");
		printf("%10s = %-24s , %s","c_str",c_str,"%%s 字符串\n");
		printf("%-37c , %s",' ',"%%%% 百分号\n");

		//printf的标志 与 修饰符
		printf("******************************\nprintf 的 用例 (标志 与 修饰符):\n");
		printf("%10s = %-24c , %s","c",c,"- 左对齐\n");
		printf("%10s = %-+24d , %s","i",i,"+ 显示正、负符号\n");
		printf("%10s = %-+24d , %s","-i",-i,"\b\b  \n");
		printf("%10s = %- 24d , %s","i",i,"  显示负号或前导空格\n");
		printf("%10s = %-#24x , %s","ix",ix,"# 使用转换说明符的可选形式，具体参考示例\n");
		printf("%10s = %-#24f , %s","dbl",dbl,"\b\b  \n");
		printf("%10s = %-#24.1e , %s","dbl",dbl,"\b\b  \n");
		printf("%10s = %-#24.g , %s","dbl",dbl,"\b\b  \n");
		printf("%10s = %024d , %s","i",i,"0 对于所有数字格式，用前导零而不是空格填充字段宽度\n");
		printf("%10s = %-*.*s , %s","c_str",24,3,c_str,"* 预填充的可变值\n");
		printf("%10s = %-24s , %s","c_str",c_str,"digit(s) 字段宽度的最小值\n");
		printf("%10s = %-24.3g , %s","dbl",dbl,".digit(s) 精度\n");
		printf("%10s = %-24.10d , %s","i",i,"整数的精度不足时在前面加0\n");
		printf("%10s = %-24.2g , %s","flt",flt,"浮点数精度产生四舍五入\n");
		printf("%10s = %-24hd , %s","hi",hi,"h 表示short int或unsigned short int（以下皆为和整数转换说明符一起使用）\n");
		printf("%10s = %-24hhd , %s","hhi",hhi,"hh 表示signed char或unsigned char\n");
		printf("%10s = %-24lu , %s","lu",lu,"l 表示long int或unsigned long int\n");
		printf("%10s = %-24lld , %s","lli",lli,"ll 表示long long int或unsigned long long int(c99)\n");
		printf("%10s = %-24llu , %s","llu",llu,"\b\b  \n");
		printf("%10s = %-24td , %s","pi - pia",pi - pia,"t 表示ptrdiff_t(c99)\n");
		printf("%10s = %-24zd , %s","sizeof(lu)",sizeof(lu),"z 表示size_t(c99)\n");
		printf("按回车键继续..");
		clear();
	}
	printf("input error or mean to quit.\n");

	return 0;
}