#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    // Construct the binary tree manually
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Display the constructed binary tree
    printf("Constructed binary tree:\n");
    printf("     %d\n", root->data);
    printf("    / \\\n");
    printf("   %d   %d\n", root->left->data, root->right->data);
    printf("  / \\ \n");
    printf(" %d   %d\n", root->left->left->data, root->left->right->data);

    return 0;
}
