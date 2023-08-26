#include <stdio.h>
#include <stdlib.h>
int main()
{

    printf("best of luck");

    int n = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
            n++;

    }

    printf("%d", n);

    return 0;
}