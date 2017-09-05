#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node *start2=NULL;
struct node *createnode()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(node));
	return n;
}
void insertnode(struct node**start,int data,int n)
{
	struct node* temp,*t;
	temp=createnode();
	temp->data=data;
	temp->link=NULL;
	if(n==1)
	{
		*start=temp;
	}
	else
	{
		t=*start;
		for(int i=0;i<n-2;i++)
		t=t->link;
		temp->link=t->link;
		t->link=temp;
	}	
}
void deletenode(struct node** start,int n)
{
	struct node *t=*start;
	if(n==1)
	{
		*start=t->link;
		free(t);
		return;
	}
	for(int i=0;i<n-2;i++)
	t=t->link;
	struct node *temp=t->link;
	t->link=temp->link;
	free(temp);
}
int len(struct node *start)
{
	int n=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		temp=temp->link;
		n++;
	}
	return n;
}
void print(struct node *start)
{
	struct node* k=start;
	while(k!=NULL)
	{
		cout<<k->data<<endl;
		k=k->link;
	}
}
int main()
{
	insertnode(&start,1,1);insertnode(&start,2,2);insertnode(&start,3,3);
	insertnode(&start,4,4);insertnode(&start,5,5);insertnode(&start,6,6);
	int n;
	print(start);
	n=len(start);
	int k,c=0;
	cin>>k;
	struct node *temp=start;
	while(temp!=NULL)
	{
		if(c-k>=0)
		insertnode(&start2,temp->data,c-k+1);
		temp=temp->link;
		c++;
	}
	struct node *t=start;
	c=0;
	while(t!=NULL)
	{
		if(c-k<0)
		insertnode(&start2,t->data,n-k+c+1);
		t=t->link;
		c++;
	}
	print(start2);	
	for(int i=0;i<6;i++)
	deletenode(&start,1);
	print(start);
}
