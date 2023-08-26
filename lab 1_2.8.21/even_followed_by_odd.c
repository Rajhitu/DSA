#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, *p, ma ;

    printf("how many elements are there");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element ", i + 1);
        scanf(" %d", (p + i));
    }

    for (int i = 0; i < n; i++)
    {    if(p[i]%2==0)
         { a[j]=p[i];
          j++;
         }

         b[k]=p[i];
         k++;

       


    }
    printf("Even followed by odd is as follows ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p+i) );
       
    }

    return 0;
}
