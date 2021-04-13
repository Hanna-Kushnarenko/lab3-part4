

#include <iostream>
using namespace std;
#define MAX_SIZE 100
#include <cstdlib>
#include <time.h>

// Function declarations
int Findmaxnumber(int array[], int index, int len);
int Findminnumber(int array[], int index, int len);
 int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;
}

int main(void)
{

const unsigned int ARRSIZE = 1000000;
const int ABSLIMIT = 100000;

int array[ARRSIZE];
    
    srand(static_cast<unsigned int>(time(NULL)));

    // инициализация массива случайными значениями из диапазона -ABSLIMIT..ABSLIMIT
    for (unsigned int i = 0; i < ARRSIZE; i++) {
        array[i] = rrand(-ABSLIMIT, ABSLIMIT);
    }
    int Num, max, min;
    int i;
 
    max = Findmaxnumber(array, 0, Num);
    min = Findminnumber(array, 0, Num);
 
    cout<<"Minimum element in array: "<<min<<endl;
    cout<<"Maximum element in array: "<<max<<endl;
 
    return 0;
}
 
 
 //Recursive function to find maximum element in the given array.
int Findmaxnumber(int array[], int index, int len)
{
    int max;
    if(index >= len-2)
    {
        if(array[index] > array[index + 1])
            return array[index];
        else
            return array[index + 1];
    }
 
    max = Findmaxnumber(array, index + 1, len);
 
    if(array[index] > max)
        return array[index];
    else
        return max;
}
 
//Recursive function to find minimum element in the array
int Findminnumber(int array[], int index, int len)
{
    int min;
 
    if(index >= len-2)
    {
        if(array[index] < array[index + 1])
            return array[index];
        else
            return array[index + 1];
    }
 
    min = Findminnumber(array, index + 1, len);
 
    if(array[index] < min)
        return array[index];
    else
        return min;
}