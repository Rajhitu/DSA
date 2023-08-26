/*•Q1.	Write a menu driven program to implement queue operations such as Enqueue,
 Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

//struct node* front=NULL
//struct node* rear=NULL
void enqueue(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("No memory\n");
    }
    else
    {
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

void dequeue()
{
   // int x = -1;
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("\n!!!!!!!!Cant delete  ueue is empty");
    }
    else
    {
        temp = front;
       printf("Elentent deleted is %d\n",front->data);  
        front = front->next;
        free(temp);
    }
    //return x;
}

void display()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\n!!!!!!!!Cant delete  Queue is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    printf("\nThe 1st element is %d", front->data);
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