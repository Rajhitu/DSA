/*2 Write a menu driven program to perform the above operations of a stack using linked list by using suitable
 user defined functions for each case..*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
       int data;
       struct Node* next;
}*top=NULL;

int isEmpty()
{
    if(top==NULL)
         return 1;
    else
         return 0;
}

int Peek()
{
    return top->data;
}

void Push(int x)
{
     struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
     temp->data=x;
     temp->next=top;
     top=temp;
}

int Pop()
{
    if (isEmpty())
    {
        printf("Underflow!");
        return -1;
    }  
    struct Node* temp=top;
    int val;
    val=top->data;
    top=top->next;
    free(temp);
    return val;
}

void display(struct Node* top)
{
     while(top!=NULL)
     {
         printf("%d ",top->data);
         top=top->next;
     }
}

int main()
{
    int ch,item;
    char ch2;
    do{
          printf("1.Push\n2.Pop\n3.Display\n4.Peek\n");
          printf("Enter you choice:");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
                   printf("\nEnter value to be pushed:");
                   scanf("%d",&item);
                   Push(item);
                   break;
              case 2:
                   item=Pop();
                   printf("\nItem deleted is %d",item);
                   break;
              case 3:
                   printf("\nStack: ");
                   display(top);
                   break;
              case 4:
                   printf("\nTop= %d",Peek());
                   break;
              default:
                  printf("Wrong choice!!");
          }
          printf("\n\nDo you want to continue? (y/n):");
          fflush(stdin);
          scanf("%c",&ch2);
          printf("\n\n");
    }while(ch2=='y');
    
    return 0;
}
