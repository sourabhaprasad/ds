#include <stdio.h>
#include <stdlib.h>

// Structure for a node of BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void displayInorder(struct Node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 12);

    // Displaying BST
    printf("Inorder traversal of BST: ");
    displayInorder(root);
    printf("\n");

    return 0;
}
