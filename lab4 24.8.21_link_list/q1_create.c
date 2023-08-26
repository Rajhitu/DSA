/* Q1.WAP to create SLLand display the value of each node
 using user defined funcion create and display*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data_025;
    struct node *next_025;
} * first_025, *temp_025, *last_025;
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
        last_025=temp_025;
    }
}
void display(struct node *F)
{
    while (F!=NULL)
    {
        printf("%d ", F->data_025);
        F = F->next_025;
    }
}


int main()
{

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    create(a, 7);
    display(first_025);
    
    return 0;
}