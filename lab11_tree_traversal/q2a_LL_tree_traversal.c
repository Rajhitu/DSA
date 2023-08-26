/*•q2	Write the following menu driven program for the binary tree
----------------------------------------

2.Create_BinaryTree_Linked (using linked representation)
3. In-Order Traversal
4. Pre-Order Traversal
5. Post-Order traversal
*/
#include <stdio.h>
#include <stdlib.h>

struct node_025
{
    struct node_025 *lchild;
    int data;
    struct node_025 *rchild;

} *root = NULL;

struct queue
{
    int size;
    int front;
    int rear;
    struct node_025 **Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node_025 **)malloc(q->size * sizeof(struct node_025 *));
}

void enqueue(struct queue *q, struct node_025 *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("queue is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct node_025 *dequeue(struct queue *q)
{
    struct node_025 *x = NULL;
    if (q->front == q->rear)
        printf("queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isempty(struct queue q)
{
    return q.front == q.rear;
}

void createtree()
{
    struct node_025 *p, *t;
    int x;
    struct queue q;
    create(&q, 100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct node_025 *)malloc(sizeof(struct node_025));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node_025 *)malloc(sizeof(struct
                                             node_025));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node_025 *)malloc(sizeof(struct
                                             node_025));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct node_025 *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node_025 *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node_025 *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
int main()
{
    createtree();
     printf("\nPre Order ");
    preorder(root);
    printf("\nPost Order ");
    postorder(root);
     printf("\nIn Order ");
    inorder(root);
    return 0;
}
