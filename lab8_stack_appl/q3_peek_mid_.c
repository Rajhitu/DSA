/*3. WAP to implement a stack which will support three additional operations in addition to push and pop.Those are  
a) peekLowestElement - return the lowest element in the stack without removing it from the stack
b) peekHighestElement - return the highest element in the stack without removing it from the stack
c) peekMiddleElement - return the (size/2+1)th lowest element in the stack without removing it from the stack.
*/

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int *s;
    int top;
};

void peek_hig(struct stack temp)
{
   

        if (temp.top != -1)
            printf(" Highest element in stack is %d\n " ,temp.s[temp.top]);
    
}

void peek_low(struct stack temp)
{
    

        while (temp.top != 0)
        {
          temp.top--;
        }
            printf(" lowest element in stack is %d\n ",  temp.s[temp.top]);
    
}

void peek_mid(struct stack temp)
{
    
for (int i = 0; i < temp.size/2; i++)
{
     temp.top--;
}

        
            printf(" mid element in stack is %d\n ",  temp.s[temp.top]);
    
}
int main()
{
    struct stack st;
    printf("How many elements u have\n");
    scanf("%d", &st.size);
    st.top = -1;
    st.s = (int *)malloc(sizeof(st.size));
    printf("enter elements");
    for (int i = 0; i < st.size; i++)
    {
        st.top++;
        scanf("%d", &st.s[st.top]);
    }

    peek_hig(st);
    peek_low(st);
    peek_mid(st);

    return 0;
}