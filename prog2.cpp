
 #include <iostream>
#include <math.h>
#include <stdlib.h>
 #include <fstream>
using namespace std;
 
#define MAX_NUM 50
// array will be initialized to 0 being global
int primes[1000];
 
void gen_sieve_primes(void)
{
    for (int p = 2; p < MAX_NUM; p++) // for all elements in array
    {
        if (primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime
 
        // mark all multiples of prime selected above as non primes
        int c = 2;
        int mul = p * c;
        for (; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p * c;
        }
    }
}
 
void print_all_primes()
{
   std::ofstream out;          // поток для записи
    out.open("/file.txt"); // окрываем файл для записи
    if (out.is_open())
    {
       // out << "Hello World!" << std::endl;
    
   
   
    int c = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (primes[i] == 1)
        {
            c++;
 
            if (c < 4)
            {
                switch (c)
                {
                    case 1:
                        out << c << "st prime is: " << i << std::endl;
                        break;
                    case 2:
                         out << c << "st prime is: " << i << std::endl;
                        break;
                    case 3:
                         out << c << "st prime is: " << i << std::endl;
                        break;
 
                    default:
                        break;
                }
            }
 
            else
               out << c << "st prime is: " << i << std::endl;
        }
    }
}
  return 0;
}
 
int main()
{
    gen_sieve_primes();
    print_all_primes();
    return 0;
}
