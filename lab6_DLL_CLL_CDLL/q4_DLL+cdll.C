/*4. WAP to create a double circular double linked list of n nodes
 and display the linked list by using suitable user defined functions
  for create and display operations
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;

} * first, *last, *temp;

void create()
{
    int n;
    printf("How many data u have\n");
    scanf("%d", &n);
    first = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1 data ");
    scanf("%d", &first->data);
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {

        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter %d data ", i + 1);

        scanf("%d", &temp->data);
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    last->next = first;
    first->prev = last;
}
void display_f(struct node *f)
{
    printf("%d ", f->data);
    f = f->next;
    while (f != first)
    {
        printf("%d ", f->data);
        f = f->next;
    }
    printf("\n");
}
void display_b(struct node *f)
{
    printf("%d ", f->data);
    f = f->prev;
    while (f != last)
    {
        printf("%d ", f->data);
        f = f->prev;
    }
    printf("\n");
}

int main()
{
    int n;
    create();
    printf("PRESS 1  TO DISPLAY FROM FORWORD\nPRESS 2 TO DISPLAY  FROM BACKWARD");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        display_f(first);
        break;

    case 2:

        display_b(last);
        break;

    default:
        break;
    }

    return 0;
}
