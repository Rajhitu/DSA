#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    /*  int testcase;
    cin >> testcase;
    int *a;
    a=new int[testcase];
    
    int p,n,z;
    p=z=n=0;

for (int i = 0; i < testcase; i++)

{
       cin>>a[i];
  if(a[i]>0)
  p++;
  else if(a[i]<0)
  n++;

  else
  z++;


    
}
cout<<p/(float)testcase<<"\n"<<n/(float)testcase<<"\n"<<z/(float)testcase<<"\n";
    delete []a;*/

    int x = 0, y = 0, a, b, c = 0;
    cin >> a >> b;
    while (x != a && y != b)
    {
        if (a >= x && b <= y)
        {
            x++;
            y--;
            c++;
            if (x == a && y == b)
            {
                cout << "yes";
                break;
            }
        }
        if (a >= x && b >= y)
        {
            x++;
            y++;
            c++;
            if (x == a && y == b)
            {
                cout << "yes";
                break;
            }
        }
        if (a <= x && b <= y)
        {
            x--;
            y--;
            c++;
            if (x == a && y == b)
            {
                cout << "yes";
                break;
            }
        }
        if (a <= x && b >= y)
        {
            x--;
            y++;
            c++;
            if (x == a && y == b)
            {
                cout << "yes";
                break;
            }
        }
        if (c > 100)
            break;
    }
    if (x == a && y == b)
        cout << "yes";
    else
        cout << "no";
}