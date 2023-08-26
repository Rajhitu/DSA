//WAP to arrange the elements of a dynamic
//array such that even numbers are followed by odd numbers.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, *p;

    printf("how many elements are there");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element ", i + 1);
        scanf(" %d", &p[i]);
    }

 

    for (int i = 0, j = n - 1; i <= n / 2 && j > n / 2;)
    {
        if (p[i] % 2 == 0 && p[j] % 2 != 0)
        {
            i++;
            j--;
        }
        else if (p[i] % 2 != 0 && p[j] % 2 == 0)
        {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            i++;
            j--;
        }
        else if (p[i] % 2 == 0 && p[j] % 2 == 0)
        {
            int temp = p[i+1];
            p[i+1] = p[j];
            p[j] = temp;
            i++;
            
        }
        else if (p[i] % 2 != 0 && p[j] % 2 != 0)
        {
            int temp = p[i];
            p[i] = p[j-1];
            p[j] = temp;
            j--;
            
        }
    }
    printf("even followed by odd is ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}




   /* for (int i = 0; i < n / 2; i++)
    {
        if (p[i] % 2 == 0 && p[n - 1 - i] % 2 != 0)
        {
        }

        else if (p[i] % 2 != 0 && p[n - 1 - i] % 2 == 0)
        {
            int temp = *(p + i);
            *(p + i) = *(p + (n - i - 1));
            *(p + (n - i - 1)) = temp;
        }
        else if (p[i] % 2 == 0 && p[n - 1 - i] % 2 == 0)
        {
            int j = i + 1, c = 0;
            while (c ==0&&j<=n/2)
            {
                if (p[j] % 2 != 0)
                {
                    int temp = *(p + j);
                    *(p + j) = *(p + (n - i - 1));
                    *(p + (n - i - 1)) = temp;
                    c = 1;
                }
                j++;
            }
        }
        else if (p[i] % 2 != 0 && p[n - 1 - i] % 2 != 0)
        {
            int j = n - 2 - i, c = 0;
            while (c == 0&&j>=n/2)
            {
                if (p[j] % 2 == 0)
                {
                    int temp = *(p + j);
                    *(p + j) = *(p + i);
                    *(p + i) = temp;
                    c = 1;
                }
                j--;
            }
        }
    }*/