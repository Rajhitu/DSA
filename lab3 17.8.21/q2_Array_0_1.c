//	Q2•	You are given an array of 0s and 1s in random order.
// Segregate 0s on left side and 1s on right side of the array.
// Traverse array only once.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, n;
    printf("how many elements you have in the array ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Enter the elements ");

    for (int i = 0; i < n; i++)
    {

        scanf("%d",&p[i]);
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d ", p[i]);
    }
    printf("\n");

    for (int i = 0, j = n-1; i <= n / 2 && j >= n / 2;)
    {
        if (p[i] == 1 && p[j] == 0)
        {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            i++;
            j--;
        }
        else if (p[i] == 0 && p[j] == 0)
        {
            int temp = p[i + 1];
            p[i + 1] = p[j];
            p[j] = temp;
            i++;
        }
        else if (p[i] == 1 && p[j] == 1)
        {
            int temp = p[i];
            p[i] = p[j-1];
            p[j - 1] = temp;
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d ", *(p + i));
    }

return 0;
}
