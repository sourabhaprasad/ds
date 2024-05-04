#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

void create()
{
    int choice = 1;
    head = 0;
    while (choice)
    {
        // Allocating memory for new node
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            // If list is empty, new node becomes head
            head = temp = newnode;
        }
        else
        {
            // Adding new node at the end of the list
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you wish to continue? ");
        scanf("%d", &choice);
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        // Displaying data of each node
        printf("%d   ", temp->data);
        temp = temp->next;
    }
}

void remove_duplicates(struct node *head)
{
    if (head == NULL)
        return;

    struct node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // Removing duplicate node
            struct node *temp1 = curr->next;
            curr->next = curr->next->next; // remove by skipping it
            free(temp1);                   // Freeing memory of duplicate node
        }
        else
        {
            curr = curr->next; // move to the next node if there are no duplicates
        }
    }
}

int main()
{
    create();
    printf("Original Sorted SLL: ");
    display();
    printf("\nAfter removing duplicates: ");
    remove_duplicates(head);
    display();
    return 0;
}
