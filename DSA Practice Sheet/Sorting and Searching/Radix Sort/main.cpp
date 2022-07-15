#include<bits/stdc++.h>
using namespace std;



// counting sort of arr[] according to
// the digit represented by exp


void CountSort(int arr[], int n, int exp)
{
    int i;

    int output[n];

    int count[10] = {0};

    // storing count of occurrences in count[]


    for(i=0;i<n;i++)
    {
        count[(arr[i]/exp) % 10]++;
    }

    // changing count[i] so that count[i] now contains actual
    // position of this digit in output[]

    for(i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }

    // building the output array

    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    // copying the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit

    for(int i=0;i<n;i++)
    {
        arr[i] = output[i];
    }

}





void RadixSort(int arr[], int n)
{

    // finding the maximum number to know number of digits

    int mx = arr[0];
    for(int i=1;i<n;i++)
    
        if(arr[i] > mx)
            mx = arr[i];

    // doing counting sort for every digit, note that instead
    // of passing digit number, exp is passed, exp is 10^i
    // where i is current digit number

    for(int exp = 1;mx/exp > 0;exp*=10)
    CountSort(arr, n, exp);
    for(int i=0;i<n;i++)
    cout << arr[i] << " ";
    
}




int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    
    RadixSort(arr, n);

    return 0;
}

