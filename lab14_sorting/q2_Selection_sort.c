/*q2WAP to sort an array of n dates in an ascending order using Bubble sort. Date structure is {day, month, year }
*/
#include <stdio.h>

 
int  main()
{
    int a[100];
   int num;
 
    printf("Enter the value of num \n");
    scanf("%d", &num);
    printf("Enter the elements \n");
    for (int i = 0; i < num; i++)
    {
        scanf(" %d",&a[i]);
    }

    

       for (int i = 0; i < num-1; i++)
    {
        for (int j = i; j<num-1; j++)
        {
            if (a[i]> a[j + 1])
                
            {
              int temp = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("after seelection sort ascending  array is \n");

    for (int i = 0; i < num; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}