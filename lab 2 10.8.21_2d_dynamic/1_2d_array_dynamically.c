/*Q1. Write a program using C to allocate memory dynamically for 2D array ,read the values and display them using 3 functions separately
I. Keeping no columns fixed and using variable no of rows
II. Keeping no rows fixed and using variable no of columns
III. Using both variable no of rows and columns(use double pointer)

*/
#include <stdio.h>
#include <stdlib.h>
void rfcv()
{
    printf(".....THIS IS  2D DMA WITH fix Row & Var Column.....\n");
    int r_025, c_025;

    printf("how many columns you have ");
    scanf("%d", &c_025);

    int *p_025[10], l = 1;

    for (int j = 0; j < 5; j++)
    {
        p_025[j] = (int *)malloc(c_025 * sizeof(int));
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < c_025; j++)
        {

            p_025[i][j] = l;
            l++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < c_025; j++)
        {

            printf("%d ", p_025[i][j]);
        }
        printf("\n");
    }
}
void rvcf()
{
    printf(".....THIS IS  2D DMA WITH var Row & fix Column.....\n");
     int(*p_025)[5];
    int r_025, l = 1;
    printf("how many rows you have ");
    scanf("%d", &r_025);
    p_025 = (int(*)[5])malloc(r_025 * 5 * sizeof(int));

    for (int i = 0; i < r_025; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            p_025[i][j] = l;
            l++;
        }
    }

    for (int i = 0; i < r_025; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            printf("%d ", p_025[i][j]);
        }
        printf("\n");
    }
}
void rvcv()
{
    printf(".....THIS IS  2D DMA WITH var Row & Var Column.....\n");
    int r_025, c_025, l = 1;
    printf("how many rows you have ");
    scanf("%d", &r_025);
    printf("how many columns you have ");
    scanf("%d", &c_025);

    int **p_025;
    p_025 = (int **)malloc(r_025 * sizeof(int));
    for (int j = 0; j < r_025; j++)
    {
        p_025[j] = (int *)malloc((j + 1) * sizeof(int));
    }
    for (int i = 0; i < r_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {

            p_025[i][j] = l;
            l++;
        }
    }

    for (int i = 0; i < r_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {

            printf("%d ", p_025[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    rfcv();
    return 0;
}