#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

    struct node *front=NULL;
    struct node *rear=NULL;
    struct node *top=NULL;
    
struct node *createnode(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}




void enqueue(int data)
{
    struct node *newnode=createnode(data);
    if (front==NULL||rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void push(struct node **top,int data)
{
 struct node *newnode=createnode(data);
 if(top==NULL)
 {
    *top=newnode;
 }
 else{
   newnode->next=*top;
   *top=newnode;
 }

}
struct node *pop()
{
     struct node *temp;
    if(top==NULL)
    {
        printf("EMPTY STACK");
    }
    else{
     temp =top;
       top=top->next;
    }
    // free(temp);
     return(temp);
}

struct node *dequeue()
{
    struct node *temp;
    if(rear==NULL||front==NULL)
    {
        printf("NOT");
    }
    else{
        temp=front;
        front=front->next;
       
    }
    
    return temp;
    // free(temp);
}
void reverse()
{
    while(front!=NULL)
    {
        push(&top,dequeue()->data);
    }
    while(top!=NULL)
    {
        enqueue(pop()->data);
    }
}
void display()
{
struct node *temp=front;
if(front==NULL||rear==NULL)
{
    printf("NULL");
}
else{
    printf("head->");
while(temp!=NULL)
{
    printf("%d->",temp->data);
    temp=temp->next;
}

}
}
int main() {
    // Write C code here
    int choice,data;
    char ch;
    do{
        printf("1:enqueue");
        printf("2:dequeue");
        printf("3:reverse");
        printf("4:display");
        printf("INPUT CHOICE");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("input");
            scanf("%d",&data);
            enqueue(data);
            break;

            case 2:
            int deqele= dequeue()->data;
            printf("dequed element:%d",deqele);
            break;

            case 3:
            reverse();
            break;

            case 4:
            display();
            break;

            default:
            printf("Invalid");

        }printf("\ncontinue?y/n");
        scanf("%s",&ch);  
          }while(ch=='y');
}