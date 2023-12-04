#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node* next;
	struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node *createnode(char c)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=c;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}


void insert(struct node *newNode)
{
  
		if(head == NULL){
			head = tail = newNode;
		
		}
		else{
			tail -> next = newNode;
			newNode -> prev = tail;
			tail = newNode;
			
		}
		 
}
int ispali(struct node *head,struct node *tail)
{
    while(head!=NULL&&tail!=NULL)
    {
        if(head->data!=tail->data)
        {
            return 0;
           
        }
       head=head->next;
       tail=tail->prev;
    }
    return 1;
}

void main(){
	printf("Enter str: ");
	char str[50];
	scanf("%s", str);
int len = 0, count = 0, flag = 0;
	for(int i = 0; str[i] != '\0'; i++){
		struct node *newNode = createnode(str[i]);
		insert(newNode);
	len++; 
	}
	

	if(ispali(head,tail)==1)

		printf("Palindrome\n");
	
	else if(ispali(head,tail)==0){
		printf("Not Palindrome\n");
	}
}
/*The ispali function is attempting to use the global variables head and tail, but these variables are already declared globally.
 It's better to pass them as parameters.

In the ispali function, you are modifying the head and tail pointers within the loop. This will result in losing the original 
pointers and may cause issues when you later try to print or use the list.
*/