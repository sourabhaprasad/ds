#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *left;
    struct node *right;
};

struct node *newNode(char data[])
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data, data);
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, char data[])
{
    if (root == NULL)
        return newNode(data);

    // Insert at left or right randomly
    if (rand() % 2 == 0)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct node *delete(struct node *root, char data[])
{
    if (root == NULL)
        return root;
    if (strcmp(data, root->data) == 0)
    {
        free(root);
        return NULL; // Deleting current node
    }

    // Recursively delete in left and right subtrees
    root->left = delete (root->left, data);
    root->right = delete (root->right, data);

    return root;
}

void printPlaylist(struct node *root)
{
    if (root != NULL)
    {
        printPlaylist(root->left);
        printf("%s\n", root->data);
        printPlaylist(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    char data[100];
    int choice;

    while (1)
    {
        printf("\n1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Display playlist\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter song to add: ");
            scanf("%s", data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter song to remove: ");
            scanf("%s", data);
            root = delete (root, data);
            break;
        case 3:
            printf("Playlist:\n");
            printPlaylist(root);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
