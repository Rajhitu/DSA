/*1.WAP to create a link list and display using recursive funcn
2.find out the length of the link list using both iterative  recursive funcn
3.find out thr sum and product of nodes of the link list using iterative and recursive func
4.find out max and mean using iterative and recursive funcn
5.write a program  to demonstrate the deletion of node at beg , end and at given position
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first, *last, *temp;

void create(int a[], int n)
{

    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void display_rec(struct node *f)
{

    if (f != NULL)
    {
        printf("%d ", f->data);
        display_rec(f->next);
    }
    else
    {
        printf("\nDATA DISPLAYED");
    }
}

void length_rec(struct node *f)
{
    int static count = 0;
    if (f != NULL)
    {
        count++;
        length_rec(f->next);
    }
    else
    {
        printf("\nlength of node is %d", count);
    }
}
void length(struct node *f)
{
    int count = 0;
    while (f != NULL)
    {
        count++;
        f = f->next;
    }

    printf("\nlength of node is %d", count);
}

void sum_prod(struct node *f)
{
    int sum = 0, prod = 1;
    while (f != NULL)
    {
        prod = prod * f->data;
        sum = sum + f->data;
        f = f->next;
    }

    printf("\nsum of data in each node is %d\n product of data in each node is %d", sum, prod);
}
void sum_prod_rec(struct node *f)
{
    int static sum = 0;
    int static prod = 1;
    if (f != NULL)
    {
        sum = sum + f->data;
        prod = prod * f->data;
        sum_prod_rec(f->next);
    }
    else
    {

        printf("\nsum of data in each node is %d\n product of data in each node is %d", sum, prod);
    }
}
void max_mean_rec(struct node *f)
{
    int static max = 0;
    int static sum = 0;
    int static c = 0;
    if (f != NULL)
    {
        sum = sum + f->data;
        if (f->data > max)
        {
            max = f->data;
        }
        c++;
        max_mean_rec(f->next);
    }
    else
    {

        printf("\nmean of data in every node is %d\n max of data in each node is %d", sum / c, max);
    }
}
void max_mean(struct node *f)
{
    int max = 0;
    int sum = 0;
    int c = 0;
    while (f != NULL)
    {
        sum = sum + f->data;
        if (f->data > max)
        {
            max = f->data;
        }
        c++;
        f = f->next;
    }

    printf("\nmean of data in every node is %d\n max of data in each node is %d", sum / c, max);
}
void delete_beg(struct node *f)
{
    struct node *temp;
    temp = f;
    f = f->next;
    free(temp);
    first = f;
    printf("after deletion the nodes left are\n");
    display_rec(first);
}
void delete_last(struct node *f)
{
    int c = 0;
    while (c == 0)
    {
        if (f->next->next == NULL)
        {
            struct node *temp = f->next->next;
            // last=f;
            f->next = NULL;
            free(temp);

            c = 1;
        }
        f = f->next;
    }

    printf("after deletion the nodes left are\n");
    display_rec(first);
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
    display_rec(first);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    create(a, 7);
    int n;
    printf("press 1 to display the data\n");
    printf("press 2 to find the no. of nodes recursively\n");

    printf("press 3 to find no. od nodes ittereatively\n");

    printf("press 4 to find the sum and prod recursively\n");

    printf("press 5 tosum and prod itteratively\n");
    printf("press 6 to find mean and max recursively \n");
    printf("press 7 to find mean and max itterativelt\n");
    printf("press 8 to delete at beg\n");
    printf("press 9 to delete at last\n");

    printf("press 10 to delete at any position\n");

    scanf("%d", &n);
    switch (n)
    {
    case 1:
        display_rec(first);
        break;
    case 2:
        length_rec(first);
        break;
    case 3:
        length(first);
        break;
    case 4:
        sum_prod_rec(first);
        break;
    case 5:
        sum_prod(first);
        break;
    case 6:
        max_mean_rec(first);
        break;
    case 7:
        max_mean(first);
        break;
    case 8:
        delete_beg(first);
        break;
    case 9:
        delete_last(first);
        break;
    case 10:
        delete_any(first);
        break;

    default:
        break;
    }

    return 0;
}