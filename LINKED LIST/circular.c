#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL, *last = NULL;

typedef struct node n;

struct node *createnode(int info) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = info;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void insertfront() {
    int info;
    struct node *new;
    printf("input value for info: ");
    scanf("%d", &info);
    new = createnode(info);

    if (first == last && first == NULL) {
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
    }
}

void insertend() {
    int info;
    struct node *new;
    printf("input the value: ");
    scanf("%d", &info);
    new = createnode(info);

    if (first == last && first == NULL) {
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}

void deleterear() {
    if (first == last && first == NULL) {
        printf("\ncannot delete");
    } else {
        n *temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }
        if (first == last) {
            first = last = NULL;
        } else {
            temp->prev->next = first;
            first->prev = temp->prev;
            last = temp->prev;
        }
        printf("\ndeleted node will be");
        free(temp);
    }
}

void deletefront() {
    n *temp;
    if (first == last && first == NULL) {
        printf("cannot delete");
    } else {
        temp = first;
        if (first->next == first) {
            first = last = NULL;
        } else {
            first = first->next;
            first->prev = last;
            last->next = first;
        }
        printf("\nthe deleted");
        free(temp);
    }
}

void display() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = first;

    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != first);

    printf("\n");
}

int main(void) {
    int ch;
    char choice;
    do {
        printf("\n1: insertfront");
        printf("\n2: insertend");
        printf("\n3: deletefront");
        printf("\n4: deleterear");
        printf("\n5: display");
        printf("\nInput choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            insertfront();
            break;
        case 2:
            insertend();
            break;
        case 3:
            deletefront();
            break;
        case 4:
            deleterear();
            break;
        case 5:
            display();
            break;
        }
        printf("\ndo you want to continue? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume the newline character
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
