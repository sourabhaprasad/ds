#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack[N];
int top = -1;
int undo_stack[N];
int undo_top = -1;

void push(int x)
{
    if (top == N - 1)
    {
        printf("Overflow!");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow!");
        return -1; // Returning -1 indicating error
    }
    else
    {
        int item = stack[top];
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
        int x = pop();
        if (x != -1)
        { // If pop operation is successful
            undo_top++;
            undo_stack[undo_top] = x;
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
        int x = undo_stack[undo_top];
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
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, x;
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
            scanf("%d", &x);
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
