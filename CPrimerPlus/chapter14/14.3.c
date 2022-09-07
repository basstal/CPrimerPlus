#include<stdio.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void sortt(struct book * pb[],int n);
void sortv(struct book * pb[],int n);

int main(void)
{
	struct book library[MAXBKS];
	struct book * pbk[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while(count < MAXBKS && gets (library[count].title) !=NULL && library[count].title[0]!='\0')
	{
		printf("Now enter the author.\n");
		gets(library[count].author);
		printf("Now enter the value.\n");
		scanf("%f",&library[count].value);
		pbk[count] = &library[count];
		count++;
		while(getchar()!='\n');
		if(count<MAXBKS)
			printf("Enter the next title.\n");
	}
	printf("Here is the list of your books:\n");
	for (index=0;index<count;index++)
		printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
	
	printf("Here is the list of your books sorted by title:\n");
	sortt(pbk,count);
	for(index=0;index<count;index++)
		printf("%s by %s :$%.2f\n",pbk[index]->title,pbk[index]->author,pbk[index]->value);
	sortv(pbk,count);
	printf("Here is the list of your books sorted by value:\n");
	for(index=0;index<count;index++)
		printf("%s by %s :$%.2f\n",pbk[index]->title,pbk[index]->author,pbk[index]->value);

	return 0;
}

void sortt(struct book * pb[],int n)
{
	int top,search;
	struct book *temp;

	for(top=0;top<n-1;top++)
		for(search=top+1;search<n;search++)
			if(strcmp(pb[search]->title,pb[top]->title)<0)
			{
				temp=pb[search];
				pb[search]=pb[top];
				pb[top]=temp;
			}
}

void sortv(struct book * pb[],int n)
{
	int top,search;
	struct book *temp;
	for(top=0;top<n-1;top++)
		for(search=top+1;search<n;search++)
			if(pb[search]->value<pb[top]->value)
			{
				temp=pb[search];
				pb[search]=pb[top];
				pb[top]=temp;
			}
}