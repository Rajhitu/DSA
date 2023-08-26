/*

3.Write a menu driven program to perform the following operations in a single circular linked list by using suitable user defined functions for each case.
a) Traverse the list 
b) Check if the list is empty 
c) Insert a node at the certain position
d) Delete a node at the certain position 
e) Delete a node for the given key
f) Count the total number of nodes 
g) Search for an element in the linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

} * first, *last, *temp;

void create()
{
    int n;
    printf("How many data u have\n");
    scanf("%d", &n);
    first = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1 data ");
    scanf("%d", &first->data);
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {

        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter %d data ", i + 1);

        scanf("%d", &temp->data);
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    last->next = first;
}
void display(struct node *f)
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
void insertbeg(struct node *f)

{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data in new node ");

    scanf("%d", &newnode->data);

    newnode->next = first;
    first = newnode;
    last->next = first;
    printf("now  CLL become \n");
    display(first);
}
void insertlast(struct node *f)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data in new node ");

    scanf("%d", &newnode->data);
    last->next = newnode;
    newnode->next = NULL;
    last = newnode;
    last->next = first;
    printf("now  CLL become after inserting at the end \n");
    display(first);
}
void delete_beg()
{
    struct node *temp = first;
    first = first->next;
    last->next = first;
    free(temp);
    printf("After deleting the 1st node CLL becomes ");
    display(first);
}
void delete_last()
{
    struct node *temp, *back = last;
    while (temp->next != last)
    {

        temp = temp->next;
    }
    last = temp;
    temp->next = first;
    free(back);
    printf("after deleting the lastt data cll bracomes");
    display(first);
}
void delete_any(struct node *f)
{
    int n;
    printf("After which node u want to delete");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        f = f->next;
    }
    struct node *temp = f->next;
    f->next = f->next->next;
    free(temp);
    printf("after deletion the nodes left are\n");
    display(first);
}
int count(struct node *f)
{

    int c;
    while (f != NULL)
    {
        c++;
    }
    return c;
}
void search(struct node *f, int data)
{

    int c;
    while (f != NULL)
    {
        if (f->data == data)
            c++;
    }
    if (c > 0)
        printf("data found\n");
}
void delete_key(struct node *f, int data)
{

    while (f->data != data)
    {
        temp->next = f->next;
        free(f);
        struct node *temp = f;
        f = f->next;
    }
    display(first);
}

void insertany(struct node *temp, int n)
{
    int a;
    printf("entre the data to the node");
    scanf("%d", &a);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}
int main()
{
    int t, C, j;
    int n;
    create();

    printf("1) Traverse the list\n");
    printf("2) Check if the list is empty \n");
    printf("3) Insert a node at the certain position\n");
    printf("4) Delete a node at the certain position\n");
    printf("5) Delete a node for the given key\n");
    printf("6) Count the total number of nodes \n");
    printf("7) Search for an element in the linked list\n");
    scanf("%d",&n);

    switch (n)
    {
    case 1 :
        display(first);
        break;
    case 2:

        break;
    case 3:
     printf("press 1 if u want to enter 1st node\n ");
        printf("press 2 if u want to enter after last node\n ");
        printf("press 3 if u want to enter any where\n ");
        scanf("%d", &t);
        if (t == 1)
            insertbeg(first);
        else if (t == 2)
            insertlast(first);
        else
            insertany(first,3);

        break;
    case 4:
        printf("press 1 if u want to delete  1st node\n ");
        printf("press 2 if u want to enter after last node\n ");
        printf("press 3 if u want to enter any where\n ");
        scanf("%d", &t);
        if (t == 1)
            delete_beg(first);
        else if (t == 2)
            delete_last(last);
        else
            delete_any(first);

        break;
    case 5: //int t;
        printf("which data u want to delete\n");
        scanf("%d", j);
        delete_key(first, j);

        break;
    case 6:
        printf("total no. of element is %d", count(first));
        break;
    case 7:
        // int C;
        printf("enter the data u want to search\n");
        scanf("%d", &C);

        search(first, C);
        break;

    default:
        break;
    }

    return 0;
}
