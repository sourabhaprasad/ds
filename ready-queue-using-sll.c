#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int process_id;
    struct Process *next;
};

struct Process *front = NULL;
struct Process *rear = NULL;

// Function to add a process to the rear of the queue (enqueue)
void enqueue(int process_id)
{
    struct Process *newProcess = (struct Process *)malloc(sizeof(struct Process));
    newProcess->process_id = process_id;
    newProcess->next = NULL;
    if (rear == NULL)
    {
        // If the queue is empty, set both front and rear to the new process
        front = rear = newProcess;
    }
    else
    {
        // Add the new process to the rear and update the rear pointer
        rear->next = newProcess;
        rear = newProcess;
    }
}

// Function to remove a process from the front of the queue (dequeue)
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Process *temp = front;
    front = front->next;
    // If front becomes NULL, set rear to NULL as well
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}

// Function to display all processes in the queue
void display()
{
    struct Process *temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Processes in the queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->process_id);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // Adding processes to the queue
    enqueue(101);
    enqueue(102);
    enqueue(103);

    // Displaying the initial queue
    printf("Initial Queue: ");
    display();

    // Removing a process from the front of the queue
    dequeue();
    printf("Queue after removing front process: ");
    display();

    return 0;
}
