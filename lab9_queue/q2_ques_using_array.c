/*•Q2	Write a menu driven program to implement queue operations such
 as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear==MAX-1) //queue is full
    {
        printf("Overflow because queue is full");
    }
    else if(front==-1 && rear==-1) //queue is empty
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1) //queue is empty
    {
        printf("Underflow");
    }
    else if(front==rear) //single element present
    {   
        printf("\n %d is deleted \n ",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d is deleted \n",queue[front]);
        front++;
    }
}

void display()
{   
    int i;
    for(i=front;i<=rear+1;++i)
    {
        printf("%d -> ",queue[i]);
    }
    printf("\n");
}

void peek()
{
    printf("\n%d ",queue[front]);
}



int main()
{
     int n, c = 1;

    while (c !=2)
    {
        printf("\nPress 1 to enqueue");
        printf("\nPress 2 to dequeue");
        printf("\nPress 3 to peek");
        printf("\nPress 4 to display the elements");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            int l;
            printf("\nenter the element to enqueue");
            scanf("%d", &l);
            enqueue(l);
            break;
        }

        case 2:
        {

            dequeue();
            break;
        }
        case 3:
        {

            peek();
            break;
        }
        case 4:
        {

            display();
            break;
        }
        default:
            break;
        }
        printf("Press 1 to continue\npress 2 to stop\n ");
        scanf("%d", &c);
       // printf("\n.............................................\n");
    }
return 0;
}