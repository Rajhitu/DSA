//Q2A
//Write a menu driven program to implement DEquee ( Input-restricted) operations such as 
//Enqueue, Dequeue, Peek, Display of elements, IsEmpty using Array.
// o/p restricted queue

#include <stdio.h>
#include <stdlib.h>
struct Cirqu
{
    int size;
    int front;
    int rear;
    int *Arr;
};
void create(struct Cirqu *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Arr = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct Cirqu *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Cirqu is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Arr[q->rear] = x;
    }
}
int dequeue_fro(struct Cirqu *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Cirqu is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Arr[q->front];
    }
    return x;
}

int dequeue_rear(struct Cirqu *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Cirqu is Empty\n");
    else
    {
        printf("%d is deleted \n", q->Arr[q->rear]);
        q->rear = (q->rear - 1) % q->size;
    }
    return x;
}
void Display(struct Cirqu q)
{
    int i = q.front + 1;
    while (i != (q.rear + 1) % q.size)
    {
        printf("%d ", q.Arr[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}
int main()
{
    int n, t;
    struct Cirqu q;
    printf("\n Enter thesize of queue");
    int no;
    scanf("%d", &no);
    create(&q, no);

    while (n)
    {

        printf("Press 1 to enqueue using rear\n");
        printf("Press 2 to dequeue from front\n");
        printf("Press 3 to dequeue from rear\n");
        printf("Press 4 to display the Circularqueue\n");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("\n Enter the no. to enque");
            int no;
            scanf("%d", &no);
            enqueue(&q, no);
            break;

        case 2:
            printf("\n  the no.which is removed from front is\n");
            printf("%d ", dequeue_fro(&q));
            break;
        case 3:
            printf("\n  the no.which is removed from rear is\n");
            printf("%d ", dequeue_rear(&q));
            break;
        case 4:
            printf("\nQueue displayed is  \n");
            Display(q);
            break;
        default:
            break;
        }
        printf("\npress 1 to countinue and 0 to stop\n");
        scanf("%d", &n);
    }

    return 0;
}