
#include <iostream>
#include <cmath>
using namespace std;
void rec(long long a, int b, int t, int n)
{
    a=10e16;
    if(t<n)
        rec(b, a+b, t+1, n);
}
int main()
{
    int n;
    cin>>n;
    rec(2,1,1,n);
    return 0;
}
