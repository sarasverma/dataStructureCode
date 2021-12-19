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
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        // root left right
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        // left right root
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        // left root right
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    // create node
    struct node *root = createNode(3);
    struct node *node2 = createNode(12);
    struct node *node3 = createNode(5);
    struct node *node4 = createNode(8);
    struct node *node5 = createNode(9);

    // make it point each others
    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    // my tree structue
    //      r
    //     / \
    //   n2  n3
    //   /\
    // n4 n5

    // other representation for tree
    //      3
    //     / \
    //   12   5
    //   /\
    //  8  9
    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    return 0;
}
