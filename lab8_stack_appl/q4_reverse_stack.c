#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};

void create_stack(struct stack *st,int n)
{
    st->size=n;
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
        st->top++;
        st->s[st->top]=x;
}

int pop(struct stack *st)
{
    int x=-1;
    if(!isEmpty(st))
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

void Reverse(struct stack *st,struct stack *stNew)
{
       int i;
       for(i=st->top;i>=0;i--)
          push(stNew,pop(st));
}

int main()
{
    struct stack S,SNew;
    int n,i,x;
    printf("Enter size of stack:");
    scanf("%d",&n);
    create_stack(&S,n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
                    scanf("%d",&x);
                    push(&S,x);
    }
    printf("\nEntered  stack is ----------------> ");
    display(S);              
    create_stack(&SNew,n);
    Reverse(&S,&SNew);
    printf("\nReversed stack is ----------------> ");
    display(SNew);  
   
    return 0;
}