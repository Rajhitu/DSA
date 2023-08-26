//Q4•	Write a program in C to find the LCM ,HCF,GCD of two numbers using recursion
//by using menu driven switch case and functions.

#include <stdio.h>
/*void hcf(int a, int b)
{
    int hcf = 1, tempa = a, tempb = b;

    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            hcf = hcf * i;
            a = a / i;
            b = b / i;
            i = 1;
        }
    }
    printf("hcf of %d and %d is %d", tempa, tempb, hcf);
}*/
void hcf(int a, int b, int i)
{ //static int i=1;
    static int thcf = 1;
    if (a % i == 0 && b % i == 0)

    {
        thcf = thcf * i;
        hcf(a / i, b / i, 2);
    }

    else if (i <= a && i <= b)

        hcf(a, b, ++i);
    else
    {

        printf("\nhcf of 2 no. is %d", thcf);
        // return thcf;
    }
}
void lcm(int a, int b, int i)
{ //static int i=1;
    static int tlcm = 1;
    if (a % i == 0 && b % i == 0)

    {
        tlcm = tlcm * i;
        lcm(a / i, b / i, 2);
    }

    else if (i <= a && i <= b)

        lcm(a, b, ++i);
    else
    {

        printf("\n lcm of 2 no. is %d", tlcm*a*b);
    }
}

/*    void lcm(int a, int b)
    {
        int lcm = 1, tempa = a, tempb = b;

        for (int i = 1; i <= a && i <= b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                lcm = lcm * i;
                a = a / i;
                b = b / i;
                i = 1;
            }
        }
        lcm = lcm * a * b;
        printf("\nlcm of %d and %d is %d", tempa, tempb, lcm);
    }*/
int main()
{

    // hcf(12, 16);
    int a, b;
    printf("Enter 2 no.s you want to calculate hcf anf lcm");
    scanf("%d%d", &a, &b);
    lcm(a, b, 1);
    hcf(a, b, 1);
    return 0;
}