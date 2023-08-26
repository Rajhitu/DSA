/*1.Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
a) Check if the stack is empty 
b) Display the contents of stack 
c)  Push 
d) Pop
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};
void create_stack(struct stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc((st->size)*sizeof(int));
}
int isEmpty(struct stack *st)
{
    if(st->top==-1)
       return 1;
    else 
       return 0;
}
void push(struct stack *st, int x)
{
    if (st->top==st->size-1)
        printf("Stack Overflow");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(isEmpty(st))
        printf("\nStack Underflow");
    else
        x=st->s[st->top--];
    return x;
}
void display(struct stack st)
{
    int i;
    if(isEmpty(&st))
        printf("Stack is empty");
    else
    {
        for(i=st.top;i>=0;--i)
            printf("%d\t",st.s[i]);
    }
}

int main() 
{
    int ch,item;
    char ch2;
    struct stack st;
    create_stack(&st);
    do{
          printf("1.Push\n2.Pop\n3.Display\n");
          printf("Enter you choice:");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
                   printf("\nEnter value to be pushed:");
                   scanf("%d",&item);
                   push(&st,item);
                   break;
              case 2:
                   printf("\nItem deleted is %d",pop(&st));
                   break;
              case 3:
                   printf("\nStack: ");
                   display(st);
                   break;
              default:
                  printf("Wrong choice!!");
          }
          printf("\n\nDo you want to continue? (y/n):");
          fflush(stdin);
          scanf("%c",&ch2);
          printf("\n\n");
    }while(ch2=='y');
    fflush(stdin);
    getchar();
    return 0;
}
