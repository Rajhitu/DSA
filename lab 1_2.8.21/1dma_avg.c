/*WAP in C to dynamically allocate memory using malloc or calloc to store  ‘N’ numbers entered by a user 
and display all the numbers and the average of the numbers.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n_025, *p_025, sum_025 = 0; 
    float avg_025;

    printf("how many elements are there");
    scanf("%d", &n_025);
    p_025 = (int *)malloc(n_025 * sizeof(int));
    for (int i = 0; i < n_025; i++)
    {
        printf("Enter the %d element ", i + 1);
        scanf(" %d", &*(p_025 + i));

        sum_025 = sum_025 + *(p_025+i);
    }
    avg_025 = sum_025 / (float)n_025;
    printf("the elements are ");
    for (int i = 0; i < n_025; i++)
    {

        printf(" %d ", *(p_025 + i));
        sum_025 = sum_025 + *p_025;
    }
    printf("\nthe avg of the entered data is %f", avg_025);
    return 0;
}
