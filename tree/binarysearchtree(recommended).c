#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

void insert(struct node *node, struct node *new)
{
    if (node->data > new->data)
    {
        if (node->left == NULL)
            node->left = new;
        else
            insert(node->left, new);
    }
    else if (node->data < new->data)
    {
        if (node->right == NULL)
            node->right = new;
        else
            insert(node->right, new);
    }
}

void delete (struct node *node, int key)
{
    struct node *temp = node, *parent = node;
    while (temp != NULL)
    {
        if (temp->data == key)
            break;
        else if (temp->data > key)
        {
            parent = temp;
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            parent = temp;
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    // no child
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // left child
    else if (temp->left != NULL && temp->right == NULL)
    {
        if (parent->left == temp)
            parent->left = temp->left;
        else
            parent->right = temp->left;
    }
    // right child
    else if (temp->left == NULL && temp->right != NULL)
    {
        if (parent->left == temp)
            parent->left = temp->right;
        else
            parent->right = temp->right;
    }

    // both child
    else if (temp->left != NULL && temp->right != NULL)
    {
        struct node *temp1 = temp->left, *parent1 = temp1;
        while (temp1->right != NULL)
        {
            parent1 = temp1;
            temp1 = temp1->right;
        }
        // swap predecessor and temp
        temp->data = temp1->data;
        if (temp1 == parent1)
            temp->left = temp->left;

        // if left child exists
        else if (temp1->left != NULL)
            parent1->right = temp1->left;
        else
            parent1->right = NULL;
    }
}

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void main()
{
    struct node *root = NULL, *new;
    int choice, key;
    while (1)
    {
        printf("1.INSERT\t2.DELETE\t3.TRAVERSE\t4.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter data :");
            scanf("%d", &new->data);
            new->left = new->right = NULL;
            if (root == NULL)
                root = new;
            else
                insert(root, new);
            break;
        case 2:
            printf("Enter key :");
            scanf("%d", &key);
            delete (root, key);
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);

        default:
            puts("Invalid choice");
        }
    }
}