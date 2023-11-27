#include <stdio.h>
#include<stdlib.h>
//struct node *insertnode(struct node *ptr3,int sum,int power);
struct node *inputpoly(struct node *head,int size);
void display(struct node *ptr);
void Calsum(struct node *ptr1,struct node *ptr2);
struct node
{
	int power;
	int coeff;
	struct node *link;
};
struct node *head3=NULL;
struct node *insertnode(struct node *ptr3,int sum,int power)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->coeff=sum;
	newnode->power=power;
	newnode->link=NULL;
	if (head3==NULL)
	{
		head3=newnode;
	}
	else
	{
		ptr3->link=newnode;
	}
	ptr3=newnode;
	return ptr3;
}
void Calsum(struct node *ptr1,struct node *ptr2)
{
	struct node *ptr3=head3;
	int sum,power;
	while(ptr1!=NULL && ptr2!=NULL)
	{	
		if(ptr1->power==ptr2->power)
		{
			sum=ptr1->coeff+ptr2->coeff;
			power=ptr2->power;
			ptr3=insertnode(ptr3,sum,power);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->power>ptr2->power)
		{
			sum=ptr1->coeff;
			power=ptr1->power;
			ptr3=insertnode(ptr3,sum,power);
			ptr1=ptr1->link;
		}
		else
		{
			sum=ptr2->coeff;
			power=ptr2->power;
			ptr3=insertnode(ptr3,sum,power);
			ptr2=ptr2->link;
		}
	}
	while(ptr1!=NULL)
	{
		sum=ptr1->coeff;
		power=ptr1->power;
		ptr3=insertnode(ptr3,sum,power);
		ptr1=ptr1->link;
	}
	while(ptr2!=NULL)
	{
		sum=ptr2->coeff;
		power=ptr2->coeff;
		ptr3=insertnode(ptr3,sum,power);
		ptr2=ptr2->link;
	}
}

struct node *inputpoly(struct node *head,int size)
{
	struct node *ptr=NULL;
	int power,coeff;
	
	for(int i=0;i<size;i++)
	{
		printf("enter the coeff  in descending order %d th term",i+1);
		scanf("%d",&coeff);
		printf("enter the  power in descending order %d th term",i+1);
		scanf("%d",&power);
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
		newnode->coeff=coeff;
		newnode->power=power;
		newnode->link=NULL;
		
		if (head==NULL)
		{
		head=newnode;
		ptr=head;
		}
		else
		{
			ptr->link=newnode;
			ptr=newnode;
		}
	}
	return head;
}
void display(struct node *ptr)
{
	while(ptr!=NULL)
		{
			printf("%d x ^ %d +",ptr->coeff,ptr->power);
			ptr=ptr->link;
		}
}
int main()
{
	struct node *head1=NULL,*head2=NULL;
	int size1,size2;
	printf("input the size of poly1");
	scanf("%d",&size1);
	
	if (size1<1)
	{
		printf("invalid");
                return 0;
	}
	head1=inputpoly(head1,size1);
	
	printf("input the size of poly2");
	scanf("%d",&size2);
	if (size2<1)
	{
		printf("invalid");
                return 0;
	}
	head2=inputpoly(head2,size2);//passing head2 since &is not there if there was &then 2 functions may be req
	printf("first poly\n");
	display(head1);
	printf("\n2nd poly");
	display(head2);
	printf("\nresultant will be\n");
	Calsum(head1,head2);
	display(head3);
}