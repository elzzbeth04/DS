#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int treeSize = 7; // Assuming 7 nodes in the tree

// Function to print the array representation of a binary tree

void printArrayRepresentation(int tree[], int n) {
    printf("Array Representation of Binary Tree: ");
    for (int i = 0; i < n; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

// Function to set a node at a specific index in the binary tree
void setNode(int tree[], int index, int value) {
    tree[index] = value;
}

// Function to set the left child of a node at a specific index
void setLeftChild(int tree[], int parentIndex, int value) {
    if (0<=parentIndex<=treeSize)
    {
    int leftChildIndex = 2 * parentIndex + 1;
    if (leftChildIndex < treeSize) {
        setNode(tree, leftChildIndex, value);
    } else {
        printf("Left child index out of bounds.\n");
    }
    }
    else
       printf("Invalid Parent Index");
}

// Function to set the right child of a node at a specific index
void setRightChild(int tree[], int parentIndex, int value) {
    if (0<=parentIndex<=treeSize)
    {
    int rightChildIndex = 2 * parentIndex + 2;
    if (rightChildIndex < treeSize) {
        setNode(tree, rightChildIndex, value);
    } else {
        printf("Right child index out of bounds.\n");
    }
    }
    else
       printf("Invalid Parent Index");
}

int main() {
    // Example binary tree
    //     1
    //    / \
    //   2   3
    //  / \     \
    // 4   5    6

   
    int binaryTree[] = {-1, -1, -1, -1, -1, -1, -1}; // Initialize with -1 for empty nodes

    // Set nodes
    setNode(binaryTree, 0, 1);
    setNode(binaryTree, 1, 2);
    setNode(binaryTree, 2, 3);

    // Set left and right children
    setLeftChild(binaryTree, 1, 4);
    setRightChild(binaryTree, 1, 5);
    setRightChild(binaryTree, 2, 6);
    // Print array representation
    printArrayRepresentation(binaryTree, treeSize);

    return 0;
}