#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node* next;
	struct node* prev;
};
struct node *createnode(char c)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=c;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}


struct node* head = NULL;
struct node* tail = NULL;

void main(){
	printf("Enter str: ");
	char str[50];
	scanf("%s", str);
	int len = 0, flag = 0, count = 0;
	
	for(int i = 0; str[i] != '\0'; i++){
		struct node *newNode = createnode(str[i]);
	
		if(head == NULL){
			head = tail = newNode;
		
		}
		else{
			tail -> next = newNode;
			newNode -> prev = tail;
			tail = newNode;
			
		}
		len++;
	}
	
	if(len % 2 == 0){
		int mid = len / 2;
		while(count != mid){
			if(head -> data != tail -> data){
				flag = 1;
				break;
			}
			head = head -> next;
			tail = tail -> prev;
			count++;
		}
// 		if(flag == 0){
// 			if(head -> data != tail -> data){
// 				flag = 1;
// 			}
// 		}
	}
	else{
		int mid = (len / 2) + 1;
		while(count != mid){
			if(head -> data != tail -> data){
				flag = 1;
				break;
			}
			head = head -> next;
			tail = tail -> prev;
			count++;
		}
	}
	
	if(flag == 0){
		printf("Palindrome\n");
	}
	else{
		printf("Not Palindrome\n");
	}
}