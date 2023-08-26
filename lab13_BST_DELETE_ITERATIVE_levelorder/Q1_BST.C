/*1.WAP using C
I. To create a BST
II.  Display the elements using Level order Traversal
III. Delete the leaf node and print it .
IV. Delete a node which has only one child and readjust the BST
V. Delete the node whose degree is 2 and display the Deleted node,it’s inorder predecessor and inorder successor and display all nodes in Inorder traversal after readjustment of BST

*/

/* level order traversal */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = q->rear + 1 % q->size;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
struct Node *insert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = insert(p->lchild, key);
    else if (key > p->data)
        p->rchild = insert(p->rchild, key);
    return p;
}
void levelorder(struct Node *r)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", r->data);
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
struct Node *InPredecessor(struct Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}
struct Node *InSuccessor(struct Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}
struct Node *Delete (struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = Delete (p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete (p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete (p->lchild, q->data);
        }
        else
        {
            q = InSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete (p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    int ch, x;
    printf("Enter root node data: ");
    scanf("%d", &x);
    root = insert(root, x);
    do
    {
        printf("Enter data: ");
        scanf("%d", &x);
        insert(root, x);
        printf("Do you want more nodes? (1/0): ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\nLevel order traversal is\n");
    levelorder(root);
    do
    {
        printf("\nEnter node to be Deleted: ");
        scanf("%d", &x);
        Delete (root, x);
        printf("\nInorder traversal after deletion\n");
        Inorder(root);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);
    } while (ch != 0);
    return 0;
}