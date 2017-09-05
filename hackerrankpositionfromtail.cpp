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

int GetNode(node *head,int positionFromTail)
{
   	//struct node *pre=NULL,*current=head,*nextn,
	struct node *t=head,*t2=head;
	int n=0;
	while(t2){
		t2=t2->link;
		n++;
	}
	
 	for(int i=0;i<n-positionFromTail-1;i++)
    	t=t->link;
   	return t->data;
}
int main()
{
	for(int i=1;i<4;i++)
	insertnode(i,i);
	int x=GetNode(start,0);
	cout<<x;
}
