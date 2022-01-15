#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void insert(struct node *node, struct node *new)
{
    if (node->data > new->data)
    {
        if (node->left != NULL)
            insert(node->left, new);
        else
            node->left = new;
    }
    else if (node->data < new->data)
    {
        if (node->right != NULL)
            insert(node->right, new);
        else
            node->right = new;
    }
    else
    {
        puts("Duplicate node not allowed");
    }
}

void delete (int key, struct node *node)
{
    struct node *temp = node, *parent = temp;
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
        puts("Key not found");
        return;
    }
    // for leaf node
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // for 1 child (left)
    else if (temp->left != NULL && temp->right == NULL)
    {
        if (parent->left == temp)
            parent->left = temp->left;
        else
            parent->right = temp->left;
    }
    // for 1 child (right)
    else if (temp->left == NULL && temp->right != NULL)
    {
        if (parent->left == temp)
            parent->left = temp->right;
        else
            parent->right = temp->right;
    }
    // for 2 children
    else if (temp->left != NULL && temp->right != NULL)
    {
        // predecessor method
        struct node *temp1 = temp->left, *parent1 = temp1;
        while (temp1->right != NULL)
        {
            parent1 = temp1;
            temp1 = temp1->right;
        }
        // exchange predecessor and to be deleted node
        temp->data = temp1->data;
        // if leftsubtree is empty
        if (temp1 == parent1)
            temp->left = NULL;
        // if predecessor has left child(it can never have right child)
        else if (temp1->left != NULL)
            parent->right = temp1->left;
    }
}

int main()
{
    struct node *root = NULL, *new;
    int choice, key;
    while (1)
    {
        printf("1.INSERT\t2.DELETE\t3.TRAVERSAL\t4.EXIT\n");
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
            printf("Enter key to be deleted :");
            scanf("%d", &key);
            delete (key, root);
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

    return 0;
}