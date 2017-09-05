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
struct node *reverse(struct node **start,int k)
{
	struct node *prev=NULL,*current=*start,*next;
	int count=0;
	while(current!=NULL && count<k)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
		count++;
	}
	if(*start!=NULL)
	(*start)->link=current;
	count=0;
	while(count<k-1 && current!=NULL)
	{
		current=current->link;
		count++;
	}
	if(current!=NULL)
	current->link=reverse(&current->link,k);
	return prev;
}
void print(struct node *start)
{
	while(start!=NULL)
	{
		cout<<start->data<<endl;
		start=start->link;
	}
}
int main()
{
	struct node *temp=start;
	insertnode(1,1);insertnode(2,2);insertnode(3,3);
	insertnode(4,4);insertnode(5,5);insertnode(6,6);
	insertnode(7,7);insertnode(8,8);insertnode(9,9);
	insertnode(10,7);insertnode(11,11);insertnode(12,12);
	insertnode(13,13);insertnode(14,14);insertnode(15,15);	
	print(start);
	int k;
	cin>>k;
	start=reverse(&start,k);
	print(start);
}
