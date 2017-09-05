#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void push (int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(node));
	temp->data=x;
	temp->link=start;
	start=temp;
}
void pop()
{
	struct node *temp=start;
	if(start=NULL)
	cout<<"stackoverflow";
	else
	start=temp->link;
	free(temp);
}
int top()
{
	struct node *temp=start;
	if(start==NULL)
	return 0;
	return temp->data;
}
int main
{
	push(1);
	push(2);
	push(3);
	push(4);
	int t=top();
	cout<<t;
	return 0;
}
