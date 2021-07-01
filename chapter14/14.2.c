#include<stdio.h>
#include<string.h>
struct Month {
		char monthname[20];
		char monthshort[4];
		int days;
		char monthnum[3];
};
struct Month months[12] = {
		{"january","jan",31,"1"},
		{"february","feb",28,"2"},
		{"march","mar",31,"3"},
		{"april","apr",30,"4"},
		{"may","may",31,"5"},
		{"june","jun",30,"6"},
		{"july","jul",31,"7"},
		{"august","aug",31,"8"},
		{"september","sep",30,"9"},
		{"october","oct",31,"10"},
		{"november","nov",30,"11"},
		{"december","dec",31,"12"}
};

int main(void)
{
	int day,month,year;
	char inmonth[40];
	int i,total;
	total=0;
	i=0;
	
	
	printf("请输入日(整数形式):");
	scanf("%d",&day);
	printf("请输入月(月份号、月份名或月份名缩写形式):\n");
	scanf("%s",inmonth);
	printf("请输入年(整数形式):");
	scanf("%d",&year);
	
	while(strcmp(months[i].monthname,inmonth)!=0&&
		strcmp(months[i].monthshort,inmonth)!=0&&
		strcmp(months[i].monthnum,inmonth)!=0&&
		i++<12);
	if(i!=12)
		month=i+1;
	for(i=0;i<month-1;i++)
		total+=months[i].days;
	if(year%4==0&&month>2)
		total+=1;
	total+=day;
	printf("一年中到该天总共有%d天.\n",total);
	return 0;
}
	



			


		


