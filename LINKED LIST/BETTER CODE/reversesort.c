#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *first=NULL;
struct node *createnode(int data)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
 }

void insert(int data)
{
    struct node *newnode=createnode(data);
    if(first==NULL)
    {
        first=newnode;
    }
    else
    {
        struct node *temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertaf(int data)
{
    int n;
      printf("\n\t\tinput val");
        scanf("%d",&n);  
        struct node* newnode=createnode(n);
        if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        struct node *temp = first;
        while (temp->data != data && temp != NULL)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void print()
{
     struct node *temp=first;
     if(first==NULL)
     {
         printf("empty");
     }
     else{
     while(temp!=NULL)
     {
         printf("%d\t",temp->data);
         temp=temp->next;
     }    
     }
     printf("\n");
     
}
void insertbef(int data){
    int newdata;
    printf("Enter the value of the node: ");
    scanf("%d", &newdata);
     struct node *temp=first;
    struct node *newNode = createnode(newdata);

    if (first == NULL)
    {
        first = newNode;
    }
    else if (first->data == data)
    {
        newNode->next = first;
        first = newNode;
    }
    else
    {
        while(temp->next->data!=data&&temp!=NULL)
        {
            temp=temp->next;
            
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void delete(int data)
{
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = first, *del = NULL;
        if (first->data == data)
        {
            del = first;
            first = first->next;
            free(del);
            printf("Element is deleted\n");
        }
        else
        {
            while (temp->next != NULL && temp->next->data != data)
            {
                temp = temp->next;
            }

            if (temp->next != NULL)
            {
                del = temp->next;
                temp->next = temp->next->next;
                free(del);
                printf("Element is deleted\n");
            }
            else
            {
                printf("Element not found\n");
            }
        }
    }
}

void deletesmall()
{
    struct node *temp=first,*del=NULL;
    int s=first->data;
    while(temp->next!=NULL)
    {
        if(s>temp->data)
        {
            s=temp->data;
            
        }
           temp=temp->next;
        
    }
    printf("\n\t\tsmallest is %d",s);
    delete(s);
    
}
void displayy(struct node*head)
{
     struct node *temp=head;
     if(head==NULL)
     {
         printf("empty");
     }
     else{
     while(temp!=NULL)
     {
         printf("%d\t",temp->data);
         temp=temp->next;
     }    
     }
     printf("\n");
}
struct node *reverse()
{
    struct node *pres=first;
    struct node *prev=NULL;
    struct node *n=first->next;
    while(pres!=NULL)
    {
        pres->next=prev;
        prev=pres;
        pres=n;
        if(n!=NULL)
        {
            n=n->next;
        }
    }
    return prev;
    
}

void sort()
{
    struct node *temp=first;
    int t,j;
    do{
        t=0;
        while(temp->next!=NULL &&temp!=NULL){
            if(temp->data > temp->next->data)
            {
           j=temp->data;
           temp->data=temp->next->data;
           temp->next->data=j;
           t=1;
            }temp=temp->next; 
      }temp=first;
       
    }
    while(t);
}







int main()
{
    int choice,data,val,pos;
    
    do{
    printf("\n\t\t1)insert");
    printf("\n\t\t2)insert after element");
    printf("\n\t\t3)insert before");
    printf("\n\t\t4)insert at pos");
    printf("\n\t\t5)delete ");
    printf("\n\t\t6)sort");
    printf("\n\t\t7)delete small ");
   printf("\n\t\t8)print ");
    printf("\n\t\t9)Exit"); 
    printf("\n\t\tINPUT CHOICE");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\n\t\tinput val");
        scanf("%d",&data);
        insert(data);
        break;
        
        case 2:
        printf("\n\t\tinput val");
        scanf("%d",&val);
        insertaf(val);
        break;
        case 3:
         printf("\n\t\tinput val");
        scanf("%d",&val);
        insertbef(val);
        break;
        case 4:
        struct node *rev=reverse();
        displayy(rev);
        break;
        case 5:
        printf("\n\t\tinput val");
        scanf("%d",&data);
        delete(data);
        break;
        case 6:
        sort();
        break;
        case 7:
        
        deletesmall();
        break;
        case 8:
        print();
        break;
        case 9:
        printf("Exiting the program.\n");
        break;
        default:
        printf("Invalid choice, please choose again.\n");
        }
    }while(choice!=9);
    return 0;
}
     
    
