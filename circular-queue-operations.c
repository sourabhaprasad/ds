#include <stdio.h>
#include <stdlib.h>
#define N 3
int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    if ((rear + 1) % N == front)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter an element: ");
        scanf("%d", &x);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = x;
        }
        else
        {
            rear = (rear + 1) % N;
            queue[rear] = x;
        }
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow!");
    }
    else if (front == rear)
    {
        printf("The dequeued element is %d", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The dequeued element is %d", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow!");
    }
    else
    {
        int i;
        i = front;
        printf("Circular Queue is ");
        while (i != rear)
        {
            printf("%d  ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\nQueue Operations are:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
        }
    }
}