#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for string operations
#define N 5

char stack[N][100];
int top = -1;
char undo_stack[N][100];
int undo_top = -1;

void push(char *x)
{
    if (top == N - 1)
    {
        printf("Overflow!");
    }
    else
    {
        top++;
        strcpy(stack[top], x);
    }
}

char *pop()
{
    if (top == -1)
    {
        printf("Underflow!");
        return NULL; // Returning NULL indicating error
    }
    else
    {
        char *item = stack[top];
        top--;
        return item;
    }
}

void undo()
{
    if (top == -1)
    {
        printf("No operation to undo!\n");
    }
    else
    {
        char *x = pop();
        if (x != NULL)
        { // If pop operation is successful
            undo_top++;
            strcpy(undo_stack[undo_top], x);
            printf("Undo successful.\n");
        }
    }
}

void redo()
{
    if (undo_top == -1)
    {
        printf("No operation to redo!\n");
    }
    else
    {
        char *x = undo_stack[undo_top];
        undo_top--;
        push(x);
        printf("Redo successful.\n");
    }
}

void display()
{
    if (top == -1)
    {
        printf("Underflow!");
    }
    else
    {
        printf("The elements in the stack are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%s ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    char x[100];
    while (1)
    {
        printf("\nThe operations on stack are: ");
        printf("\n1.Push\n2.Pop\n3.Undo\n4.Redo\n5.Display\n6.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%s", x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            undo();
            break;
        case 4:
            redo();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
