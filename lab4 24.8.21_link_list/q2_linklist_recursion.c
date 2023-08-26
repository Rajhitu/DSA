/* Q2.WAP to create SLL using recursion and display the value of each node
 using user defined funcion create and display*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data_025;
    struct node *next_025;
} * first_025, *temp_025, *last_025;

void crearec(int a[], int n, int i)
{

    if (i == n)
    {
        printf("nodes are created\n");
    }

    else
    {
        struct node *temp_025;
        temp_025 = (struct node *)malloc(sizeof(struct node));
        temp_025->data_025 = a[i];
        temp_025->next_025 = NULL;
        last_025->next_025 = temp_025;
        last_025 = temp_025;
        crearec(a, n, i + 1);
    }
}
void display(struct node *f)
{
    //struct node *temp_025 = f;
    while (f != NULL)

    {
        printf("%d ", f->data_025);
        f = f->next_025;

    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    first_025 = (struct node *)malloc(sizeof(struct node));
    first_025->data_025 = a[0];
    first_025->next_025 = NULL;
    last_025 = first_025;
    crearec(a, 7, 1);
    printf("data in created nodes are: ");
    display(first_025);

    return 0;
}