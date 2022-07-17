#include<bits/stdc++.h>
using namespace std;



vector<long long int> productArray(vector<long long int>& nums, int n)
{

    // Allocating the memory and Initialising product array with 1


    vector<long long int> vec(n, 1ll);

    // If all are 1

    if(n == 1)
    {

        // return the vec

        return vec;
    }

    // initializing temp with 1 for left product array value to get stored



    long long temp = 1ll;
    
    // looping from i to n

    for(int i=0;i<n;i++)
    {

        // storing the vec[i] values after multiplying temp


        vec[i] = vec[i] * temp;

        // now storing nums[i] multiplication with temp in temp only


        temp = temp * nums[i];
    }


    // initialising temp with 1 to store the product of values on right side of nums[i]


    temp = 1ll;

    // Looping from right side till 0


    for(int i=n-1;i>=0;i--)
    {
        
        // Multiplying vec[i] with temp and storing the vec[i]

        
        vec[i] = vec[i] * temp;

        // Multiplying vec[i] with temp and storing the vec[i]


        temp = temp * nums[i];
    }

    // returning the vector

    return vec;
}


// traversing the array and finding the product of all the elements in the array and storing the product in a variable
// then again traverse the array and finding the product of all the elements except that number by using the formula (product * pow(a[i], -1))
// arr[] = {10, 3, 5, 6, 2}
// product of all elements 1800 * 10^(-1)
// product of all elements 1800 * 3^(-1)
// product of all elements 1800 * 5^(-1)
// product of all elements 1800 * 6^(-1)
// product of all elements 1800 * 2^(-1)
// prod[] = {180, 600, 360, 300, 900}


void ProductArr(int arr[], int n)
{

    // initializing a variable to store the
    // total product of the array elements

    int prod = 1;

    for(int i=0;i<n;i++)
    {
        prod = prod * arr[i];
    }

    // x/y mathematically is same
    // as x*(y to power -1)

    for(int i=0;i<n;i++)
    {
        cout << (long long int) (prod * pow(arr[i], -1)) << ' ';
    }
}