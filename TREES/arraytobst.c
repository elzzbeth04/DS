#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a tree node */
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Function to create a new tree node */
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Recursive function to construct a Balanced BST from a sorted array */
struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) // Base case: Empty range, return NULL
        return NULL;

    // Calculate the middle index
    int mid = (start + end) / 2;

    // Create a new node with the middle element as the root
    struct TreeNode* root = newNode(arr[mid]);

    // Recursively construct the left subtree from elements before the middle element
    root->left = sortedArrayToBST(arr, start, mid - 1);

    // Recursively construct the right subtree from elements after the middle element
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root; // Return the root of the constructed BST
}

/* Function to perform an in-order traversal of a BST (for testing purposes) */
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/* Main function */
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert the sorted array to a Balanced BST
    struct TreeNode* root = sortedArrayToBST(arr, 0, n - 1);

    // Perform an in-order traversal to verify the BST
    printf("In-order Traversal of constructed BST: ");
    inOrder(root);

    return 0;
}
