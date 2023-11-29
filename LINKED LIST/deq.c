#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
struct deq{
struct node *front;
struct node *rear;
};
struct node *createnode(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
struct deq *initdeq(struct deq *mydeq)
{
	mydeq->front=NULL;
	mydeq->rear=NULL;
	return mydeq;
}
void addfront(struct deq *mydeq,int data)
{
	struct node *newnode=createnode(data);
	if(mydeq->front==NULL)
	{
		mydeq->front=mydeq->rear=newnode;
	}
	else
	{
		newnode->next=mydeq->front;
		mydeq->front->prev=newnode;
		mydeq->front=newnode;
	}
}
void addrear(struct deq *mydeq,int data)
{
	struct node *newnode=createnode(data);
	if(mydeq->front==NULL)
	{
		mydeq->front=mydeq->rear=newnode;
	}
	else
	{
		newnode->prev=mydeq->rear;
		mydeq->rear->next=newnode;
		mydeq->rear=newnode;
	}
}
int removefront(struct deq *mydeq)
{
	if(mydeq->front==NULL)
	{
		printf("/n Empty");
		return -1;
	}
	int data=mydeq->front->data;
	struct node *temp=mydeq->front;
	if(mydeq->front->next)
	{
		mydeq->front=mydeq->front->next;
		mydeq->front->prev=NULL;
	}
	else
	{
		mydeq->front=mydeq->rear=NULL;
	}
	free(temp);
	return data;
}
int removerear(struct deq *mydeq)
{
	if(mydeq->front==NULL)
	{
		printf("\n empty list");
		return -1;
	}
	int data=mydeq->rear->data;
	struct node *temp=mydeq->rear;
	if (mydeq->rear->prev)
	{
		mydeq->rear=mydeq->rear->prev;
		mydeq->rear->next=NULL;
	}
	else
	{
		mydeq->front=mydeq->rear=NULL;
	}
	free(temp);
	return data;
}
void displaydeq(struct deq *mydeq)
{
	struct node *current=mydeq->front;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	printf("\n");
}
void main()
{
	int ch,data;
	char choice;
	struct deq mydeq;
	initdeq(&mydeq);
	do{
	printf("\n1:addfront");
	printf("\n2:addrear");
	printf("\n3:removefront");
	printf("\n4:removerear");
	printf("\n5:display");
	printf("\n6:exit");
	printf("input choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("input the data");
		scanf("%d",&data);
		addfront(&mydeq,data);
		break;
		case 2:
		printf("input the data");
		scanf("%d",&data);
		addrear(&mydeq,data);
		break;
		case 3:
		printf("THE DATA REMOVED FROM FRONT IS%d",removefront(&mydeq));
		break;
		case 4:
		int val=removerear(&mydeq);
		printf("THE DATA REMOVED FROM REAR IS%d",val);
		break;
		case 5:
		displaydeq(&mydeq);
		break;
		case 6:
		exit(0);
		break;
		default:
		printf("invalid choice");
	}printf("do you want to continue y/n");
	scanf("%s",&choice);
	}
	while(choice=='y'||choice=='Y');
}
		
	
