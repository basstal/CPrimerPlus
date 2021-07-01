#include"BiTree.h"
typedef struct{
	BiNode * parent;
	BiNode * child;
}Pair;

static void DeleteAllNodes(BiNode * root);
static void Delete(BiNode ** p);
static void InOrder_1(const BiNode * root,void (*visit)(Item));
static void InOrder_2(const BiNode * root,void (*visit)(Item));
static void InOrder_3(const BiNode * root,void (*visit)(Item));
static Pair SeekNode(const Item * i,const BiTree * tree);
static Bool ToRight(const Item * i1,const Item * i2);
static Bool ToLeft(const Item * i1,const Item * i2);
static void Add(BiNode * new_node,BiNode * root);
static BiNode * MakeNode(const Item * i);


void InitBiTree(BiTree * tree)
{
	tree->root=NULL;
	tree->size=0;
}

Bool BiTreeEmpty(const BiTree * tree)
{
	return tree->size==0?TRUE:FALSE;
}

int BiTreeSize(const BiTree * tree)
{
	return tree->size;
}

Bool AddNode(const Item * i,BiTree * tree)
{
	BiNode * new_node;

	/*if(SeekItem(i,tree).child!=NULL){
		fprintf(stderr,"Attempted to add duplicate item\n");
		return FALSE;
	}*/
	new_node=MakeNode(i);
	if(new_node==NULL){
		fprintf(stderr,"Couldn't create node\n");
		return FALSE;
	}

	tree->size++;
	if(tree->root==NULL)
		tree->root=new_node;
	else
		Add(new_node,tree->root);
	return TRUE;
}

Item * InBiTree(const Item * i,const BiTree * tree)
{
	if(SeekNode(i,tree).child)
		return &SeekNode(i,tree).child->i;
	else 
		return NULL;
}

Bool DeleteNode(const Item * i,BiTree * tree)
{
	Pair look;
	look=SeekNode(i,tree);
	if(look.child==NULL)
		return FALSE;

	if(look.parent==NULL)
		Delete(&tree->root);
	else if(look.parent->left==look.child)
		Delete(&look.parent->left);
	else
		Delete(&look.parent->right);
	tree->size--;
	return TRUE;
}

void TraverBiTree(const BiTree * tree,void (*visit)(Item))
{
	if(tree->size!=0)
		InOrder_1(tree->root,visit);
}

void DeleteBiTree(BiTree * tree)
{
	if(tree->size!=0)
		DeleteAllNodes(tree->root);
	tree->root=NULL;
	tree->size=0;
}


/*****************************************
 *        �ڲ�����                       
 *****************************************/
static BiNode * MakeNode(const Item * i)
{
	BiNode * new_node;

	new_node=malloc(sizeof(BiNode));
	if(new_node!=NULL){
		new_node->i=*i;
		new_node->left=NULL;
		new_node->right=NULL;
	}
	return new_node;
}

static void Add(BiNode * new_node,BiNode * root)
{
	if(ToLeft(&new_node->i,&root->i)){
		if(root->left==NULL)
			root->left=new_node;
		else
			Add(new_node,root->left);
	}
	else if(ToRight(&new_node->i,&root->i)){
		if(root->right==NULL)
			root->right=new_node;
		else
			Add(new_node,root->right);
	}
	else
		root->i.count++;
}

static Bool ToLeft(const Item * i1,const Item * i2)
{
	if(strcmp(i1->string,i2->string)<0)
		return TRUE;
	else
		return FALSE;
}
static Bool ToRight(const Item * i1,const Item * i2)
{
	if(strcmp(i1->string,i2->string)>0)
		return TRUE;
	else
		return FALSE;
}
static Pair SeekNode(const Item * i,const BiTree * tree)
{
	Pair look;
	look.parent=NULL;
	look.child=tree->root;

	if(look.child==NULL)
		return look;
	while(look.child!=NULL){
		if(ToLeft(i,&(look.child->i))){
			look.parent=look.child;
			look.child=look.child->left;
		}
		else if(ToRight(i,&(look.child->i))){
			look.parent=look.child;
			look.child=look.child->right;
		}
		else
			break;
	}
	return look;
}


