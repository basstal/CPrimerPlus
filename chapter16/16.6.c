#include"normal.h"
#define NUM 5
#define CNUM 40

struct names{
	char first[CNUM];
	char last[CNUM];
};


void fillarray(struct names ar[],int n);
void showarray(const struct names ar[],int n);
int mycomp(const void *p1,const void *p2);

int main(void)
{
	struct names vals[NUM]={{'\0','\0'}};
	fillarray(vals,NUM);
	puts("Random list: ");
	showarray(vals,NUM);
	qsort(vals,NUM,sizeof(struct names),mycomp);
	puts("\nSorted list: ");
	showarray(vals,NUM);
	return 0;
}

void fillarray(struct names ar[],int n)
{
	int index;

	for(index=0;index<n;index++){
		printf("请输入#%d姓名，用逗号隔开:\n",index+1);
		scanf("%s%s",ar[index].last,ar[index].first);
	}

}

void showarray(const struct names ar[],int n)
{
	int index;

	for(index=0;index<n;index++)
		printf("%s·%s\n",ar[index].last,ar[index].first);
}


int mycomp(const void *p1,const void *p2)
{
	const struct names *ps1=(const struct names *)p1;
	const struct names *ps2=(const struct names *)p2;
	int res;

	res=strcmp(ps1->last,ps2->last);
	if(res!=0)
		return res;
	else
		return strcmp(ps1->first,ps2->first);
}