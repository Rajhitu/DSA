#include <iostream>

using namespace std;
class Sample {

static int x; public:

Sample() { x++; } static int getX() {return x;}

}; int Sample::x;

int main()

{

cout<<Sample::getX() <<" ";

Sample t[5];

cout<<Sample::getX();

}