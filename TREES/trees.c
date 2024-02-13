#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
int rear =-1,front=-1;
struct node *queue[20];
struct node *create(int v)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=v;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}

struct node *insert(struct node *root,int v)
{
    if(root==NULL)
    return create(v);
    else if(v<root->data)
    {
        root->left=insert(root->left,v);
    }
    else
    {
        root->right=insert(root->right,v);
    }
    return root;
    
}
struct node *findmin(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
struct node *delete(struct node *root,int val)
{
    if(root==NULL)
    return root;
    else if(root->data<val)
    {
        root->right=delete(root->right,val);
    }
    else if(root->data>val)
    root->left=delete(root->left,val);
    else
    {
        if(root->right==NULL && root->left==NULL)
        {
            struct node *temp=root;
            free (temp);
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
             free(temp);
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free (temp);
        }
        else
        {
            struct node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\t%d",root->data);
        inorder(root->right);
    }
    
}


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
    temp=queue[front];
    if(front==rear)
    {
        front=rear=-1;
        
    }
    else front=front+1;
    
  return temp;  
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
        printf("%d\t",temp->data);
        if(temp->left!=NULL)
        enqueue(temp->left);
        if(temp->right!=NULL)
        enqueue(temp->right);
        
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("\t%d",root->data);
         preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        
         postorder(root->left);
        postorder(root->right);
        printf("\t%d",root->data);
    }
}
void main()
{
   int n,val,d;
   struct node *root=NULL;
   printf("\nenter number");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&val);
       root=insert(root,val);
   }
   printf("\npreorder");
   preorder(root);
   printf("\npostorder");
   postorder(root);
   printf("\ninorder\t");
   inorder(root);
   printf("\n");
   levelorder(root);
  printf("\nenter val to delete");
    scanf("%d",&d);
   
   root=delete(root,d);
  
   printf("\npreorder");
   preorder(root);
   printf("\npostorder");
   postorder(root);
   printf("\ninorder");
   inorder(root);
   
   
   
}