// a binarry search tree is a whose left side is small and right side is large than root
// and root is in between them
// **inorder traversal of a BST is a sorted

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

int isBST(struct node *root)
{
    // this is actually modification of inorder traversal only
    // because inorder traversal result of BST is a sorted list in ascending order.
    static struct node *prev = NULL;
    // we have made it as static because we want it to be initialized only once
    // and it's will be null for the root
    if (root != NULL)
    {
        if (!isBST(root->left))
        { // for checking the left subtree
            return 0;
        }
        // for middle
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        // make prev as root
        prev = root;
        return isBST(root->right);
    }
    else
    {
        // we are assuming empty tree is also a BST.
        return 1;
    }
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

    printf("binary serch tree condition : %d", isBST(root));
    return 0;
}