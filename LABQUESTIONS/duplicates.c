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
int findmin()
{
    int small=head->data;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(small > temp->data)
        {
            small=temp->data;
        }
        temp=temp->next;
    }
    return small;
    
}
int findmax()
{
    int large=head->data;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(large < temp->data)
        {
            large=temp->data;
        }
        temp=temp->next;
    }
    return large;
    
}
int findsum()
{
    struct node *temp=head;
    int s=0;
   while(temp!=NULL)
   {
       s=s+temp->data;
       temp=temp->next;
   }
   return s;
//   printf("\n%d",s);
}
void display(struct node *h)
{
    if (h == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp = h;
        printf("\n\t\tHead->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int removed() {
    struct node *i = head;
    struct node *j, *temp;
    while(i != NULL && i->next != NULL) {
        j = i;
        while (j->next != NULL) {
            if (i->data == j->next->data) {
                temp = j->next;
                if (j->next->next != NULL) {
                    j->next = j->next->next;
                } else {
                    j->next = NULL;
                }
                free(temp);
            } else {
                j = j->next;
            }
        }
        i = i->next;
    }
    printf("\n\t\t AFTER DUPLICATES REMOVAL");
    display(head);
}
struct node  *copy(struct node *head)
{
    struct node *temp=head;
    struct node *head2=NULL;
    while(temp!=NULL)
    {
        int c=temp->data;
        struct node *newnode=createnode(c);
        if(head2==NULL)
        {
            head2=newnode;
        }
        else
        {
            struct node *temp2=head2;
            while(temp2->next!=NULL)
            {
                temp2=temp2->next;
            }
            temp2->next=newnode;
        }
        temp=temp->next;
    }
    printf("\nCOPIED LIST");
    display(head2);
    return head2;
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
    printf("\n\n\t\tORIGINAL");
    display(head);
    int min=findmin();
    printf("\n\n\t\tminimum val=%d",min);
    int max=findmax();
    printf("\n\n\t\tmaximum val=%d",max);
    int sum=findsum();
    printf("\n\n\t\t sum is=%d",sum);
     struct node *ptr=head;
    struct node *head2 =copy(ptr);
    removed();
   
    
       
    }
   
