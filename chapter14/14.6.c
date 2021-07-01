#include<stdio.h>
#include<string.h>
struct info {
	int num;
	char fname[40];
	char lname[40];
	int ontimes;
	int hits;
	int runbase;
	int runrbi;
	double avehitsuc;
};
int main(void)
{
	int temp,n,i;
	char tempc[40];
	FILE *fp;
	int a=0,b=0,c=0,d=0;
	double e=0;
	struct info data[19] = {0,'\0','\0',0,0,0,0};
	fp=fopen("information.txt","r+");

	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		n=temp;
		fscanf(fp,"%s",tempc);
		strcpy(data[n].fname,tempc);
		fscanf(fp,"%s",tempc);
		strcpy(data[n].lname,tempc);
		fscanf(fp,"%d",&temp);
		data[n].ontimes+=temp;
		fscanf(fp,"%d",&temp);
		data[n].hits+=temp;
		fscanf(fp,"%d",&temp);
		data[n].runbase+=temp;
		fscanf(fp,"%d",&temp);
		data[n].runrbi+=temp;
	}
	for(i=0;i<19;i++)
		data[i].avehitsuc=(double)data[i].hits/(double)data[i].ontimes;
	printf("球员号码        球员姓名  上场次数  击中数  走垒数  跑点数  平均成功率\n");
	for(i=0;i<19;i++)
		printf("%3d%10s%10s%10d%10d%10d%10d%10g\n",i,data[i].fname,data[i].lname,data[i].ontimes,data[i].hits,data[i].runbase,data[i].runrbi,data[i].avehitsuc);
	for(i=0;i<19;i++)
	{
		a+=data[i].ontimes;
		b+=data[i].hits;
		c+=data[i].runbase;
		d+=data[i].runrbi;
		e+=data[i].avehitsuc;
	}
	printf("%33d%10d%10d%10d%10g\n",a,b,c,d,e/19);
	
	getchar();
	fclose(fp);
	return 0;
}
