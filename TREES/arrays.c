#include <stdio.h>

// Global variable to store the number of nodes in the complete binary tree
int complete_node = 15;

// Array to store the binary tree
char tree[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0', '\0', 'J', '\0', 'K', 'L'};

// Function to get the index of the right child of a given node
int get_right_child(int index) {
    // Check if the node is not null and if the index of the right child is within the bounds of the tree
    if (tree[index] != '\0' && ((2 * index) + 2) <= complete_node)
        return (2 * index) + 2; // Return the index of the right child
    else
        return -1; // Right child doesn't exist
}

// Function to get the index of the left child of a given node
int get_left_child(int index) {
    // Check if the node is not null and if the index of the left child is within the bounds of the tree
    if (tree[index] != '\0' && (2 * index + 1) <= complete_node)
        return 2 * index + 1; // Return the index of the left child
    else
        return -1; // Left child doesn't exist
}

// Preorder traversal function
void preorder(int index) {
    // Check for a valid index and non-null node
    if (index >= 0 && tree[index] != '\0') {
        printf(" %c ", tree[index]); // Visit the root node
        preorder(get_left_child(index)); // Traverse the left subtree
        preorder(get_right_child(index)); // Traverse the right subtree
    }
}

// Postorder traversal function
void postorder(int index) {
    // Check for a valid index and non-null node
    if (index >= 0 && tree[index] != '\0') {
        postorder(get_left_child(index)); // Traverse the left subtree
        postorder(get_right_child(index)); // Traverse the right subtree
        printf(" %c ", tree[index]); // Visit the root node
    }
}

// Inorder traversal function
void inorder(int index) {
    // Check for a valid index and non-null node
    if (index >= 0 && tree[index] != '\0') {
        inorder(get_left_child(index)); // Traverse the left subtree
        printf(" %c ", tree[index]); // Visit the root node
        inorder(get_right_child(index)); // Traverse the right subtree
    }
}

int main() {
    printf("Preorder:\n");
    preorder(0); // Start preorder traversal from the root
    printf("\nPostorder:\n");
    postorder(0); // Start postorder traversal from the root
    printf("\nInorder:\n");
    inorder(0); // Start inorder traversal from the root
    printf("\n");
    return 0;
}
