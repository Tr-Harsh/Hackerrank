#include<stdio.h>  
#include<conio.h>  
#include<stdlib.h>  
  
typedef struct node  
{  
int data;  
struct  node* next,*prev;  
      
}node;  
struct node* head;  
void print()  
{  
    struct node* temp=head;  
    while(temp!=NULL)  
    {  
        printf("%d",temp->data);  
        temp=temp->next;  
    }  
}  
void insertAtAnyPosition(int x,int pos)  
{     
    struct node* temp=NULL;  
    temp=(node*)malloc(sizeof(struct node));  
    temp->data=x;  
    if(pos==1)  
    {  
        temp->next=NULL;  
        head=temp;  
        temp->prev=head;   
    }  
    else  
    {  
         struct node* temp2=head;  
          struct node* temp3=NULL;  
        int i=0;  
        for(i=0;i<pos-2;i++)  
        {  
            temp2=temp2->next;  
            temp3=temp2->next;  
        }  
        temp->next=temp3;  
        temp3->prev=temp->next;  
        temp2->next=temp;  
        temp->prev=temp2;  
    }  
    printf(" After Insertion at any Position  ");  
    print();  
      
}  
int main()  
{      
	insertAtAnyPosition(1,1);
	insertAtAnyPosition(2,2);
	insertAtAnyPosition(3,3);        
    getch();  
}  
