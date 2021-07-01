#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *fp;
	char data[256];

	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("文件打开错误.\n");
		exit(0);
	}
	if(argc<2)
	{
		printf("参数不正确");
		exit(0);
	}

	while(fgets(data,256,fp)!=NULL)
		if(strstr(data,argv[1])!=NULL)
			printf("%s",data);
	
	fclose(fp);
	return 0;
}
