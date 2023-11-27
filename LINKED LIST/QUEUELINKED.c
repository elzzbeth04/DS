#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;
struct node *temp=NULL;
struct node *createnode(int data)
{
	struct node newnode=(struct node *)malloc((sizeof(struct node)));
	if(newnode==NULL)
	{
		printf("there was an error");
		exit(0);
	}
	else 
	{
		newnode->next=NULL;
		newnode->data=data;
	}
	return newnode;
}
void Enqueue(int val)
{
	struct node *newnode=createnode(val);
	if(rear==NULL||front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else 
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void Dequeue()
{	
	if (front==NULL)
	{
		printf("QUEUE IS EMPTY");
	}
	else
	{
		temp=front;
		front=front->next;
			if(front==NULL)
			{
				rear=NULL;
			}
		free(temp);
	}
}
void display()
{
	if (front==NULL)
	{	
		printf("QUEUE IS EMPTY");
	}
	else
	{
		temp=front;
		printf("HEAD->");
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}printf("\n");
}
int main()
{
	int choice,val;
	char c;
	do{
	printf("\n1:ENQUEUE");
	printf("\n2:DEQUEUE");
	printf("\n3:DISPLAY");
	printf("INPUT THE VALUE FROM THE USER");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("\nEnqueue operation");
	printf("\nInput the value from the user");
	scanf("%d",&val);
	Enqueue(val);
	break;
	
	case 2:
	printf("\nDequeue Operation");
	Dequeue();
	break;
	
	case 3:
	printf("nDISPLAYING THE LIST\n");
	display();
	break;
	}
	printf("\ndo u want to continue y/n");
	scanf("%s",&c);
}	while(c=='y'||c=='Y');
}