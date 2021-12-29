#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorderTravesal(struct node *root)
{
    if (root != NULL)
    {
        inorderTravesal(root->left);
        printf("%d ", root->data);
        inorderTravesal(root->right);
    }
}

int searchRecursion(struct node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
            return 1;
        else if (root->data > key)
            return searchRecursion(root->left, key);
        else
            return searchRecursion(root->right, key);
    }
    return 0;
}

int searchLoop(struct node *node, int key)
{
    while (node != NULL)
    {
        if (node->data == key)
            return 1;
        else if (node->data > key)
            node = node->left;
        else
            node = node->right;
    }
    return 0;
}

int main()
{
    // create nodes
    struct node *root = createNode(5);
    struct node *n1 = createNode(2); // make is more than 5 for not a BST
    struct node *n2 = createNode(6);
    struct node *n3 = createNode(1);
    struct node *n4 = createNode(3);

    // linking all the nodes
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    // the following is the tree
    inorderTravesal(root);
    printf("\n");

    if (searchRecursion(root, 3))
    {
        printf("The element is found through recursion\n");
    }
    else
    {
        printf("The element is NOT found through recursion\n");
    }

    // it is sample code for
    if (searchLoop(root, 3))
    {
        printf("The element is found through loop method\n");
    }
    else
    {
        printf("The element is NOT found through loop method\n");
    }

    return 0;
}