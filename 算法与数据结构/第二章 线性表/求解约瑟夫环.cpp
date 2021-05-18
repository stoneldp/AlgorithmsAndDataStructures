# include<stdio.h>
#include<stdlib.h>
typedef struct jos
{
	int order;
	int mima;
	struct jos *link;
}Node;
Node *creat(void)
{
	Node *p,*q,*head;
	int i,s[100];
	int n;//人数
	/*s输入人数和各自的密码*/
	printf("请输入人数（n）:");
	scanf("%d",&n);
	printf("请输入个人的密码：\n");
	for(i=1;i<=n;i++)
	scanf("%d",&s[i]);
	head=(Node *)malloc(sizeof(Node));//建立循环单链表
	head->order=1;
	head->mima=s[1];
	q=head;
	for(i=1;i<=n-1;i++)
	{
		p=(Node *)malloc(sizeof(Node));
		q->link=p;
		p->order=i+1;
		p->mima=s[i+1];
		q=p;
	}//将新结点插入在链表的尾部
	p->link=head;//首尾相接，构成循环
	return head;
}
main()
{
	Node *head,*p,*q;
	int i,n,m,k=1,t=0,del[100];
	head=creat();
	p=head;
	q=head;
	printf("请输入初始值（m）:");
	scanf("%d",&m);
	do
	{
		loop1:if(k==m){
			k=1;m=p->mima;
			t++;
			del[t]=p->order;
			q->link=p->link;
			free(p);
			p=q->link;
			goto loop1;
		}
		q=p;
		p=p->link;
		k++;
		if(t== n-1){
			del[n]=p->order;
			t++;
		}
	}while(t<=n-1);
	printf("出列顺序为：\n");
	if(n==1)
	printf("%d",1);
	else
	for(i=1;i<=n;i++)
	printf("%7d",del[i]);
}