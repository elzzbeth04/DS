#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
struct node *temp=NULL;
struct node *createnode(int data)
{
	struct node *newnode= (struct node*)malloc((sizeof(struct node)));
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
void push(int data)
{
	struct node *newnode=(struct node*)malloc((sizeof(struct node)));
	
	newnode=createnode(data);
	if (top==NULL)
	{
		top=newnode;
		//newnode=newnode->next;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void peak()
{
printf("%d",top->data);
}
void pop()
{
if(top==NULL)
{
	printf("stack is empty");
}
else
{
	temp=top;
	top=top->next;
	free(temp);
}
}
void display()
{
 	
	if (top==NULL)
	{
		printf("stack is empty");
	}
	else 
	{
		temp=top;
		  printf("Head->");
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}

int main()
{
char c;
int choice,data;
do
{
	printf("\n1:PUSH");
	printf("\n2:POP");
	printf("\n3:PEAK");
	printf("\n4:DISPLAY");
	printf("\ninput choice from the user");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		int val;
		printf("\nenter the value to be pushed\n");
		scanf("%d",&val);
		push(val);
		break;
		
		case 2:
		printf("\nPOP OPERATION");
		pop();
		break;
		
		case 3:
		printf("\npeak operation");
		peak();
		break;
		
		case 4:
		printf("\ndisplay");
		display();
		break;
		
	}printf("\ndo u want to continue y/n");
	scanf("%s",&c);
	}while(c=='y'||c=='Y');
return 0;
}