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
    char a[100000];
    cin >> cases;
    /*  a = new char*[cases];

    for (int i = 0; i <cases; i++)
    {
        a[i] = new char[1000000];
    }*/

    while (cases > 0)
    {    int c = 0;
        cin >> a;
        for (int i = 0; a[i] != '\0'; i++)
        {
            
            if (a[i] == '0')
            {
                c++;
                for (int j = i; a[j] != '\0'; j++)
                {
                    if (a[j] == '0')

                        a[j] = '1';
                    else
                        a[j] = '0';

                    
                }
                
            }
                
            
            
        }

        cases--;

            cout <<"\n"<< c<< "\n";
    }
    
    
return 0;
}