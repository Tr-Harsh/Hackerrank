#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* link;
};
struct node* front=NULL;
struct node* rear=NULL;
void enqueue(int x)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(node));
	temp->data=x;
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->link=temp;
	rear=temp;	
}
void dequeue()
{
	struct node* temp=front;
	if(front==rear)
	{
		front=rear=NULL;
		return;
	}
	front=front->link;
	free(temp);
}
int retfront()
{
	if(front==NULL)
	return -1;
	return front->data;
}
int main()
{
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	cout<<retfront()<<endl;
	dequeue();
	cout<<retfront();
}
