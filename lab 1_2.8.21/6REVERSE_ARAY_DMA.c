//WAP to reverse the contents of a dynamic array of ‘N’ elements.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n_025, *p_025;

    printf("how many elements are there");
    scanf("%d", &n_025);
    p_025 = (int *)malloc(n_025 * sizeof(int));
    for (int i = 0; i < n_025; i++)
    {
        printf("Enter the %d element ", i + 1);
        scanf(" %d", &*(p_025 + i));
    }

    for (int i = 0; i < n_025/2; i++)
    {    
       int temp=*(p_025+i);
       *(p_025+i)=*(p_025+(n_025-i-1));
       *(p_025+(n_025-i-1))=temp;
    }
    printf("the reverse array is ");
    for (int i = 0; i < n_025; i++)
    {
        printf("%d ", *(p_025+i) );
       
    }

    return 0;
}
