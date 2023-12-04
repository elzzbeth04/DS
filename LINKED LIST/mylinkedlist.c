
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void addElement(int data)
{
    struct node *newNode = createNode(data);
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp = first;
        printf("Head");
        while (temp != NULL)
        {
            printf("%d\t->", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void addafterele(int data)
{
    int newdata;
    printf("Enter the value of new data: ");
    scanf("%d", &newdata);
    struct node *newNode = createNode(newdata);

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while (temp->data != data && temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void addbefore(int data)
{
    int newdata;
    printf("Enter the value of the node: ");
    scanf("%d", &newdata);
    struct node *newNode = createNode(newdata);

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
        struct node *temp = first;
        while (temp->next != NULL && temp->next->data != data)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void addatposition(int index)
{
    int newdata, i;
    struct node *temp = first;
    printf("Enter the value of the new node: ");
    scanf("%d", &newdata);
    struct node *newNode = createNode(newdata);

    if (index == 0)
    {
        newNode->next = temp;
        first = newNode;
    }
    else
    {
        for (i = 1; i < index && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            printf("Invalid index\n");
        }
    }
}

void deletenode(int data)
{
    struct node *temp=first,*del=NULL;
    if(first->data==data)
    {
        del=first;
        first=first->next;
        free(del);
        printf("\ndeleted");
        
    }
    else if(first==NULL)
    printf("empty");
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
void deleteindex(int index)
{
   
    int i;
   struct node *del=NULL;
    if(first==NULL)
    printf("\n not");
    else if(index==0)
    {
        del=first;
        first=first->next;
        free(del);
    }
    else
    {
         struct node *temp=first;
        for(int i=1;i<index &&temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            del=temp->next;
            temp->next=temp->next->next;
            free(del);
        }
        else
        printf("not");
        
    }
    
}
void deletesmall()
{
    if(first==NULL)
    {
        printf("empty");
        
    }
    else
    {
      int  smallest=first->data;
        struct node *dtemp=first;
        while(dtemp!=NULL)
        {
            if(smallest>dtemp->data)
            {
                smallest=dtemp->data;
            }
            dtemp=dtemp->next;
        }
        printf("%d",smallest);
        struct node *temp=first,*del=NULL;
        if(first->data==smallest)
        {
            del=first;
            first=first->next;
            free(del);
        }
        else
        {
            while(temp->next!=NULL & temp->next->data!=smallest)
            {
              temp=temp->next;
            }
            if(temp->next!=NULL)
            {
                del=temp->next;
                temp->next=temp->next->next;
                free(del);
              //  break;
            }
            else
            printf("mot");
        }
    }
}
void search(int data)
{
    struct node *temp=first;
    int c=0;
    while(temp->next!=NULL&&temp->data!=data)
    {
        temp=temp->next;
        c++;
    }
    if(temp->data==data)
    {
        printf("foundt%d",c);
    }
}
int main()
{
    int choice;
    char c;
    do
    {
        int data;
        printf("1: Add Element\n");
        printf("2: Display Element\n");
        printf("3: Delete a particular Element\n");
        printf("4: Insert after a node\n");
        printf("5: Insert before a node\n");
        printf("6: Add at a particular position\n");
        printf("7: Delete an element at a particular index\n");
        printf("8: Delete smallest\n");
        printf("9: Search for an element\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            addElement(data);
            break;

        case 2:
            printf("Displaying the elements\n");
            display();
            break;

        case 3:
            printf("Delete an element\n");
            printf("Enter the value from the user: ");
            scanf("%d", &data);
            deletenode(data);
            break;

        case 4:
            printf("Insert after\n");
            printf("Enter the value from the user: ");
            scanf("%d", &data);
            addafterele(data);
            break;

        case 5:
            printf("Insert before\n");
            printf("Enter the value from the user: ");
            scanf("%d", &data);
            addbefore(data);
            break;

        case 6:
            printf("Add at a particular position\n");
            printf("Enter the index from the user: ");
            scanf("%d", &data);
            addatposition(data);
            break;

        case 7:
            printf("Delete an element at a particular index\n");
            printf("Enter the index to be deleted from the user: ");
            scanf("%d", &data);
          deleteindex(data);
            break;

        case 8:
            printf("Delete smallest\n");
         deletesmall();
            break;

        case 9:
            printf("Search for an element\n");
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
          search(data);
            break;
        }

        printf("\nDo you want to continue (input y or n): ");
        scanf(" %c", &c);
    } while (c == 'y');

}