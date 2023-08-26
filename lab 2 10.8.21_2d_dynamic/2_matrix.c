/*Q2 Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
a. Find the number of nonzero elements in A
B. Find the sum of the elements above the leading diagonal.
C. Display the elements below the minor diagonal.
D. Find the product of the diagonal elements.
*/
#include <stdio.h>
#include <stdlib.h>
void zero_el(int *a[10], int c_025)
{
    int count = 0;
    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            if (a[i][j] == 0)
            {
                count++;
            }
        }
    }
    printf("no. of zero element is %d \n\n", count);
}

void sumabovediad(int *a[10], int c_025)
{
    int sum = 0;
    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            if (j > i)
            {
                sum = sum + a[i][j];
            }
        }
    }
    printf("sum of elements above leading diagnol is %d\n\n", sum);
}

void disp_b_lead_diag(int *a[10], int c_025)
{
    printf("the  elements below leading disgnol are :");
    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            if (i > j)
            {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n\n");
}
void diag_prod(int *a[10], int c_025)
{
    int prod = 1;

    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            if (i ==j)
            {
                prod = prod * a[i][j];
            }
            else if ((i + j) == (c_025 - 1))
            {
                prod = prod * a[i][j];
            }
        }
    }
   
    
    printf("the prod of the diag elements are %d \n\n:", prod);
}

int main()
{

    int *p_025[10], c_025, l = 0;
    printf("how many columns you have ");
    scanf("%d",&c_025);
    for (int i = 0; i < c_025; i++)
    {
        p_025[i] = (int *)malloc(c_025 * sizeof(int));
    }
    printf("Enter elements \n");
    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            scanf("%d",&p_025[i][j]);
        }
    }

    for (int i = 0; i < c_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {
            printf("%d ", p_025[i][j]);
        }
        printf("\n");
    }

zero_el(p_025,c_025);
sumabovediad(p_025,c_025);
disp_b_lead_diag(p_025,c_025);
diag_prod(p_025,c_025);
    return 0;
}
