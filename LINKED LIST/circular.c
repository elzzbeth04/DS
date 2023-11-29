#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *first=NULL,*last=NULL;
int number=0;
typedef struct node n;
struct node *createnode(int info)
{
	//number++;
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=info;
	new->prev=NULL;
	new->next=NULL;
	return new;
}
void insertfront()
{
	int info;
	struct node *new;
	printf("input value for info");
	scanf("%d",&info);
	new=createnode(info);
	if(first==last&&first==NULL)
	{
		first=last=new;
		first->next=last->next=NULL;
		first->prev=last->prev=NULL;
	}
	else
	{
		new->next=first;
		first->prev=new;
		first=new;
		first->prev=last;
		last->next=first;
	}
}
void insertend()
{
	int info;
	struct node *new;
	printf("input the value");
	scanf("%d",&info);
	new=createnode(info);
	if(first==last &&first==NULL)
	{
		first=last=new;
		first->next=last->next=NULL;
		first->prev=last->prev=NULL;
	}
	else
	{
		last->next=new;
		new->prev=last;
		last=new;
		first->prev=last;
		last->next=first;
	}
}
void deleterear()
{
	if (first==last &&first==NULL)
	{
		printf("\ncannot");
		
	}
	else
	{
		n *temp=first;
		while(temp->next!=first)
		{
			temp=temp->next;
		}
		if(first==last)
		{	
			
			first=last=NULL;
		}
		else
		{
			temp->prev->next=first;
			first->prev=temp->prev;
			
		}
		printf("deleted node will be");
			free(temp);
	}
}
void deletefront()
{
	n *temp;
	if (first==last && first==NULL)
	{
		printf("cannot delete");
	}
	else
	{
		temp=first;
		if(first->next==first)
		{
			first=last=NULL;
		}
		else
		{
			first=first->next;
			first->prev=last;
			last->next=first;
		}
		printf("the deleed");
		free(temp);
	}
}
void display() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = first;

    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != first);

    printf("\n");
}
// void display()
// {
// 	struct node *temp=first;
// 	while(temp->next!=first)
// 	{
// 	printf("%d->",temp->data);
// 	temp=temp->next;
// 	//printf("\n");
// 	if(temp->next->next==first)
// 	{printf("%d->",temp->next->data);}
// 	}
// 	}
	
void main()
{
	int ch;

	char choice;
	do{
	printf("\n1:insertfront");
	printf("\n2:insertend");
	printf("\n3:deletefront");
	printf("\n4:deleterear");
	printf("\n5:display");
	printf("input val");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		insertfront();
		break;
		case 2:
		insertend();
		break;
		case3:
		deletefront();
		break;
		case 4: 
		deleterear();
		break;
		case 5:
		display();
		break;
	}
	printf("do you want to continue");
	scanf("%s",&choice);
	}while(choice=='y'||choice=='Y');
	}
	
	
			
