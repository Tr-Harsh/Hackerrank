#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* link;
};
struct node *start=NULL;
struct node* createnode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(node));
    return n;
}
void insertnode()
{
    struct node* temp,*t;
    temp=createnode();
    cout<<"enter a number: ";
    cin>>temp->data;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void deletenode(int n)
{
	struct node* temp1=start;
	if(n==1)
	{
		start=temp1->link;
		free(temp1);
	}
	else
	{
		for(int i=0;i<n-2;i++)
		temp1=temp1->link;
		
		struct node *temp2=temp1->link;
		temp1->link=temp2->link;
		free(temp2);
	}
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
void reverse()
{
	struct node* prev=NULL,*current=start,*next;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next; 
	}
	start=prev;
}
int main() {
    for(int i=0;i<5;i++)
    insertnode();
    print();  
    deletenode(3);
    deletenode(1);
	deletenode(3);
	print();
	for(int i=0;i<3;i++)
    insertnode();
    reverse();
    print();
	return 0;
}
