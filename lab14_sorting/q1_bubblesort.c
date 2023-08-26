// q1 sort day month and year(structre type) using bubble sort
#include <stdio.h>

struct date_sort
{
    int day;
    int month;
    int year;
};

void sort_year(struct date_sort a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j].year > a[j + 1].year)
                
            {
                struct date_sort temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            else if (a[j].month > a[j + 1].month&& a[j].year == a[j + 1].year)
                
            {
                struct date_sort temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            else if (a[j].day > a[j + 1].day&& a[j].year == a[j + 1].year&&a[j].month == a[j + 1].month)
                
            {
                struct date_sort temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{      printf("enter 5 dates\n");
    struct date_sort a[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i].day);
        scanf("%d", &a[i].month);
        scanf("%d", &a[i].year);
    }

  /* 2 3 2003
    4 5 2008
    5 6 2001
    6 6 2001
    1 6 2001*/
    sort_year(a, 5);
 
 printf("  \n.......................................\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d %d \n", a[i].day, a[i].month, a[i].year);
    }

    return 0;
}