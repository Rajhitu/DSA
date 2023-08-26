/*Q2•	Extend the above program by providing more options as follows:
a) To count number of leaf nodes in the tree.
b) To count number of non-leaf nodes in the tree.
c) To find number of nodes in the tree.
d) To find sum of all nodes of the tree.
e) To print depth of the tree.
f) To find nodes which are at maximum depth in the tree?
g) To print all the elements of kth level in single line.
h) To find the common ancestor and print the paths.
i) To check whether a tree is a binary search tree or not.
*/
#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *New (int x)
{
    struct node *Temp;
    Temp=(struct node *)malloc(sizeof(struct node));
    Temp->data = x;
    Temp->left = NULL;
    Temp->right = NULL;
    return Temp;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
        return New (x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}

int countLeaf(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeaf(root->left) + countLeaf(root->right);
}

int countNonleaf(struct node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countNonleaf(root->left) + countNonleaf(root->right);
}

int countNode(struct node *root)
{
    return countLeaf(root) + countNonleaf(root);
}

int sumNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int maxDepth(struct node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printlevel(struct node *n, int desired, int current)
{
    if (n)
    {
        if (desired == current)
            printf("%d ", n->data);
        else
        {
            printlevel(n->left, desired, current + 1);
            printlevel(n->right, desired, current + 1);
        }
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

void path(struct node *root, int num)
{
    if (num > root->data)
    {
        printf("%d ", root->data);
        path(root->right, num);
    }
    else if (num < root->data)
    {
        printf("%d ", root->data);
        path(root->left, num);
    }
    else if (num == root->data)
    {
        printf("%d \n", root->data);
    }
}

struct node *lca(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

struct node *NewNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main()
{
    struct node *root;
    int n1, n2;
    root = NULL;
    int c = 0;
    int temp = 0;
    int k = 0;
    while (1)
    {
        printf("\n1 - Insert a Node in BST.\n");
        printf("2 - Count number of leaf nodes.\n");
        printf("3 - Count number of non-leaf nodes.\n");
        printf("4 - Total number of nodes.\n");
        printf("5 - Sum of all nodes.\n");
        printf("6 - Depth of tree.\n");
        printf("7 - Nodes at maximum depth.\n");
        printf("8 - All elements at k-th level.\n");
        printf("9 - Find common ancestors and print the paths.\n");
        printf("10 - Check if BST or not.\n");
        printf("11 - Exit.\n");

        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                printf("Enter Value of Node to Insert in BST : ");
                scanf("%d", &temp);
                root = insert(root, temp);
                printf("Insertion Done.\n");
                break;
            case 2:
                printf("Number of leaf nodes in BST : ");
                printf("%d", countLeaf(root));
                break;
            case 3:
                printf("Number of non-leaf nodes in BST : ");
                printf("%d", countNonleaf(root));
                break;
            case 4:
                printf("Total number of nodes in BST : ");
                printf("%d", countNonleaf(root) + countLeaf(root));
                break;
            case 5:
                printf("Sum of all nodes in BST : ");
                printf("%d", sumNodes(root));
                break;
            case 6:
                printf("Depth of BST : ");
                printf("%d", maxDepth(root));
                break;
            case 7:
                printf("Nodes present at maximum depth in BST : ");
                printlevel(root, maxDepth(root), 0);
                break;
            case 8:
                printf("Enter value of k : ");
                scanf("%d", &k);
                printf("\nNodes present at %d-th level in BST : ");
                printlevel(root, k, 0);
                break;
            case 9:
               { printf("Enter value of Nodes : ");
                scanf("%d", &n1);
                scanf("%d", &n2);
                struct node *t = lca(root, n1, n2);
                printf("LCA of %d and %d is %d \n", n1, n2, t->data);
                printf("Path between %d (LCA) and %d is : ",t->data,n1);
                path(t,n1);
                printf("Path between %d (LCA) and %d is : ",t->data,n2);
                path(t,n2);
                break;
               }
            case 10:
                if (isBST(root) == 1)
                {
                    printf("Given tree is a BST.\n");
                }
                else
                {
                    printf("Given tree is not a BST.\n");
                }
                break;
            case 11:
                printf("Code Exited.\n");
                exit(1);
            default:
                printf("Wrong Choice, Try again!\n");
        }
    }
    return 0;
}
