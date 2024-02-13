#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *createnode(int d)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}
void insert(int c)
{
   
    struct node *newnode=createnode(c);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
         struct node *temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
        temp->next=newnode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp = head;
        printf("\n\t\tHead->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void alter()
{
    int c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        
        if(c%2==0)
        {
            printf("%d->",temp->data);
        }
        c++;
        temp=temp->next;
    }
   // printf("\n\t\t%d",c);
}


int main()
{
    int n,c,num;
    
    printf("input the length:\n\t\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n enter num");
        scanf("%d",&num);
        insert(num);
    }
    display();
    alter();
   

       
    }
   
