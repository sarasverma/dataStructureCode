#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *new, *prev;
int choice, key;

void create()
{
    if (head != NULL)
    {
        printf("List already exist");
        return;
    }
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = NULL;
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
        new->prev = NULL;
        new->next = head;
        head->prev = new;
        // head point to new head
        head = new;
        break;

    case 2:
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        new->prev = temp;
        new->next = NULL;

        temp->next = new;
        break;

    case 3:
        printf("Enter key after to be inserted :");
        scanf("%d", &key);

        temp = head;
        while (temp->data != key)
            temp = temp->next;
        new->prev = temp;
        new->next = temp->next;
        // adjustment to neighbouring nodes
        if (temp->next != NULL)
            temp->next->prev = new;
        temp->next = new;
        break;

    default:
        puts("Invalid choice");
        break;
    }
}

// modify from herews
void delete ()
{
    puts("1.Beg 2.End 3.Random location");
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("deleted element %d\n", temp->data);
        free(temp);
        break;

    case 2:
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("deleted element %d\n", temp->data);
        free(temp);
        break;

    case 3:
        printf("Enter key to be deleted :");
        scanf("%d", &key);

        temp = head;
        while (temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        // make neighbouring nodes point each other
        temp->next->prev = prev;
        printf("deleted element %d\n", temp->data);
        free(temp);
        break;

    default:
        puts("Invalid choice");
        break;
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
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