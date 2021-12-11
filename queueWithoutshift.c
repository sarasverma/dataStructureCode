//fixed size.
#include <stdio.h>

#define MAX_SIZE 50
//queue ADT.
struct queue
{
    int front;
    int rear;
    int arr[MAX_SIZE];
};

int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
        return 1;
    // else return false.
    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == MAX_SIZE - 1)
        return 1;
    // else return false.
    return 0;
}

void display(struct queue *q)
{
    int i;
    if (isEmpty(q))
    {
        puts("The queue is Empty.");
    }
    else
    {
        for (i = (q->front + 1); i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void enqueue(struct queue *q, int element)
{
    if (isFull(q))
        puts("Overflow");
    else
    {
        (q->rear)++;
        q->arr[q->rear] = element;
    }
}

int dequeue(struct queue *q)
{
    int element;
    if (isEmpty(q))
        puts("Underflow");
    else
    {
        (q->front)++;
        element = q->arr[q->front];
        return element;
    }
}

void main()
{
    struct queue *q;
    // intitate the queqe.
    q->front = -1;
    q->rear = -1;

    // for menu.
    int choice, insertElement, deletedElement;

    while (1)
    {
        puts("Enter a choice :");
        puts("1. Display");
        puts("2. Enqueue");
        puts("3. Dequeue");
        puts("4. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(q);
            break;

        case 2:
            puts("Enter element to be inserted :");
            scanf("%d", &insertElement);
            enqueue(q, insertElement);
            break;

        case 3:
            deletedElement = dequeue(q);
            printf("The deleted element is : %d\n", deletedElement);
            break;

        case 4:
            exit(0);
            break;

        default:
            puts("Invalid choice");
            break;
        }
    }
}
