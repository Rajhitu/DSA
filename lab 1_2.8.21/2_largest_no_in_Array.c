//Find the largest element in an array using Dynamic Memory Allocation.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n_025, *p_025, max_025;

    printf("how many elements are there");
    scanf("%d", &n_025);
    p_025 = (int *)malloc(n_025 * sizeof(int));
    for (int i = 0; i < n_025; i++)
    {
        printf("Enter the %d element ", i + 1);
        scanf(" %d", &*(p_025 + i));
    }
    max_025 = *p_025;
    for (int i = 0; i < n_025; i++)
    {

        if (max_025 <= *(p_025 + i))
            max_025 = *(p_025 + i);
    }
    printf("the largest no. is %d", max_025);
    return 0;
}
