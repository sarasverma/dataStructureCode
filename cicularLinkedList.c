#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *temp2, *new, *prev;
int choice, key;

void create()
{
    if (head != NULL)
    {
        puts("List already exists");
        return;
    }

    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d", &new->data);
    new->next = new;
    head = new;
}

void insert()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d", &new->data);

    puts("1.Beg 2.End 3.Random location");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        new->next = head;
        // make last node point to new head
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new;
        head = new;
        break;

    case 2:
        new->next = head;
        // make previous node point new end
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new;
        break;

    case 3:
        puts("Enter key after which you want to insert");
        scanf("%d", &key);
        temp = head;
        while (temp->data != key)
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
        break;
    default:
        puts("Invalid choice");
    }
}

void delete ()
{
    puts("1.Beg 2.End 3.Random location");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        temp = head;
        temp2 = head;
        // make end point to new head
        while (temp2->next != head)
            temp2 = temp2->next;
        temp2->next = head->next;
        head = head->next;
        printf("deleted element : %d \n", temp->data);
        free(temp);
        break;

    case 2:
        temp = head;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        printf("deleted element :%d \n", temp->data);
        free(temp);
        break;

    case 3:
        puts("Enter key to be deleted :");
        scanf("%d", &key);

        temp = head;
        while (temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("deleted element :%d \n", temp->data);
        free(temp);
        break;
    default:
        puts("Invalid choice");
    }
}

void display()
{
    if (head == NULL)
        puts("List doesn't exist");
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        // for last element
        printf("%d\t", temp->data);
        printf("\n");
    }
}

int main()
{

    while (1)
    {
        puts("1.CREATE 2.INSERT 3.DELETE 4.DISPLAY 5.EXIT");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            insert();
            break;

        case 3:
            delete ();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}