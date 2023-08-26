#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int power;
    int terms;
    struct node *next;
    struct node *first,*last;
    

};

void create(struct node *a)
{ struct node*temp;
    int n;
    printf("How many terms u have\n");
    scanf("%d", &n);
     a->terms=n;
         a->first = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1st tem coef and power of x ");
    scanf("%d %d", &a->first->coef,&a->first->power);
    a->first->next = NULL;
    a->last = a->first;

    for (int i = 1; i < n; i++)
    {

        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter %d term coef and power of x  ", i + 1);

        scanf("%d%d", &temp->coef,&temp->power);
        temp->next = NULL;
        a->last->next = temp;
        a->last = temp;
    }
   
}
void display(struct node *f)
{
   
    while (f != NULL)
    {
        printf("%dx^%d ", f->coef,f->power);
        f = f->next;
        printf("+");
    }
    printf("\n");
}
void add(struct node *a,struct node *b)
{
struct node *c;
c = (struct node *)malloc(sizeof(struct node));
for (int i = 0; i < a->terms; i++)
{
    
    for (int j = 0; j < b->terms ; j++)
    {
        if(a->power==b->power)
        {
            c->coef=a->coef+b->coef;
            c->power=a->power;
            

        }
        else
        {
            a=a->next;
        }
    }
    
}



}

int main()
{

    create();
    display(first);
    


    return 0;
}
