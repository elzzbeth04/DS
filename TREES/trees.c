#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct  node *lchild;
    struct node *rchild;
};
struct node *new_node,*root=NULL,*queue[20];
int rear =-1,front=-1;
void enqueue(struct node *root)
{
    if(front==-1)
    {
        front=0;
       queue[++rear]=root;
       
    }
    else
    queue[++rear]=root;
}
struct node *dequeue()
{
    struct node *temp;
    if(front!=rear)
    {
        return queue[front++];
    }
    else
    {
        temp=queue[front];
        front=rear=-1;
        return temp;
    }
}
struct node* create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        new_node = create(data);
        root = new_node;
    } else if (data <= root->data)
        root->lchild = insert(root->lchild, data);
    else
        root->rchild = insert(root->rchild, data);
    return root;
}
void preorder(struct node *ptr)
{
    if (ptr!=NULL)
    {
    printf("%d \t",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
    }
}
void postorder(struct node *ptr)
{
    if (ptr!=NULL)
    {
    postorder(ptr->lchild);
    postorder(ptr->rchild);
     printf("%d \t",ptr->data);
    }
}
void inorder(struct node *ptr)
{
    if (ptr!=NULL)
    {
    inorder(ptr->lchild);
      printf("%d \t",ptr->data);
    inorder(ptr->rchild);
    }
   
}
void levelorder(struct node *root)
{
     struct node *temp;
    if(root==NULL)
    return;
    enqueue(root);
    while(front!=-1)
    {
       temp=dequeue();
        printf("%d",temp->data);
        if(temp->lchild!=NULL)
        enqueue(temp->lchild);
        if(temp->rchild!=NULL)
        enqueue(temp->rchild);
        
    }
}
struct node *findmin(struct node *root)
{
    while(root->lchild!=NULL)
    {
        root=root->lchild;
        return root;
    }
}
struct node *delete(struct node *root,int value )
{
      struct node *temp;
    if(root==NULL)
    {
        return NULL;
    }
    else if(value<root->data)
    {
        root->lchild=delete(root->lchild,value);
    }
    else if(value>root->data)
    {
        root->rchild=delete(root->rchild,value);
    }
    else
    {
        if(root->lchild==NULL&&root->rchild==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->lchild==NULL)
        {
            temp=root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL)
        {
            temp=root->lchild;
            free(root);
            return temp;
        }
        else
        {
        temp=findmin(root->rchild);
            root->data=temp->data;
            root->rchild=delete(root->rchild,temp->data);
        }
    }
    return root;
    
}
int main()
{
    char choice,n,i,d;
    int ch;
    do{
            printf("\n\t\t 1) Insert Element(s)");
            printf("\n\t\t 2) Inorder Traversal");
        	printf("\n\t\t 3) Preorder Traversal");
        	printf("\n\t\t 4) Postorder Traversal");
        	printf("\n\t\t 5) Levelorder Traversal");
        	printf("\n\t\t 6) Delete Element");
            printf("\n\t\tinput choice");
             scanf("%d",&ch);
             switch(ch)
                 {
                  case 1:
                printf("\nEnter The Number Of Elements: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter The Data: ");
                    int d;
                    scanf("%d", &d);
                    root = insert(root, d);
                }
                break;
			case 2:
                printf("Inorder Traversal: ");
				inorder(root);
				break;
			case 3:
                printf("Preorder Traversal: ");
				preorder(root);
				break;
			case 4:
                printf("Postorder Traversal: ");
				postorder(root);
				break;
			case 5:
                printf("Levelorder Traversal: ");
				levelorder(root);
				break;
            case 6:
                printf("Enter The Element To Be Deleted: ");
                scanf("%d", &n);
               delete(root, n);
                printf("Element Deleted!\n");
                break;
                
                default:
                printf("INVALID");
                 }printf("do you want to continue?");
         scanf("%s",&choice);
    }while(choice=='y'||choice=='Y');
    return 0;

    }