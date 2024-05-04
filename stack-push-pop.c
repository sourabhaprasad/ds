#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;

void push(){
    if(top==N-1){
        printf("Overflow!");
    }
    else{
        int x;
        printf("Enter data to be inserted: ");
        scanf("%d",&x);
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        int item;
        item = stack[top];
        printf("The popped item is : %d", item);
        top--;
    }
}

void display(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        int i;
        printf("The elements in the stack are: ");
        for(i=top;i>=0;i--){
            printf("%d    ",stack[i]);
        }
    }
}



void main() {
    int choice;
    while(1){
        printf("\nThe operations on stack are: ");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid Choice!\n");
        }
    }
}