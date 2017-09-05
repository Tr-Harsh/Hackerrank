#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* link;
};
void push(struct node** top,int x);
int pop(struct node** top);

struct queue{
	struct node* stack1;
	struct node* stack2;
};

void enqueue(struct queue* q,int x)
{
	push(&q->stack1,x);
}
int dequeue(struct queue* q)
{
	int x;
	if(q->stack1==NULL && q->stack2==NULL)
	return -1;
	if(q->stack2==NULL)
	{
		while(q->stack1!=NULL)
		{
			x=pop(&q->stack1);
			push(&q->stack2,x);
		}
	}
	x=pop(&q->stack2);
	return x;
}

void push(struct node** top,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(node));
	if(temp==NULL)
	return;
	temp->data=x;   //set data
	temp->link=*top;  //make the temp link as start
	*top=temp;  // make start point towards temp so another time new temp will come and point towards previous element and start will point this element
}
int pop(struct node** top)
{
	int res;
	struct node* rear;
	if(top==NULL)
	return -1;
	struct node* temp=*top;
	res=temp->data;
	*top=temp->link;
	free(temp);
	return res;
}
int main()
{
	struct queue* q=(struct queue*)malloc(sizeof(queue));
	q->stack1=NULL;
	q->stack2=NULL;
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);	
	enqueue(q,4);
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
}
