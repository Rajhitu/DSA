/*Q3. WAP to swap all the elements in the 1st column with all the corresponding elements in the last column, and 2nd column with the second last column\
 and 3rd with 3rd last etc. of a 2-D dynamic array.  Display the matrix.
*/

#include <stdio.h>
#include <stdlib.h>
void swap(int *a[10], int r_025, int c_025)
{

    for (int i = 0; i < c_025/2; i++)
    {
        for (int j = 0; j < r_025; j++)
        {
            int temp = a[j][i];
            a[j][i] = a[j][c_025 - 1-i];
            a[j][c_025 - 1-i] = temp;
        }
        
    }
    for (int i = 0; i < r_025; i++)
    {
        for (int j = 0; j < c_025; j++)
        {

            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int r_025, c_025, l = 1;
    printf("how many rows you have ");
    scanf("%d", &r_025);
    printf("how many columns you have ");
    scanf("%d", &c_025);

    int **p_025;
    p_025 = (int **)malloc(r_025 * sizeof(int));
    for (int j = 0; j < r_025; j++)
    {
        p_025[j] = (int *)malloc(c_025 * sizeof(int));
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
    printf("\n");
swap(p_025,r_025,c_025);

return 0;
}