static void Delete(BiNode ** p)
{
	BiNode * temp;

	puts((*p)->i.string);
	if((*p)->left==NULL){
		temp=*p;
		*p=(*p)->right;
		free(temp);
	}
	else if((*p)->right==NULL){
		temp=*p;
		*p=(*p)->left;
		free(temp);
	}
	else{
		for(temp=(*p)->left;temp->right!=NULL;temp=temp->right)
			continue;
		temp->right=(*p)->right;
		temp=*p;
		*p=(*p)->left;
		free(temp);
	}
}

static void InOrder_1(const BiNode * root,void (*visit)(Item))
{
	if(root!=NULL){
		visit(root->i);
		InOrder_1(root->left,visit);
		InOrder_1(root->right,visit);
	}
}
static void InOrder_2(const BiNode * root,void (*visit)(Item))
{
	if(root!=NULL){
		InOrder_2(root->left,visit);
		visit(root->i);
		InOrder_2(root->right,visit);
	}
}
static void InOrder_3(const BiNode * root,void (*visit)(Item))
{
	if(root!=NULL){
		InOrder_3(root->left,visit);
		InOrder_3(root->right,visit);
		visit(root->i);
	}
}

static void DeleteAllNodes(BiNode * root)
{
	BiNode * pright;
	if(root!=NULL){
		pright=root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

void ReadWords(BiTree * tree)
{
	FILE * fp;
	char name[20];
	char word[WORDSIZE];
	Item temp;
	int i=0,j;
	char ch;

	printf("�������ļ���(����׺):");
	scanf("%s",name);
#ifdef TEST
	printf("\n�����ļ����ɹ�\n");
#endif
	if((fp=fopen(name,"r+"))==NULL){
		fprintf(stderr,"���ļ�%s����!\n",name);
		exit(1);
	}
#ifdef TEST
	printf("\n���ļ��ɹ�\n");
#endif
	while((ch=getc(fp))!=EOF){
#ifdef TEST
		printf("\n�ܶ�ȡ�ļ��е��ַ�\n");
#endif
		if(isalpha(ch)){
			word[i++]=ch;
#ifdef TEST
			printf("\n¼���ַ�\n");
#endif
		}
		else if(word[0]!='\0'){
			word[i]='\0';
			for(j=0;j<=i;j++)
				temp.string[j]=word[j];
			temp.count=1;
#ifdef TEST
			printf("\n¼���ַ�Ϊ%s,��һ���������뵽��������\n",temp.string);
#endif
			AddNode(&temp,tree);
			word[0]='\0';
			i=0;
		}
	}
	fclose(fp);
}

void print(Item i)
{
	printf("����%s���ִ���Ϊ%d\n",i.string,i.count);
}

void menu(void)
{
	printf("***********************************************\n");
	printf("*       ѡ��1���г����е��ʼ����ִ���         *\n");
	printf("*       ѡ��2�����벢����ָ������             *\n");
	printf("*       ѡ��3���˳�����                       *\n");
	printf("***********************************************\n");
	printf("        ����������1-3��");
}


int main(void)
{
	BiTree tree;
	Item * temp;
	char word[20];
	int i,s;

	InitBiTree(&tree);
	ReadWords(&tree);
	menu();
	while(1){
		scanf("%d",&s);
		CLEAN();
		switch(s)
		{
		case 1:
			TraverBiTree(&tree,print);
			break;
		case 2:
			printf("��������ҵĵ���:");
			scanf("%s",word);
			CLEAN();
			temp=malloc(sizeof(Item));
			for(i=0;i<=strlen(word);i++)
				temp->string[i]=word[i];
			temp=InBiTree(temp,&tree);
			if(temp)
				printf("����%s���ִ���Ϊ%d\n",temp->string,temp->count);
			else
				printf("����%sδ����\n",word);
			break;
		case 3:
			return 0;
		default:
			printf("��������,����������ѡ��:");
			continue;
		}
		menu();
	}

	return 0;
}

			
