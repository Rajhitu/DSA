// q3 WAP to sort an array of n integers in a descending order using insertion sort.
#include <stdio.h>

int main()
{
    int a[100];
    int num;

    printf("Enter the value of num \n");
    scanf("%d", &num);
    printf("Enter the elements \n");
    for (int i = 0; i < num; i++)
    {
        scanf(" %d", &a[i]);
    }

    for (int i = 0; i < num ; i++)
    {
        int back = a[i+1];
        int j = i+1;
        for (; j > -1; j--)
        {
            if (a[j] > back)
            {
                a[j+1] = a[j];
            }
        }
        a[j+1] = back;
    }
    printf("after insertion sort ascending  array is \n");

    for (int i = 0; i < num; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}