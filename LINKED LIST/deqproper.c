// without init 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *createnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void addfront(int data) {
    struct node *newnode = createnode(data);
    if (front == NULL) {
        front = rear = newnode;
    } else {
        newnode->next = front;
        front->prev = newnode;
        front = newnode;
    }
}

void addrear(int data) {
    struct node *newnode = createnode(data);
    if (front == NULL) {
        front = rear = newnode;
    } else {
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
    }
}

int removefront() {
    if (front == NULL) {
        printf("\n Empty");
        return -1;
    }
    int data = front->data;
    struct node *temp = front;
    if (front->next)
     {
        front = front->next;
        front->prev = NULL;
    } else {
        front = rear = NULL;//after removal if no element is there
    }
    free(temp);
    return data;
}

int removerear() {
    if (front == NULL) {
        printf("\n Empty list");
        return -1;
    }
    int data = rear->data;
    struct node *temp = rear;
    if (rear->prev) {
        rear = rear->prev;
        rear->next = NULL;
    } else {
        front = rear = NULL;
    }
    free(temp);
    return data;
}

void displaydeq() {
    struct node *current = front;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int ch, data;
    char choice;

    do {
        printf("\n1: addfront");
        printf("\n2: addrear");
        printf("\n3: removefront");
        printf("\n4: removerear");
        printf("\n5: display");
        printf("\n6: exit");
        printf("\nInput choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Input the data: ");
                scanf("%d", &data);
                addfront(data);
                break;
            case 2:
                printf("Input the data: ");
                scanf("%d", &data);
                addrear(data);
                break;
            case 3:
                printf("THE DATA REMOVED FROM FRONT IS %d", removefront());
                break;
            case 4:
                printf("THE DATA REMOVED FROM REAR IS %d", removerear());
                break;
            case 5:
                displaydeq();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
