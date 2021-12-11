#include <stdio.h>

#define max 10

int queue[max], front = -1, rear = -1;

void enqueue()
{
    if (rear == max - 1)
        puts("Overflow");
    else
    {
        if (front == -1)
            front++;

        rear++;
        printf("enter the data :");
        scanf("%d", &queue[rear]);
    }
}

void dequeue()
{
    if (front > rear || front == -1)
        puts("Underflow");
    else
    {
        printf("deleted element %d \n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front > rear || front == -1)
        puts("Queue is empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        puts("1.ENQUEUE 2.DEQUEUE 3.DISPLAY 4.EXIT");
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
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}