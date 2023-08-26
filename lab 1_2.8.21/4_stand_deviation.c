//Q4.WAP to find the standard deviation of 20 numbers.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n_025, *p_025, sum_025 = 0, mean_025;
    double sqr_025 = 0.0, sd_025 = 0.0;
    printf("how many no. u have");
    scanf("%d", &n_025);

    p_025 = (int *)malloc(sizeof(int) * n_025);
    printf("enter the no.s ");
    for (int i = 0; i < n_025; i++)
    {
        scanf("%d", &p_025[i]);
        sum_025 = sum_025 + p_025[i];
    }
    mean_025 = sum_025 / n_025;

    for (int i = 0; i < n_025; i++)
    {
        double t = p_025[i] - mean_025;
        sqr_025 = pow(t, 2);
        sd_025 = sd_025 + sqr_025;
    }
    sd_025 = sd_025 / (n_025 - 1);

    printf("the standard deviation is %lf ", sqrt(sd_025));

    return 0;
}