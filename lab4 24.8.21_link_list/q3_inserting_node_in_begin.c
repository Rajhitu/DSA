/*inserting new node at beginning
inserting new node at end
inserting new node at any place*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data_025;
    struct node *next_025;
} * first_025, *last_025, *temp_025;
void create(int a[10], int n)
{
    first_025 = (struct node *)malloc(sizeof(struct node));
    first_025->data_025 = a[0];
    first_025->next_025 = NULL;
    last_025 = first_025;
    for (int i = 1; i < n; i++)
    {
        temp_025 = (struct node *)malloc(sizeof(struct node));
        temp_025->data_025 = a[i];
        temp_025->next_025 = NULL;
        last_025->next_025 = temp_025;
        last_025 = temp_025;
    }
}
void display(struct node *temp_025)
{
    while (temp_025 != NULL)
    {
        printf("%d ", temp_025->data_025);
        temp_025 = temp_025->next_025;
    }
}

void insertbeg(struct node *temp_025)
{
    struct node *newnode;

    printf("entre the data to the node ");
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newnode->data_025);

    newnode->next_025 = temp_025;

    first_025 = newnode;
}
void insertlast(struct node *temp_025)
{
    int a;
    printf("entre the data to the node");
    scanf("%d", &a);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data_025 = a;
    newnode->next_025 = NULL;
    temp_025->next_025 = newnode;
    last_025 = newnode;
}
void insertany(struct node *temp_025, int n)
{
    int a;
    printf("entre the data to the node");
    scanf("%d", &a);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data_025 = a;
    newnode->next_025 = NULL;
    for (int i = 1; i < n; i++)
    {
        temp_025 = temp_025->next_025;
    }

    newnode->next_025 = temp_025->next_025;
    temp_025->next_025 = newnode;
}
int main()
{
    int n,p;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    create(a, 7);
    display(first_025);
    printf("\n press 1 to insert in begin\n press 2 to insert in last \npress 3 to insert b/w any node\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        insertbeg(first_025);
        display(first_025);
        break;
    case 2:
        insertlast(last_025);
        display(first_025);
        break;
    case 3:
        
        printf("After which node you want to enter");
        scanf("%d", &p);
        insertany(first_025,p);
        display(first_025);
        break;

    default:
        break;
    }

    return 0;
}