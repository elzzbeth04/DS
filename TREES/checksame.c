#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BST Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root1;
struct Node *root2;

// Utility function to create new Node
struct Node *newNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *insert(struct Node *root,int v)
{
    if(root==NULL)
    return newNode(v);
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

// Function to insert elements of the tree to an array
void storeInorder(struct Node *root, int arr[], int *index)
{
    if (root==NULL)
        return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    storeInorder(root->right, arr, index);
}

// Function to check if the two BSTs contain the same set of elements
bool checkBSTs(struct Node *root1, struct Node *root2)
{
    // Base cases
    if (root1==NULL && root2==NULL)
        return true;
    if ((root1!=NULL && root2==NULL) || (root1==NULL && root2!=NULL))
        return false;

    int arr1[100], arr2[100];
    int index1 = 0, index2 = 0;

    // Store inorder traversals of both BSTs in arrays
    storeInorder(root1, arr1, &index1);
    storeInorder(root2, arr2, &index2);

    // Return false if sizes of arrays are different
    if (index1 != index2)
        return false;

    // Check if both arrays are identical
    for (int i = 0; i < index1; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }

    return true;
}

// Driver program to check above functions
int main()
{
    // First BST
    int n,n2,val;
     printf("\nenter number");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&val);
       root1=insert(root1,val);
   }
    printf("\nenter number");
   scanf("%d",&n2);
   for(int i=0;i<n2;i++)
   {
       scanf("%d",&val);
       root2=insert(root2,val);
   }
    
    // Check if two BSTs have the same set of elements
    if (checkBSTs(root1, root2))
        printf("YES");
    else
        printf("NO");
    return 0;
}
