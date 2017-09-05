#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node *createnode()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(node));
	return n;
}
void insertnode(int data,int n)
{
	struct node* temp,*t;
	temp=createnode();
	temp->data=data;
	temp->link=NULL;
	if(n==1)
	{
		start=temp;
	}
	else
	{
		t=start;
		for(int i=0;i<n-2;i++)
		t=t->link;
		temp->link=t->link;
		t->link=temp;
	}	
}
void deletenode(int n)
{
	struct node *t=start;
	if(n==1)
	{
		start=t->link;
		free(t);
		return;
	}
	for(int i=0;i<n-2;i++)
	t=t->link;
	struct node *temp=t->link;
	t->link=temp->link;
	free(temp);
}
void reverse()
{
	struct node *pre=NULL,*current=start,*next;
	while(current!=NULL)
	{
		next=current->link;
		current->link=pre;
		pre=current;
		current=next;
	}
	start=pre;
}
void print()
{
	struct node* k=start;
	while(k!=NULL)
	{
		cout<<k->data<<endl;
		k=k->link;
	}
}
void revrec(struct node* p)
{
	//struct node *p=start;
	if(p->link==NULL)
	{
		start=p;return;
	}
	revrec(p->link);
	p->link->link=p;
	p->link=NULL;
}
int main()
{
	for(int i=1;i<6;i++)
	insertnode(i,i);
//	insertnode(7,1);
	print();
//	deletenode(4);
	//deletenode(2);
	//deletenode(1);	
///	print();
//	reverse();
//	print();
	revrec(start);
	print();
}
