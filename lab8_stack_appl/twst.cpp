#include <iostream>
#include <stdlib.h>

using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main()
{
    int cass;
    cin >> cass;

    for (int i = 0; i < cass; i++)
    {
        int no_of_horse;
        cin >> no_of_horse;
        cpp_int *skill;
        skill = new cpp_int[no_of_horse];

        for (int j = 0; j < no_of_horse; j++)
        {
            cin >> skill[j];
        }
        cpp_int min = 1000000000;

        for (int k = 0; k < no_of_horse; k++)
        {
            for (int m = (k + 1); m < no_of_horse; m++)
            {
                cpp_int temp = skill[k] - skill[m];
                if (temp < 0)
                {
                    temp = -temp ;
                }

                if (temp < min)
                {
                    min = temp;
                }
            }
        }
        cout << min << "\n";
    }
    delete []skill;
    return 0;
}