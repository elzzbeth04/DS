#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *createnode(char d)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    newnode->prev=NULL;
}
void insert(char c)
{
    struct node *newnode=createnode(c);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        
    }
}

int main()
{
    char str[10];
    int c;
    
    printf("input the string:\n\t\t");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        insert(str[i]);
    }
    for(int i=0;i<strlen(str);i++)
    {
        struct node *temp=head;
        int c=0;
        while(temp!=NULL)
        {
              
            if(temp->data==str[i])
            {
            c++;
            }
            temp=temp->next;
        } 
        printf("\n\t\toccurence of %c in %s is %d",str[i],str,c);
        // while(head!=NULL)
        // {
        //     struct node *ptr=head;
        //     head=head->next;
        //     free(temp);
        // }
        // head=NULL;
       
    }
   
}