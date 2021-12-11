#include <stdio.h>

#define MAX_SIZE 10

struct stack
{
    int top;
    int arr[MAX_SIZE];
};

void display(struct stack *s)
{
    if (s->top == -1)
        puts("No element to display stack is empty");

    else
    {
        int i;
        puts("The stacks is");
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}

void push(struct stack *s, int element)
{
    if (s->top == MAX_SIZE - 1)
        puts("OVERFLOW");
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}

int pop(struct stack *s)
{
    int element;
    if (s->top == -1)
        puts("UNDERFLOW");
    else
    {
        element = s->arr[s->top];
        s->top--;
        return element;
    }
    return NULL;
}

void main()
{
    struct stack s;
    int element, deletedElement, choice;
    s.top = -1;

    while (1)
    {
        puts("1. Display");
        puts("2. Push");
        puts("3. Pop");
        puts("4. Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(&s);
            break;

        case 2:
            puts("Enter the element to push");
            scanf("%d", &element);

            push(&s, element);
            break;

        case 3:
            deletedElement = pop(&s);
            printf("The element deleted is : %d\n", deletedElement);
            break;

        case 4:
            exit(1);

        default:
            puts("Enter a valid choice");
            break;
        }
    }
}