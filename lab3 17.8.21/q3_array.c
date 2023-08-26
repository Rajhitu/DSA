//Q3•	Given an unsorted dynamic array arr and two numbers x and y, find the minimum distance between x and y 
//in arr. The array might also contain duplicates. You may assume that both x and y are different and present in arr.
//Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
//Output: Minimum distance between 3 and 6 is 4.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, n, x, y,uplimit,lowerlimit;
    printf("how many elements you have in the array ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Enter the elements ");

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d ", p[i]);
    }

    printf("\nenter 2 elements you need to find the distance ");
    scanf("%d %d", &x, &y);
    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        if (p[i] == x)
        {
            lowerlimit = i;
            break;
        }

    }
    for (int i = 0; i < n; i++)
    {

      if (p[i] == y)
        {
            uplimit = i;
            break;
        }
        
    }
    printf("difference b/w the 2 elemnts are %d ",uplimit-lowerlimit);

    return 0;
}
