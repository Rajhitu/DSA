#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * first, *temp,*last;

void create(int a[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last=first;
    for (int i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next=temp;
        last=temp;
    }
}

void display(struct node *temp)
{

    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n ");
}

void insertbeg(struct node *temp)
{
  struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=77;
    newnode->next=temp;
    
    first=newnode;
}
void insertlast(struct node *temp)
{
  struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=78;
    newnode->next=NULL;
    temp->next=newnode;
    last=newnode;
}
void insertany(struct node *temp,int n)
{
  struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=55;
    newnode->next=NULL;
    for (int i = 0; i < n; i++)
    {
       temp=temp->next;
    }
   
    newnode->next=temp->next;
     temp->next=newnode;
    


}
    
int main()
{
int a[]={1,2,3,4,5,6,7,8,9,10};
create(a,10);
display(first);
insertbeg(first);
display(first);
insertlast(last);
display(first);
insertany(first,4);
display(first);




    return 0;
}