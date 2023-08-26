#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int testcases;
    int **a;
    cin >> testcases;
    a = new int *[testcases * 2];

    for (int i = 0; i < testcases * 2; i++)
    {
        a[i] = new int[3];
    }

    for (int i = 0; i < testcases * 2; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < testcases * 2; i = i + 2)
    {
        int tme = 240, tpp, points = 0;

        for (int j = 0; j < 3; j++)
        {    tpp=a[i][j]*20;
            //int ques = tme / a[i][j];
            if (tme >= tpp)
            {
                tme = tme - tpp;
                points = points + (a[i + 1][j] * 20);
            }
            else if (tme > 0)
            {
                int ques = tme / a[i][j];
                tme = 0;
                points = points + (a[i + 1][j] * ques);
            }
        }
        cout<<points<<"\n";
    }


return 0;
}