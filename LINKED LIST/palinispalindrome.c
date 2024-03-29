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
int ispal()
{
    struct node *h=head;
    struct node *t=tail;
    while(h!=NULL&& t!=NULL)
    {
        if(h->data != t->data)
        {
            return 0;
        }
        t=t->prev;
        h=h->next;
        
    }
    return 1;
}
int main()
{
    char str[10];
    printf("input the string");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        insert(str[i]);
    }
    if(ispal())
    {
        printf("palindrome");
    }
    else 
    printf("not");
}