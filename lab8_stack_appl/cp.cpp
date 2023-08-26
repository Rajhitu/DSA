#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
//#include <boost/multiprecision/int.hpp>
//using namespace boost::multiprecision;

using namespace std;

int main()
{
    int testcases;
    int **a;;
    cin >> testcases;
    a = new int *[testcases];

     for (int i = 0; i < testcases; i++)
    {
        a[i] = new int[4];
    }


     for (int i = 0; i < testcases; i++)
    {

        for (int j = 0 ; j <3; j++)
        {
            cin>>a[i][j];
        }
        
       

    }

    while (testcases > 0)
    {
       for (int i = 0; i < testcases; i++)
       {int sum=a[i][0];

       sum=sum+ a[i][2]*2;
       if(sum>=a[i][1])
       cout<<"YES\n";
       else
       cout<<"NO\n";
       testcases--;
       }
       

    
        
    }

    return 0;
}