#include<iostream>
using namespace std;
int arr[5];
int n=5;
bool isempty(int &front,int &rear)
{
	if(front==-1 && rear==-1)
	return true;
	return false;
}
bool isfull(int &front,int &rear)
{
	if((rear+1)%n==front)
	return true;
	return false;
}
void enqueue(int x,int &front,int &rear)
{
	if(isfull(front,rear))
	return;
	if(isempty(front,rear))
	{
		front=0;
		rear=0;
	}
	else
	rear=(rear+1)%n;
	arr[rear]=x;
}
void dequeue(int &front,int &rear)
{
	if(isempty)
	return;
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	front=(front+1)%n;
}
int retfront(int &front)
{
	if(front==-1)
	return -1;
	return arr[front];
}
int main()
{
	int	front=-1,rear=-1;
	enqueue(5,front,rear);
	enqueue(2,front,rear);
	enqueue(3,front,rear);
	enqueue(4,front,rear);
	cout<<retfront(front)<<endl;
	dequeue(front,rear);
	cout<<"****"<<endl;
	for(int i=front;i<=rear;i++)
	cout<<arr[i]<<endl;
	return 0;
}
