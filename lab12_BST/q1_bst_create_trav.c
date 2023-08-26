/*•	WAP Write the following menu driven program for the binary search tree
----------------------------------------
Binary search Tree Menu
----------------------------------------
0. Quit
1. Create
2. In-Order Traversal
3. Pre-Order Traversal
4. Post-Order traversal
5. search
6. Find Smallest Element
7. Find Largest Element
----------------------------------------
Enter your choice:
*/
#include <stdio.h>
#include <stdlib.h>
struct BSTnode
{
    struct BSTnode *lchild;
    int data;
    struct BSTnode *rchild;
} *root = NULL;
void insert(int key)
{
    struct BSTnode *prev = root;
    struct BSTnode *rear = NULL, *newnode;
    if (root == NULL)
    {
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        root = newnode;
        return;
    }
    while (prev != NULL)
    {
        rear = prev;
        if (key < prev->data)
            prev = prev->lchild;
        else if (key > prev->data)
            prev = prev->rchild;
        else
            return;
    }
    newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    if (key < rear->data)
        rear->lchild = newnode;
    else
        rear->rchild = newnode;
}
void Inorder(struct BSTnode *newnode)
{
    if (newnode)
    {
        Inorder(newnode->lchild);
        printf("%d ", newnode->data);
        Inorder(newnode->rchild);
    }
}
void preorder(struct BSTnode *newnode)
{
    if (newnode)
    {
        printf("%d ", newnode->data);
        preorder(newnode->lchild);

        preorder(newnode->rchild);
    }
}
void postorder(struct BSTnode *newnode)
{
    if (newnode)
    {
        postorder(newnode->lchild);

        postorder(newnode->rchild);
        printf("%d ", newnode->data);
    }
}
struct BSTnode *search(int key)
{
    struct BSTnode *prev = root;
    while (prev != NULL)
    {
        if (key == prev->data)
            return prev;
        else if (key < prev->data)
            prev = prev->lchild;
        else
            prev = prev->rchild;
    }
    return NULL;
}

struct BSTnode*  search_smal()
{       int key=root->data;
    struct BSTnode *prev = root;
     struct BSTnode *temp=prev;
    while (prev != NULL)
    {  temp=prev;
        prev=prev->lchild;

    }
    return temp;
}
struct BSTnode*  search_largest()
{       int key=root->data;
    struct BSTnode *prev = root;
     struct BSTnode *temp=prev;
    while (prev != NULL)
    {  temp=prev;
        prev=prev->rchild;

    }
    return temp;
}
int main()
{
    int n = 1, c,l=1;
    struct BSTnode *temp;
    while (n)
    {
        printf("\n 0. Quit \n");
        printf("1. Create \n");
        printf("2. In-Order Traversal \n");
        printf("3. Pre-Order Traversal \n");
        printf(" 4. Post-Order traversal \n");
        printf(" 5. search \n");
        printf(" 6. Find Smallest Element \n");
        printf(" 7. Find Largest Element \n");

        scanf("%d", &c);
        switch (c)
        {
        case 1:
        while (l)
        { 
            int j;
             printf("Enter the element ");
            scanf("%d", &j);
            insert(j);
              printf("\nPress 0 to exit and 1 to continue \n");
             scanf("%d", &l);
        }
            
            break;
        case 2:
            Inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;

        case 5:
        {
            int j;
            printf("which element u want to search ");
            scanf("%d", &j);
            temp = search(j);
            if (temp != NULL)
                printf("element %d is found\n", temp->data);
            else
                printf("element is not found\n");

            break;
        }
        case 6:
        {
            
            temp = search_smal();
            if (temp != NULL)
                printf("element %d is the smallest element\n", temp->data);
         

            break;
        }
        case 7:
        {
            
            temp = search_largest();
            if (temp != NULL)
                printf("element %d is the largest element\n", temp->data);
          
            break;
        }
        default:
            break;

            printf("\nPress 0 to exit and 1 to continue \n");

            scanf("%d", &n);
        }
    }
    return 0;
}