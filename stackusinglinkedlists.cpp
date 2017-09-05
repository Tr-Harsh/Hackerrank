#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *link;
};
struct node* start=NULL;
void push (int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(node));
	temp->data=x;
	temp->link=start;
	start=temp;
} 
void pop()
{
	struct node *temp;
	if(start==NULL)
	return;
	temp=start;
	start=start->link;
	free(temp);
}
int top()
{
	struct node* temp=start;
	if(start==NULL)
	return 0;
	//temp=temp->link;
	cout<<temp->data;
	return temp->data;
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
int main()
{
	push(1);push(2);push(3);//top();
	print();
	return 0;
}
