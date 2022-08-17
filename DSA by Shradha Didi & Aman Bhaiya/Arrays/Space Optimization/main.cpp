// Space optimization using bit manipulations

// Difficulty Level : Medium
// Last Updated : 09 Aug, 2022
// There are many situations where we use integer values as index in array to see presence or absence, we can use bit manipulations to optimize space in such problems.
// Let us consider below problem as an example.
// Given two numbers say a and b, mark the multiples of 2 and 5 between a and b using less than O(|b – a|) space and output each of the multiples. 

// Note : We have to mark the multiples i.e save (key, value) pairs in memory such that each key either have value as 1 or 0 representing as multiple of 2 or 5 or not respectively. 

// Examples :  

// Input : 2 10
// Output : 2 4 5 6 8 10

// Input: 60 95
// Output: 60 62 64 65 66 68 70 72 74 75 76 78 
//         80 82 84 85 86 88 90 92 94 95



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 2, b = 10;
    int size = abs(b - a) + 1;
    int *array = new int[size];
    for (int i = 0; i <= b;i++)
    {
        if(i%2 == 0 || i%5 == 0)
        {
            array[i - a] = 1;
        }
    }

    for (int i = a; i <= b;i++)
    {
        if (array[i - a] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}




bool checkBit(int array[], int index)
{
    return array[index >> 5] & (1 << (index & 31));
}


void setBit(int array[], int index)
{
    array[index >> 5] |= (1 << (index & 31));
}


int main()
{
    int a = 2, b = 10;
    int size = abs(b - a) + 1;

    size = ceil((double)size / 32);

    int *array = new int[size];
    for (int i = a; i <= b;i++)
    {
        if(i%2==0 || i%5==0)
        {
            setBit(array, i - a);
        }
    }

    for (int i = a; i <= b;i++)
    {
        if(checkBit(array,i-a))
        {
            cout << i << " ";
        }
    }
    return 0;
}