
 #include <iostream>
#include <math.h>
#include <stdlib.h>
 
using namespace std;
 
int main(int argc, char **argv)
{
    int p = 7, l = 3, g = 2, n = 4, x;
    int a[] = { 1, 2, 2, 1 };
    int bin[4];
    cout << "The Random numbers are: ";
    for (int i = 0; i < 10; i++)
    {
        x = rand() % 16;
        for (int j = 3; j >= 0; j--)
        {
            bin[j] = x % 2;
            x /= 2;
        }
        int mul = 1;
        for (int k = 0; k < 4; k++)
            mul *= pow(a[k], bin[k]);
        cout << pow(g, mul)<<" ";
    }
}
