
#include <iostream>
#include <cmath>
using namespace std;
void rec(int a, int b, int t, long long n)
{
    //cout<<a<<endl;
    if(t<n)
        rec(b, a+b, t+1, n);
}
int main()
{
    long long n= 10e16;
    rec(2,1,1,n);
    return 0;
}
