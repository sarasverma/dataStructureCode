#include <stdio.h>

#define max 10

int queue[max], front = -1, rear = -1, count = 0;
// count is used as counter

void enqueue()
{
    if (count == max)
        puts("Overflow");
    else
    {
        if (front == -1)
            front++;

        rear = (rear + 1) % max;
        printf("enter the data :");
        scanf("%d", &queue[rear]);
        count++;
    }
}

void dequeue()
{
    if (count == 0)
        puts("Underflow");
    else
    {
        printf("deleted element %d \n", queue[front]);
        front = (front + 1) % max;
        count--;
    }
}

void display()
{
    int i, j = front;
    if (count == 0)
        puts("Queue is empty");
    else
    {
        for (i = 0; i < count; i++)
        {
            printf("%d\t", queue[j]);
            j = (j + 1) % max;
        }
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