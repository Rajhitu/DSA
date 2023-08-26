#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include <string.h>
//#include <boost/multiprecision/int.hpp>
//using namespace boost::multiprecision;

using namespace std;

int main()
{
    int cases;
    
    cin >> cases;
    /*  a = new char*[cases];

    for (int i = 0; i <cases; i++)
    {
        a[i] = new char[1000000];
    }*/

    while (cases > 0)
    {
        int a[4], b[1000];
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        for (int j = 0; j < a[0]; j++)
        {
            cin >> b[j];
        }
        int time1=0;
        for (int k = 0; k < a[1]; k++)
        {
            if (b[k] == 0)
                time1 = time1 + a[2];
            else
                time1 = time1 + a[3];
        }

        cout << time1 << "\n";
        cases--;
    }

    return 0;
}